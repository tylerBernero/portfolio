/********************************************************
 * Name: Anthony Bernero                                *
 * Date: May 2018                                       *
 * Project: Smallsh                                     *
 * *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

//Array of strings extra help: https://www.youtube.com/watch?reload=9&v=pB-nvbCg3yc
//Strtok extra help: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

//Global variables
//getline variables:
size_t bufferSize = 0;                          //Holds how large the allocated buffer is
char* userInput = NULL;                         //Holds string + \n + \0
//NOTE: bufferSize=0 and userInput=NULL makes getline() allocate a buffer with malloc()
int numCharsEntered = -5;						//trick by brewster to check if getline should be cleared
pid_t spawnPid = -5;
int childExitMethod = -5;
char cpyInput[2048];                            //char array to test user input against certain char
//char expandCpy[2048];                           //char array to store expanded string
char *expandCpy;
//memset(cpyInput, '\0', 2048);
int numWords = 0;                                   //Holds number of words the user input
int numChars = 0;                                   //Holds number of chars the user input
char* argArr[512];                                  //Array to hold the arguments to be passed into execvp()
char* redirArg[512];                                //array to hold arguments from redirection
char* token;                                        //token used for strok
//char* beforeStr;									//Stores temp string for contents before $$
//char* afterStr;									//Stores temp string of contents after $$
char beforeStr[512];                                //Stores temp string for contents before $$
char afterStr[512];                                 //Stores temp string of contents after $$
char testPid[8];                                    //Stores $$ to test for $$ in user input
int pidFound;                                       //boolean for it Pid is found : 0 - false, 1 - true
int pid;                                            //stores pid
int sizePidStr;                                     //stores number of bytes in string with pid
int pidFound2;                                      //a second variable to ensure I can modify $$ outsde of loop
int pidArr[256];									//array to store pid of children
int pidArrSize = 0;									//stores how many elements to loop through in the pidArr
int childPid;										//stores childpid returned from wait of background processes
//Global sig structs set to be empty
struct sigaction SIGINT_action_parent = { 0 }, SIGINT_action_child = { 0 }, SIGSTP_action_parent = { 0 }, SIGSTP_action_child = { 0 };
int	SIGTSTP_caught = 0;								//boolean to know if we need to ignore & or not

//Function prototypes
void startShell();
void getInput();
void verifyInput();
void callExit();
void callCD();
void callStatus();
void callLinuxCmd();
void callForkTest();
void setSigs();
void catchSIGSTP();

int main()
{
    //malloc space for argArr
    int i;
    for(i = 0; i < 512; i++)
    {
        argArr[i] = (char*) malloc(32);             //reserve space for 512 arguments of 32 chars
        redirArg[i] = (char*) malloc(32);           //same as above
    }

	//Initialize PID array to -1
	for (i = 0; i < 256; i++)
	{
		pidArr[i] = -1;
	}

	//Set signals
	setSigs();
    
    //Start shell which loops until user quits
    startShell();

    return 0;
}

//Starts the shell
void startShell()
{
    //Run shell until another program exits
    while(1 == 1)
    {
        //Testing out user input
        getInput();
        userInput[strcspn(userInput, "\r\n")] = 0;              //Strips out carriage returns and newlines in getline: https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input
        verifyInput();
        
        //Frees allocated memory to prevent memory leaks
        free(userInput);

		//Loop through array of child PIDs
		int i;
		for (i = 0; i < 256; i++)
		{
			//printf("pidArr[%d]: %d\n", i, pidArr[i]);

			//Only do stuff is the aray element has a pid stored in it
			if (pidArr[i] != -1)
			{
				//returns pid if terminated, 0 if not
				childPid = waitpid(pidArr[i], &childExitMethod, WNOHANG);

				//childPid will not be 0 if it has terminated
				if (childPid != 0)
				{
					printf("background pid %d is done: exit value %d\n", childPid, childExitMethod);
					pidArr[i] = -1;
				}
			}
		}
    }
}

//uses getline to get user input
void getInput()
{
    //Use getline to, well, get the line [input by user]
	while (1)
	{
		printf(": ");

		//Test new prompt based on brewster's suggestion to help debug
		//printf("%d: ", getpid());
		fflush(stdout);

		//reset lineEntered to NULL so that getline will work as expected
		userInput = NULL;

		bufferSize = 0;
		numCharsEntered = getline(&userInput, &bufferSize, stdin);

		//Clear stdin if getline was interrupted
		if (numCharsEntered == -1)
		{
			clearerr(stdin);
			free(userInput);
		}
		else
		{
			break;
		}
	}
}

//Checks what user typed into getline and calls corresponding functions
void verifyInput()
{
    pidFound = 0;               //Reset to false
    pidFound2 = 0;               //Reset to false
    
    //memset beforeStr and afterStr
    memset(beforeStr, '\0', 512);
    memset(afterStr, '\0', 512);
    memset(testPid, '\0', 8);
    
    //Copy userInput into cpyInput to test first char against #
    memset(cpyInput, '\0', 2048);
    //memset(expandCpy, '\0', 2048);
    strcpy(cpyInput, userInput);
    numWords = 0;                   //reset numWords
    numChars = 0;                   //reset numChars
    
    //Loop through userInput and get number of words entered - https://www.opentechguides.com/how-to/article/c/72/c-file-counts.html
	//But only if userInput is not en ampty line
	if (strcmp(userInput, "") != 0)
	{
		int i;
		for (i = 0; i < strlen(cpyInput); i++)
		{
			pidFound = 0;               //Reset to false

			//inc chars for everything that's not a space
			if (cpyInput[i] != ' ')
			{
				numChars++;
			}

			//inc word for everything that is a space
			if (cpyInput[i] == ' ')
			{
				numWords++;
			}

			//look for $$
			if (cpyInput[i] == '$')
			{
				//printf("Found one $!\n");

				//if next cahr is also $, we have a $$
				if (cpyInput[i + 1] == '$')
				{
					//printf("Found second $!\nGeting pid\n");
					pidFound = 1;
					pidFound2 = 1;
					pid = getpid();
					//printf("pid: %d\n", pid);
				}
			}

			//cpy everything before $$ into before string
			if (pidFound == 1)
			{
				int j;
				for (j = 0; j < i; j++)
				{
					//strcpy(beforeStr[j], cpyInput[j]);
					beforeStr[j] = cpyInput[j];
				}
			}

			//cpy everything after $$ into after string
			if (pidFound == 1)
			{
				int j;
				int k = 0;
				for (j = (i + 2); j < strlen(cpyInput); j++)
				{
					afterStr[k] = cpyInput[j];
					k++;
				}
			}
		}

		//asprintf help: https://stackoverflow.com/questions/12746885/why-use-asprintf
		//printf beforeStr to test functionality
		//printf("beforeStr: %s\n", beforeStr);
		//printf("pid: %d\n", pid);
		//printf("afterStr: %s\n", afterStr);
		asprintf(&expandCpy, "%s%d%s", beforeStr, pid, afterStr);

		//printf("expandCpy: %s\n", expandCpy);


		//ensure word is 1 if only one word is input i.e no spaces
		if (numChars > 0)
		{
			numWords++;
		}


		//Store arguments in argArr
		if (pidFound2 == 1)              //use expanded string if we eexpanded $$
		{
			token = strtok(expandCpy, " ");         //token string with space delimiter
		}
		else                            //if no $$ use original cpy
		{
			token = strtok(cpyInput, " ");
		}

		//memset argArr to clean it before new arguments
		for (i = 0; i < 512; i++)
		{
			memset(argArr, '\0', 32);
			memset(redirArg, '\0', 32);
		}



		//strtok: https://stackoverflow.com/questions/15472299/split-string-into-tokens-and-save-them-in-an-array
		i = 0;

		//store token in argArr array
		while (token != NULL)
		{
			argArr[i++] = token;
			token = strtok(NULL, " ");
		}

		argArr[i++] = NULL;
	}

    //Compare userInput to built in commands
    if(numWords > 512)
    {
        printf("Please, no more than 512 words.\n");
    }
    //else if(strcmp(userInput, "exit") == 0)
	else if (strcmp(argArr[0], "exit") == 0)
    {
        //printf("Calling callExit()\n");
        callExit();
    }
    //else if(strcmp(userInput, "cd") == 0)
    else if(cpyInput[0] == 'c' && cpyInput[1] == 'd')
    {
        callCD(); 
    }
    //else if(strcmp(userInput, "status") == 0)
	else if (strcmp(argArr[0], "status") == 0)
    {
        callStatus();
    }
    else if(strcmp(userInput, "") == 0)
    {
        //Do Nothing and let shell loop do its thing
    }
    else if(cpyInput[0] == '#')
    {
        //'Twas a comment line, therefore do nothing and let shell loop do its thing
    }
    else
    {
        callLinuxCmd();
    }
}


//Kills any other processes and then terminates
void callExit()
{
    //printf("Inside callExit()\n");
    
    //memset argArr to clean it before new arguments
    int i;
    for(i = 0; i < 512; i++)
    {
        memset(argArr, '\0', 32);
        memset(redirArg, '\0', 32);
    }

    //free argArr and redirArg
    for(i = 0; i < numWords; i++)
    {
        free(argArr[i]);
        free(redirArg[i]);
    }
    
    free(expandCpy);
    
    exit(0);
}


//changes the working directory to home or to one argument along the path
void callCD()
{
    //getcwd: https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtgtc.htm
    
    if((numWords == 1) || strcmp(argArr[1], "&") == 0)
    {
        chdir(getenv("HOME"));                      //Change directory to home directory
    }
    else
    {
        //Create strings to hold current and new directory name and home path
        char newDir[256];
        memset(newDir, '\0', 256);
        //printf("newDir: %s\n", newDir);
        
        char home[256];
        memset(home, '\0', 256);
        //char* home;
        
        //copy home path to home then newDir
        //strcpy(home, getenv("HOME"));
        
        getcwd(home, sizeof(home));                //set home to current directory
        //printf("home: %s\n", home);
        
        strcpy(newDir, home);
        //printf("newDir: %s\n", newDir);
        
        
        
        //add / and rest of arguments to newDir then change directory
        strcat(newDir, "/");
        //printf("newDir: %s\n", newDir);
        strcat(newDir, argArr[1]);
        //printf("newDir: %s\n", newDir);
        //fflush(stdout);
        chdir(newDir);
    }
}


//Prints either exit status OR terminating signal of last foreground process
void callStatus()
{
    //TODO - NOTHING - COMPLETE - I THINK?
    //printf("Inside callStatus()\n");
    
    //prints exit value
    if(WIFEXITED(childExitMethod))  //None zero value is true
    {
        //printf("The process exited normally\n");
        int exitStatus  = WEXITSTATUS(childExitMethod);
        printf("exit value %d\n", exitStatus);
    }
    else if(WIFSIGNALED(childExitMethod) != 0)        //Otherwise exited by a signal
    {
        //printf("Process terminated by a signal\n");
        int termSignal = WTERMSIG(childExitMethod);
        printf("exit value %d\n", termSignal);
    }
    fflush(stdout);
}


//Creates a fork and calls program based on userInput
void callLinuxCmd()
{
    //Create fork
    spawnPid = fork();
    
	//Redirection of dev/null: https://stackoverflow.com/questions/14846768/in-c-how-do-i-redirect-stdout-fileno-to-dev-null-using-dup2-and-then-redirect
    //Set other variables for redirection and looping
    int i;
    int sourceFD;
    int targetFD;
	int devNullIn;
	int devNullOut;
    int result;

    //Set boolean for redirection: 0 = false, 1 = true
    int redirect = 0;
    int redirectLocation = 512;
    
    //switch statement to know what to do with input
    switch(spawnPid)
    {
        case -1:        //Error
            perror("Hull Breaks!\n");
            exit(1);
            break;
        case 0:         //Child

			//do child sigtstp sigaction since all children ignore it
			sigaction(SIGTSTP, &SIGSTP_action_child, NULL);

            //Loop through all arguments of argArr[]
            for(i = 0; i < numWords; i++)
            {
                //printf("argArr[%d]: %s\n", i, argArr[i]);
                
                //Redirect if argArr contains < or >
                if(strcmp(argArr[i], ">") == 0)
                {
                    //printf("redirecting stdout\n");
                    
                    //Redirect stdout to file name
                    targetFD = open(argArr[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);   //Open/create file targeted to by next argument
                    if(targetFD == -1)
                    {
                        perror("target open()");
                        exit(1);
                    }
                    //printf("targetFD: %d\n", targetFD);
                    
                    //Set close on exec
                    fcntl(targetFD, F_SETFD, FD_CLOEXEC);
                    
                    result = dup2(targetFD, 1);     //Set result equal to return value of dup2
                    if(result == -1)
                    {
                        perror("target dup2()");
                        exit(2);
                    }
                    //printf("result: %d\n", result);
                    
                    //Set redirect to 1 so execvp will call correct function
                    redirect = 1;
                    
                    //Set redirectLocation to first < or >
                    if(redirectLocation > i)
                    {
                        redirectLocation = i;
                    }
                    
                }
                
                if(strcmp(argArr[i], "<") == 0)
                {
                    //printf("redirecting stdin\n");
                    
                    //redirect stdin to file name
                    sourceFD = open(argArr[i + 1], O_RDONLY);
                    if(sourceFD == -1)
                    {
                        perror("source open()");
                        exit(1);
                    }
                    
                    //Set close on exec
                    fcntl(sourceFD, F_SETFD, FD_CLOEXEC);
                    
                    result = dup2(sourceFD, 0);
                    if(result == -1)
                    {
                        perror("source dup2()");
                        exit(2);
                    }
                    
                    //Set redirect to 1 so execvp will call correct function
                    redirect = 1;
                    
                    if(redirectLocation > i)
                    {
                        redirectLocation = i;
                    }
                }
                
                
            }
            
            //Call execvp using argArr tokenized from userInput
            if(redirect == 1)               //If redirect == 1, then we need to modify exec() to work with fewer arguments
            {
                //printf("Copying argArr into redirArg\n");
                //copy arguments from argArr into redirArg until < or > is encountered
                for(i = 0; i < redirectLocation; i++)
                {
                    //strcpy(redirArg[i], argArr[i]);
                    redirArg[i] = argArr[i];
                    //printf("redirArg[%d]: %s\n", redirectLocation, redirArg[i]);
                }
                
                //add NULL to end of redirArg array after checking if last argument is &
				if (strcmp(redirArg[i - 1], "&") == 0)		//If last argument is & change to NULL
				{
					redirArg[i - 1] = NULL;
				}
				else
				{
					redirArg[i] = NULL;						//Otherwise, add NULL to the end
				}
                
				//FOREGROUND
				//This sets foreground child to default to termination if sigint is sent
				sigaction(SIGINT, &SIGINT_action_child, NULL);

                //printf("Finished copying argArr to redirArg\n");
                execvp(redirArg[0], redirArg);
                perror("Child: exec failure!\n");
                exit(2);
                break;
            }
            else
            {
				//BACKGROUND
				//Change & to NULL if it is last argument and call execvp
				if (strcmp(argArr[numWords - 1], "&") == 0)
				{
					//Change & to NULL if it is last argument
					argArr[numWords - 1] = NULL;

					//If redirect == 1, proceed as planned - otherwise redirect to dev/null
					if (redirect == 1)
					{
						execvp(argArr[0], argArr);
						perror("Child: exec failure!\n");
						exit(2);
						break;
					}
					else
					{
						//Only redirect stdout/stdin if SIGSTP_caught is 00
						if (SIGTSTP_caught == 0)
						{
							devNullOut = open("/dev/null", O_WRONLY | O_CREAT | O_TRUNC, 0644);   //Open/create file targeted to by next argument
							if (devNullOut == -1)
							{
								perror("surce open()");
								exit(1);
							}

							result = dup2(devNullOut, 1);
							if (result == -1)
							{
								perror("source dup2()");
								exit(2);
							}

							//Set close on exec
							fcntl(devNullOut, F_SETFD, FD_CLOEXEC);

							devNullIn = open("/dev/null", O_RDONLY);
							if (devNullIn == -1)
							{
								perror("source open()");
								exit(1);
							}

							result = dup2(devNullIn, 0);
							if (result == -1)
							{
								perror("source dup2()");
								exit(2);
							}

							//Set close on exec
							fcntl(devNullIn, F_SETFD, FD_CLOEXEC);
						}

						execvp(argArr[0], argArr);
						perror("Child: exec failure!\n");
						exit(2);
						break;
					}
				}
				//FOREGROUND
				//Otherwise set new sigint flag so child process can be terminated
				else
				{
					//This sets foreground child to default to termination if sigint is sent
					sigaction(SIGINT, &SIGINT_action_child, NULL);
					execvp(argArr[0], argArr);
					perror("Child: exec failure!\n");
					exit(2);
					break;
				}
            }
        default:        //Parent

			//If last argument is & do background
			if ((strcmp(argArr[numWords - 1], "&") == 0) && (SIGTSTP_caught == 0))
			{
				//Do background stuff

				//Store childPid in pidArr in order to loop through later and check for terminated processes
				int i = pidArrSize;
				pidArr[i] = spawnPid;
				
				waitpid(spawnPid, &childExitMethod, WNOHANG);
				printf("background pid is %d\n", spawnPid);

				pidArrSize++;
			}
			else
			{
				//Do foreground stuff
				waitpid(spawnPid, &childExitMethod, 0);

				//Print number of signal used if child was killed by signal
				if (WIFSIGNALED(childExitMethod) != 0)        //exited by a signal
				{
					//printf("Process terminated by a signal\n");
					int termSignal = WTERMSIG(childExitMethod);
					printf("terminated by signal %d\n", termSignal);
				}
			}
    }

	fflush(stdout);
}


//Creates a fork and calls program based on userInput
void callForkTest()
{
    //Create fork
    spawnPid = fork();
    
    //switch statement to know what to do with input
    switch(spawnPid)
    {
        case -1:        //Error
            perror("Hull Breaks!\n");
            exit(1);
            break;
        case 0:         //Child
            printf("Child speaking. How do you do?\n");
            fflush(stdout);
            exit(0);
            break;
        default:        //Parent
            printf("Parent speaking. Do doo dooo\n");
            //fflush(stdout);
    }
    
    waitpid(spawnPid, &childExitMethod, 0);
    printf("Parent again.  Child has since terminated.\n");
    fflush(stdout);
}


//Set signals
void setSigs()
{
	//Set SIGINT_action_parent struct up and call sigaction to assign it all
	SIGINT_action_parent.sa_handler = SIG_IGN;				//ignore sigint
	sigfillset(&SIGINT_action_parent.sa_mask);				//don't let any other sigs interrupt
	SIGINT_action_parent.sa_flags = 0;						//don't set any flags

	sigaction(SIGINT, &SIGINT_action_parent, NULL);

	//Set SIGINT_action_child struct but only call sigaction() when child will exec in foreground
	SIGINT_action_child.sa_handler = SIG_DFL;				//ignore sigint
	sigfillset(&SIGINT_action_child.sa_mask);				//don't let any other sigs interrupt
	SIGINT_action_child.sa_flags = 0;						//don't set any flags

	//Set SIGSTP_action_parent and call sigaction to assign it
	SIGSTP_action_parent.sa_handler = catchSIGSTP;
	sigfillset(&SIGSTP_action_parent.sa_mask);
	SIGSTP_action_parent.sa_flags = SA_RESTART;

	sigaction(SIGTSTP, &SIGSTP_action_parent, NULL);

	//Set SIGSTP_action_child and call sigaction when child is made
	SIGSTP_action_child.sa_handler = SIG_IGN;
	sigfillset(&SIGSTP_action_child.sa_mask);
	SIGSTP_action_child.sa_flags = 0;
}

//SIGSTP Handler
void catchSIGSTP(int signo)
{
	//If SIGSTP_caught is false, enter foreground mode and change boolean to true
	if (SIGTSTP_caught == 0)
	{
		char* message = "\nEntering foreground-only mode (& is now ignored)\n:";
		write(STDOUT_FILENO, message, 51);
		SIGTSTP_caught = 1;	
	}
	else
	{		
		char* message = "\nExiting foreground-only mode\n:";
		write(STDOUT_FILENO, message, 31);
		SIGTSTP_caught = 0;
	}

	fflush(stdout);
}

/***************************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Menu class
****************************************************************/
#include "Menu.hpp"
#include "InputValid.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*****************************************************
** Description: Default constructor for Menu class
******************************************************/
Menu::Menu()
{
	string p1 = "Team A";
	int p1Score = 0;
	string p2 = "Team B";
	int p2Score = 0;
}

/*****************************************************
** Description: Displays the menu, allows user input 
** to make a choice, uses that choice to call the 
** correct case, then iterates back to displaying the 
** menu so the user can perform any of the recursive 
** functions again if they wish
******************************************************/
void Menu::callMenu()
{
	do
	{
		//Display Menu and have user enter choice
		cout << "Welcome to \"Fantasy Arena Combat Simulator\"" << endl;
		cout << "1. *Choose Your Lineup of Worthy Champions!" << endl;
		cout << "2. Battle!" << endl;
		cout << "3. Check stats of Champions!" << endl;
		cout << "4. Memory of Those Who Were Lost" << endl;
		cout << "5. Quit Combat Simulation!" << endl;
		cout << "*Must choose new Champions after each battle." << endl;

		menuChoice = inputValid();

		if (menuChoice < 1 || menuChoice > 5)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
			menuChoice = inputValid();
		}

		//Takes choice to skip to the correct case
			switch (menuChoice)
			{
			//Choose champions NEED TO UPDATE
			case 1:

				//Clear queue
				while (!p1Line.isEmpty())
				{
					Creature *c;
					p1Line.dequeue();
				}

				while (!p2Line.isEmpty())
				{
					Creature *c;
					p2Line.dequeue();
				}

				//Add 2 lines after menu choice was made for improved readability
				cout << endl << endl;

				//Instructions on how to play the game
				cout << endl << "Before you begin picking your lineup of champions, please enter the number of champions you would like to use (1-20)." << endl;
				cout << "Please note, this number applies to both teams." << endl << "Number of champions: ";
				numOfChamps = inputValid();
				if (numOfChamps < 1 || numOfChamps > 20)
				{
					cout << endl << "That is not a valid input.  Please enter a number between 1 and 20." << endl << endl;
					numOfChamps = inputValid();
				}

				cout << "Team A may now enter the letter choice of the following champions. Please enter one at a time followed by \"Enter\"." << endl;
				cout << "Choose wisely. . . Their fates lie in your hands. . ." << endl << endl;

				for (int i = 0; i < numOfChamps; i++)
				{

					//Display an option for each class the user can choose from
					cout << "(a) Vampire" << endl;
					cout << "(b) Barbarian" << endl;
					cout << "(c) Blue Men" << endl;
					cout << "(d) Medussssssa" << endl;
					cout << "(e) Harry Potter" << endl << endl;

					cout << "Choose a letter to send a lucky champion to Team A: ";
					cin >> creatureChoice;

					//Validate the user input a letter between a and e
					while ((creatureChoice != 'a' && creatureChoice != 'A') && (creatureChoice != 'b' && creatureChoice != 'B') && (creatureChoice != 'c' && creatureChoice != 'C') && (creatureChoice != 'd' && creatureChoice != 'D') && (creatureChoice != 'e' && creatureChoice != 'E'))
					{
						cout << "That is not a valid input.  Please enter a leter between a and e." << endl;
						cin >> creatureChoice;
					}


					//Use a switch statement to assign the correct creature subclass to c1
					switch (creatureChoice)
					{
					case 'A':
					case 'a':
						c1 = new Vampire();
						p1Line.enqueue(c1);
						break;

					case 'B':
					case 'b':
						c1 = new Barbarian();
						p1Line.enqueue(c1);
						break;

					case 'C':
					case 'c':
						c1 = new BlueMen();
						p1Line.enqueue(c1);
						break;

					case 'D':
					case 'd':
						c1 = new Medusa();
						p1Line.enqueue(c1);
						break;

					case 'E':
					case 'e':
						c1 = new HarryPotter();
						p1Line.enqueue(c1);
						break;
					}

					cout << "Choose a name for your " << c1->getName() << ": ";
					cin.ignore();
					getline(cin, name);
					c1->setUserName(name);
					cout << "Champion " << i + 1 << ": " << c1->getUserName() << endl << endl;
				}



				//Print Lineup
				cout << "Team A's lineup is: " << endl;
				p1Line.displayLineup();
				nodePtr1 = p1Line.getFront();

				cout << endl << endl;

				cout << "Team B may now enter the letter choice of the following champions. Please enter one at a time followed by \"Enter\"." << endl;
				cout << "Choose wisely. . . Their fates lie in your hands. . ." << endl << endl;

				for (int i = 0; i < numOfChamps; i++)
				{

					//Display an option for each class the user can choose from
					cout << "(a) Vampire" << endl;
					cout << "(b) Barbarian" << endl;
					cout << "(c) Blue Men" << endl;
					cout << "(d) Medussssssa" << endl;
					cout << "(e) Harry Potter" << endl << endl;

					cout << "Choose a letter to send a lucky champion to Team B: ";
					cin >> creatureChoice;

					//Validate the user input a letter between a and e
					while ((creatureChoice != 'a' && creatureChoice != 'A') && (creatureChoice != 'b' && creatureChoice != 'B') && (creatureChoice != 'c' && creatureChoice != 'C') && (creatureChoice != 'd' && creatureChoice != 'D') && (creatureChoice != 'e' && creatureChoice != 'E'))
					{
						cout << "That is not a valid input.  Please enter a leter between a and e." << endl;
						cin >> creatureChoice;
					}


					//Use a switch statement to assign the correct creature subclass to c1
					switch (creatureChoice)
					{
					case 'A':
					case 'a':
						c2 = new Vampire();
						p2Line.enqueue(c2);
						break;

					case 'B':
					case 'b':
						c2 = new Barbarian();
						p2Line.enqueue(c2);
						break;

					case 'C':
					case 'c':
						c2 = new BlueMen();
						p2Line.enqueue(c2);
						break;

					case 'D':
					case 'd':
						c2 = new Medusa();
						p2Line.enqueue(c2);
						break;

					case 'E':
					case 'e':
						c2 = new HarryPotter();
						p2Line.enqueue(c2);
						break;
					}

					cout << "Choose a name for your " << c2->getName() << ": ";
					cin.ignore();
					getline(cin, name);
					c2->setUserName(name);
					cout << "Champion " << i + 1 << ": " << c2->getUserName() << endl << endl;
				}

				//Print Lineup
				cout << "Team B's lineup is: " << endl;
				p2Line.displayLineup();
				nodePtr2 = p2Line.getFront();

				cout << endl << endl;
				break;

			//BATTLE!
			case 2:
				//Add 2 lines after menu choice was made for improved readability
				cout << endl << endl;

				//Make sure the user has chosen 2 champions. Otherwise, do battle! 
				if ((p1Line.isEmpty()) || (p2Line.isEmpty()))
				{
					cout << "Must choose worthy champions before a battle may be fought. Returning to menu." << endl << endl;
					break;
				}
				else
				{
					while ((p1Line.getFront() != nullptr) && (p2Line.getFront() != nullptr))
					{
						//Set cPtr1 and cPtr2 to the front champs
						cPtr1 = nodePtr1->creature;
						c1 = cPtr1;
						cout << "Sending " << c1->getUserName() << " to battle!" << endl;
						cPtr2 = nodePtr2->creature;
						c2 = cPtr2;
						cout << "Sending " << c2->getUserName() << " to battle!" << endl;
						
						//Call battle
						battle(c1, c2);

						//Reset round number
						round = 1;
					}
				}

				//Display the winning team after battles are over
				displayWinner();

				//Reset round to 1 and scores to 0 so user can battle again after choosing new combatants
				round = 1;
				p1Score = 0;
				p2Score = 0;
				break;

			//View Stats
			case 3:
				//Add a couple lines to improve readability
				cout << endl << endl;

				//Vampire stats
				cout << "Vampire - Suave, debonair, but vicious. 50 % chance to Charm opponent" << endl;
				cout << "Strength: 18" << endl;
				cout << "Attack: 1d12" << endl;
				cout << "Defense 1d6" << endl;
				cout << "Armor: 1" << endl;
				cout << "Ability: Charm - 50% chance the opponent's attack fails" << endl << endl;

				//Barbarian stats
				cout << "Barbarian - Big sword. Bigger Muscles" << endl;
				cout << "Strength: 12" << endl;
				cout << "Attack: 2d6" << endl;
				cout << "Defense 2d6" << endl;
				cout << "Armor: 0" << endl;
				cout << "Ability: None" << endl << endl;

				//Blue Men stats
				cout << "Blue Men - Short, swift, and cunning. Always attacks in a group" << endl;
				cout << "Strength: 12" << endl;
				cout << "Attack: 2d10" << endl;
				cout << "Defense 3d6" << endl;
				cout << "Armor: 3" << endl;
				cout << "Ability: Mob - lose 1d6 defense for every 4 health lost" << endl << endl;

				//Medussssssa ssstatssssssss
				cout << "Medussssssa - Scrawny lady with snakes for hair" << endl;
				cout << "Strength: 8" << endl;
				cout << "Attack: 2d6" << endl;
				cout << "Defense 1d6" << endl;
				cout << "Armor: 3" << endl;
				cout << "Ability: Glare - if Medussssssa crits (12 attack), petrifies opponent and automatically wins the match" << endl << endl;

				//Harry Potter stats
				cout << "Harry Potter - The Boy Who Lived" << endl;
				cout << "Strength: 10" << endl;
				cout << "Attack: 2d6" << endl;
				cout << "Defense 2d6" << endl;
				cout << "Armor: 0" << endl;
				cout << "Ability: Hogwarts - Once per battle, Harry returns to life with 20 strength"
					<< " if strength is reduced to zero (or petrified be Medusa)." << endl << endl;
				break;

			//Display loser pile
			case 4:
				loserPile.displayLosers();

				//Delete loser pile to make room for new one if user does another tournament
				loserPile.~Loser();

				cout << endl << endl;
				break;
		}
	} while (menuChoice != 5);
}

/*****************************************************
** Description: Takes two creature objects and has
** them do battle.  Randomly chooses which creature
** goes first, then has them alternate turns until
** one runs out of strength
******************************************************/
void Menu::battle(Creature *c1, Creature *c2)
{
	//Generate random number to see which champion goes first
	rando = rand() % 2 + 1;

	//If random number is 1, p1 attacks first
	if (rando == 1)
	{
		//Repeat alternate attacks until one champion's health hits 0
		while ((c1->getStr() > 0) && (c2->getStr() > 0))
		{
			//Add a line after menu choice was made for improved readability
			cout << endl;

			//Creature 1 attacks and Creature 2 defends
			if (c1->getStr() > 0)
			{
				//Add a line after menu choice was made for improved readability
				cout << endl;

				//Print round number and increment round
				cout << "Round " << round << ":" << endl;
				round++;

				cout <<"Team A (" << c1->getUserName() << ") attacks!" << endl;
				c1Att = c1->attack();
				if (c1Att == 100)
				{
					c2->setStr(0);
					cout << "Team B (" << c2->getUserName() << ") is petrified!" << endl;
					if (c2->getName() == "Harry Potter")
					{
						if (c2->getDeath() == 0)
						{
							cout << "But wait. . ." << endl;
							cout << "Praise be to Hogwarts! Harry Potter has been revived, stronger than ever before!" << endl;
							cout << "Harry Potter now has 20 strength!" << endl;
							c2->setStr(20);
							c2->setMaxStr(20);
							c2->setDeath(1);
						}
					}
				}
				else
				{
					c2->defend(c1Att);
					cout << "Team B (" << c2->getUserName() << ") has " << c2->getStr() << " strength" << endl;
				}

				if (c1->getStr() < 1)
				{
					cout << "Team A (" << c1->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c1);
					p1Line.dequeue();
					cout << c1->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr1 = p1Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team B (" << c2->getUserName() << ") is victorious!" << endl << endl;
					c2->recover();
					p2Score += 1;
					p2Line.movePtr();
					nodePtr2 = p2Line.getFront();

					//Display Score
					displayScore();
					
				}
				else if (c2->getStr() < 1)
				{
					cout << "Team B (" << c2->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c2);
					p2Line.dequeue();
					cout << c2->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr2 = p2Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team A (" << c1->getUserName() << ") is victorious!" << endl << endl;
					c1->recover();
					p1Score += 1;
					p1Line.movePtr();
					nodePtr1 = p1Line.getFront();

					//Display Score
					displayScore();
				}
			}

			//Creature 2 attacks and Creature 1 defends
			if ((c2->getStr() > 0))
			{
				//Add a line after menu choice was made for improved readability
				cout << endl;

				//Print round number and increment round
				cout << "Round " << round << ":" << endl;
				round++;

				cout << "Team B (" << c2->getUserName() << ") attacks!" << endl;
				c2Att = c2->attack();
				if (c2Att == 100)
				{
					c1->setStr(0);
					cout << "Team A (" << c1->getUserName() << ") is petrified!" << endl;
					if (c1->getName() == "Harry Potter")
					{
						if (c1->getDeath() == 0)
						{
							cout << "But wait. . ." << endl;
							cout << "Praise be to Hogwarts! Harry Potter has been revived, stronger than ever before!" << endl;
							cout << "Harry Potter now has 20 strength!" << endl;
							c1->setStr(20);
							c1->setMaxStr(20);
							c1->setDeath(1);
						}
					}
				}
				else
				{
					c1->defend(c2Att);
					cout << "Team A (" << c1->getUserName() << ") has " << c1->getStr() << " strength" << endl;
				}

				if (c1->getStr() < 1)
				{
					cout << "Team A (" << c1->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c1);
					p1Line.dequeue();
					cout << c1->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr1 = p1Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team B (" << c2->getUserName() << ") is victorious!" << endl << endl;
					c2->recover();
					p2Score += 1;
					p2Line.movePtr();
					nodePtr2 = p2Line.getFront();

					//Display Score
					displayScore();
				}
				else if (c2->getStr() < 1)
				{
					cout << "Team B (" << c2->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c2);
					p2Line.dequeue();
					cout << c2->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr2 = p2Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team A (" << c1->getUserName() << ") is victorious!" << endl << endl;
					c1->recover();
					p1Line.movePtr();
					nodePtr1 = p1Line.getFront();

					//Display Score
					displayScore();
				}
			}
		}
	}

	//If random number is 2, c2 attacks first
	if (rando == 2)
	{
		//Repeat alternate attacks until one creature's health hits 0
		while ((c1->getStr() > 0) && (c2->getStr() > 0))
		{
			if ((c2->getStr() > 0))
			{
				//Add a line after menu choice was made for improved readability
				cout << endl;

				//Print round number and increment round
				cout << "Round " << round << ":" << endl;
				round++;

				cout << "Team B (" << c2->getUserName() << ") attacks!" << endl;
				c2Att = c2->attack();
				if (c2Att == 100)
				{
					c1->setStr(0);
					cout << "Team A (" << c1->getUserName() << ") is petrified!" << endl;
					if (c1->getName() == "Harry Potter")
					{
						if (c1->getDeath() == 0)
						{
							cout << "But wait. . ." << endl;
							cout << "Praise be to Hogwarts! Harry Potter has been revived, stronger than ever before!" << endl;
							cout << "Harry Potter now has 20 strength!" << endl;
							c1->setStr(20);
							c1->setMaxStr(20);
							c1->setDeath(1);
						}
					}
				}
				else
				{
					c1->defend(c2Att);
					cout << "Team A (" << c1->getUserName() << ") has " << c1->getStr() << " strength" << endl;
				}

				if (c1->getStr() < 1)
				{
					cout << "Team A (" << c1->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c1);
					p1Line.dequeue();
					cout << c1->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr1 = p1Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team B (" << c2->getUserName() << ") is victorious!" << endl << endl;
					c2->recover();
					p2Score += 1;
					p2Line.movePtr();
					nodePtr2 = p2Line.getFront();

					//Display Score
					displayScore();
				}
				else if (c2->getStr() < 1)
				{
					cout << "Team B (" << c2->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c2);
					p2Line.dequeue();
					cout << c2->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr2 = p2Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team A (" << c1->getUserName() << ") is victorious!" << endl << endl;
					c1->recover();
					p1Score += 1;
					p1Line.movePtr();
					nodePtr1 = p1Line.getFront();

					//Display Score
					displayScore();
				}
			}

			if (c1->getStr() > 0)
			{
				//Add a line after menu choice was made for improved readability
				cout << endl;

				//Print round number and increment round
				cout << "Round " << round << ":" << endl;
				round++;

				cout << "Team A (" << c1->getUserName() << ") attacks!" << endl;
				c1Att = c1->attack();
				if (c1Att == 100)
				{
					c2->setStr(0);
					cout << "Team B (" << c2->getUserName() << ") is petrified!" << endl;
					if (c2->getName() == "Harry Potter")
					{
						if (c2->getDeath() == 0)
						{
							cout << "But wait. . ." << endl;
							cout << "Praise be to Hogwarts! Harry Potter has been revived, stronger than ever before!" << endl;
							cout << "Harry Potter now has 20 strength!" << endl;
							c2->setStr(20);
							c2->setMaxStr(20);
							c2->setDeath(1);
						}
					}
				}
				else
				{
					c2->defend(c1Att);
					cout << "Team B (" << c2->getUserName() << ") has " << c2->getStr() << " strength" << endl;
				}

				if (c1->getStr() < 1)
				{
					cout << "Team A (" << c1->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c1);
					p1Line.dequeue();
					cout << c1->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr1 = p1Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team B (" << c2->getUserName() << ") is victorious!" << endl << endl;
					c2->recover();
					p2Score += 1;
					p2Line.movePtr();
					nodePtr2 = p2Line.getFront();

					//Display Score
					displayScore();
				}
				else if (c2->getStr() < 1)
				{
					cout << "Team B (" << c2->getUserName() << ") is dead!" << endl;

					//Add loser to loserpile and remove said loser from lineup
					loserPile.push(c2);
					p2Line.dequeue();
					cout << c2->getUserName() << " was sent to the Loser Pile!" << endl;
					nodePtr2 = p2Line.getFront();

					//Recover winner's strength and move the winning team's nodePtr to the next node
					cout << "Team A (" << c1->getUserName() << ") is victorious!" << endl << endl;
					c1->recover();
					p1Score += 1;
					p1Line.movePtr();
					nodePtr1 = p1Line.getFront();

					//Display Score
					displayScore();
				}
			}
		}
	}
}

/*****************************************************
** Description: Displays the score for each team
******************************************************/
void Menu::displayScore()
{
	cout << "Team A: " << p1Score << "     " << "Team B: " << p2Score << endl << endl;
}

/*****************************************************
** Description: Displays the winner of the tournament
******************************************************/
void Menu::displayWinner()
{
	if (p1Score > p2Score)
	{
		cout << "Team A wins!" << endl << endl;
	}
	else
	{
		cout << "Team B wins!" << endl << endl;
	}
}
#include "SkulltulaRoom.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for SkulltulaRoom Class
****************************************************************/

SkulltulaRoom::SkulltulaRoom()
{
	name = "SkulltulaRoom";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	specialItem = "Skulltula";
	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void SkulltulaRoom::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool SkulltulaRoom::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string SkulltulaRoom::getSpecialItem()
{
	return specialItem;
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void SkulltulaRoom::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void SkulltulaRoom::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void SkulltulaRoom::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void SkulltulaRoom::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int SkulltulaRoom::dispayMenu()
{
	if (getSpecialAction() == false)
	{
		cout << endl << endl;

		cout << "It's dark. You hear a slight scratching sound and realize you're not alone." << endl;
		cout << "\"SCRHCRHCRHCRH!\" You see a giant skulltula crawling towards you!" << endl;
		cout << "You suddenly remember you have some weapons!" << endl;
		do
		{
			cout << endl << endl;

			cout << "What do you grab? " << endl;
			cout << "1. Wooden Sword" << endl;
			cout << "2. Slingshot" << endl;
			choice = intInputValid();
			cout << endl << endl << endl;

			while (choice < 1 || choice > 2)
			{

				cout << endl << "That is not a valid input.  Please enter a number between 1 and 2." << endl << endl;
				choice = intInputValid();
				cout << endl << endl << endl;
			}

			if (choice == 1)
			{
				cout << endl << endl;

				cout << "You quickly draw your wooden sword and swing!" << endl;
				cout << "*tink*" << endl;
				cout << "Your sword is reflected off of the skulltula's rock-hard exoskeleton." << endl;
				cout << "The skulltula charges. You raise your sword in defense and redirect the skulltula's attack." << endl;
			}
			else if (choice = 2)
			{
				cout << endl << endl;

				cout << "You reach for you slingshot and ready a deku seed." << endl;
				cout << "\"SCRHCRHCRHCRH!\" The skulltula rapidly crawls closer." << endl;
				cout << "You draw back. . . and release!" << endl;
				cout << "You hit the skulltula dead in the eye and it falls over stunned." << endl;
				cout << "You run over and draw your wooden sword and stab it in it's soft underbelly." << endl;
				specialAction();
			}
		} while (choice != 2);

		cout << endl << endl;

		cout << "*Whew* The skulltula is dead.  You look around and notice 2 doors:" << endl;
		cout << "1 to the West that leads back to the entrance and 1 directly to North." << endl;
		cout << "What do you do?" << endl;
		cout << "1. Go West" << endl;
		cout << "2. Go North" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;
	}
	else
	{
		cout << endl << endl;

		cout << "*Whew* The skulltula is dead.  You look around and notice 2 doors:" << endl;
		cout << "1 to the West that leads back to the entrance and 1 directly to North that leads to Basement 1." << endl;
		cout << "What do you do?" << endl;
		cout << "1. Go West" << endl;
		cout << "2. Go North" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;
	}

	choice = intInputValid();
	cout << endl << endl << endl;

	while (choice < 1 || choice > 3)
	{
		cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
		choice = intInputValid();
		cout << endl << endl << endl;
	}
	return choice;
}

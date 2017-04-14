#include "BossRoom.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for BossRoom Class
****************************************************************/

BossRoom::BossRoom()
{
	name = "Boss";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	specialItem = "Boss";
	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void BossRoom::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool BossRoom::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string BossRoom::getSpecialItem()
{
	return specialItem;
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void BossRoom::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void BossRoom::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void BossRoom::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void BossRoom::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int BossRoom::dispayMenu()
{
	cout << "\"Hey! Listen!\" You hear the familair cry of your lost friend." << endl;
	cout << "You scan the room and immediately find Navi in a cage on the far end of the room." << endl;
	cout << "You dash towards her but all of a sudden you witness the appearance of a gigantic shadow covering the room." << endl;
	cout << "Ghoma! The arachnid queen drops to the floor and almost squishes you, but you roll our of the way just in time." << endl;
	cout << "You must think fast.  You need something to attack Ghoma with!" << endl;

	do
	{
		cout << endl << endl;

		cout << "What do you do?" << endl;
		cout << "1. Draw wooden sword" << endl;
		cout << "2. Grab your slingshot" << endl;
		cout << "3. Throw a bomb" << endl;
		cout << "4. Abandon your quest to save Navi and leave her to die" << endl;

		choice = intInputValid();
		cout << endl << endl << endl;
		while (choice < 1 || choice > 4)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 4." << endl << endl;
			choice = intInputValid();
			cout << endl << endl << endl;
		}

		if (choice == 1)
		{
			cout << endl << endl;

			cout << "You reach for your sword, but your hand slips!" << endl;
			cout << "Ghoma lunges at you and knocks you to the gorund." << endl;
			cout << "\"SCRHCRHCRHCRH!\" Your head rings with pain as she bellows in your ear." << endl;
			cout << "With a mighty kick you force Ghoma off of you. You roll to the side and jump on your feet." << endl;
			cout << "You realize your wooden sword will be of no use to you in this fight." << endl;
			cout << "You use your quick wits to reach for your slingshot as you did against the skulltula earlier!" << endl;
			choice = 2;
			cout << endl << endl << endl;
		}
		
		if (choice == 2)
		{
			cout << endl << endl;

			cout << "You go to grab your slingshot, but it's not there!" << endl;
			cout << "You must have dropped it when you rolled away from Ghoma's surprise attack!" << endl;
			cout << "Thinking quickly, you decide to throw a bomb at Ghoma!" << endl;
			choice = 3;
			cout << endl << endl << endl;
		}
		
		if (choice == 3)
		{
			cout << endl << endl;

			cout << "You take a bomb from your bag and throw it as hard as you can right at Ghoma's face!" << endl;
			cout << "\"SCRHCRHCRHCRH!\" She screeches as her eight legs twist and turn trying to get away from the bomb." << endl;
			cout << "*BOOM* *BOOM* *BOOM*" << endl;
			cout << "The bomb seemed to have set off a chain reaction from within the dungeon." << endl;
			cout << "The ceiling starts to crumble and you see Ghoma get squished by the falling debris." << endl;
			cout << "You rush over to Navi as fast as you can and grab the cage and make a break for the exit." << endl;
			cout << "Debris continues to fall everywhere.  You continue running without looking back." << endl;
			cout << "You see the light shining from the exit! You run and run and don't stop until you are safely outside of the Great Deku Tree." << endl;
			cout << "You escaped with your life and your fairy! You collapse on the ground, the cage dropping from your hands as you do so." << endl;
			cout << "\"Hey! Listen!\" Navi exclaims as she is released from the broken cage." << endl;
			cout << "You smile at your fairy companion glad that she is back, close your eyes, and fall sleep right there on the ground." << endl;
			cout << "THE END" << endl;
		}
		else if (choice == 4)
		{
			return choice;
		}

	} while (choice != 3);

	return choice;
}

#include "Game.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for Game Class
****************************************************************/

/*****************************************************
** Description: Default constructor for Game
******************************************************/
Game::Game()
{
	//Create the dungeon
	entranceRoom = new EntranceRoom();
	bombRoom = new BombRoom();
	b1Room = new B1Room();
	b2Room = new B2Room();
	skulltulaRoom = new SkulltulaRoom();
	bossRoom = new BossRoom();

	//Create the player
	player = entranceRoom;
	fatigue = 0;
	invMax = 6;
	inventory.push_back("sword");
	inventory.push_back("slingshot");
	inventory.push_back("dekuSeeds");

	//Idea for this was taken from Chris's example final
	//Set Entrance Doors
	entranceRoom->setNorth(bossRoom);
	entranceRoom->setEast(skulltulaRoom);
	entranceRoom->setWest(bombRoom);

	//Set BombRoom Doors
	bombRoom->setEast(entranceRoom);

	//Set SkulltulaRoom Doors
	skulltulaRoom->setWest(entranceRoom);
	skulltulaRoom->setNorth(b1Room);

	//Set B1Room Doors
	b1Room->setNorth(b2Room);
	b1Room->setSouth(skulltulaRoom);

	//Set BossRoom Doors
	bossRoom->setSouth(entranceRoom);
}

/*****************************************************
** Description: Plays the game
******************************************************/
void Game::play()
{
	do
	{
		if (player == entranceRoom)
		{
			cout << endl;
			displayFatigue();
			choice = entranceRoom->dispayMenu();

			switch (choice)
			{
			//Go North
			case 1:
				if (b2Room->getSpecialAction() == true)
				{
					player = bossRoom;
				}
				else
				{
					cout << "The door is locked! You need a key to pass through!" << endl << endl;
				}

				raiseFatigue();

				if (fatigue == 25)
				{
					cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
				}

				if (fatigue == 50)
				{
					cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
				}

				if (fatigue == 75)
				{
					cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
					cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
				}

				if (fatigue == 100)
				{
					cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
					cout << "You never wake up.  Navi is never saved." << endl;
					cout << "GAME OVER" << endl << endl << endl;
					bossRoom->specialAction();
				}
				break;

			//Go West
			case 2:
				player = bombRoom;
				raiseFatigue();

				if (fatigue == 25)
				{
					cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
				}

				if (fatigue == 50)
				{
					cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
				}

				if (fatigue == 75)
				{
					cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
					cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
				}

				if (fatigue == 100)
				{
					cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
					cout << "You never wake up.  Navi is never saved." << endl;
					cout << "GAME OVER" << endl << endl << endl;
					bossRoom->specialAction();
				}
				break;

			//Go East
			case 3:
				player = skulltulaRoom;
				raiseFatigue();

				if (fatigue == 25)
				{
					cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
				}

				if (fatigue == 50)
				{
					cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
				}

				if (fatigue == 75)
				{
					cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
					cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
				}

				if (fatigue == 100)
				{
					cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
					cout << "You never wake up.  Navi is never saved." << endl;
					cout << "GAME OVER" << endl << endl << endl;
					bossRoom->specialAction();
				}
				break;

			//Quit
			case 4:
				bossRoom->specialAction();
				cout << "You have given up all hope of saving your fairy, Navi." << endl;
				cout << "You gather up your belongings and walk out of the dungeon, defeated." << endl;
				cout << "GAME OVER" << endl;
				bossRoom->specialAction();
				break;
			}
		}
		else if (player == b1Room)
		{
			cout << endl;
			displayFatigue();
			choice = b1Room->dispayMenu();

				switch (choice)
				{
				//Go North
				case 1:
					if (b1Room->getSpecialAction() == false)
					{
						if (bombRoom->getSpecialAction() == false)
						{
							cout << "If only you had something explosive that could break this wall." << endl;
						}
						else if (bombRoom->getSpecialAction() == true)
						{
							cout << "You pull out a bomb and use it to blast a hole in the wall!" << endl;
							cout << "Through the hole in the wall you see another room." << endl;
							b1Room->specialAction();
						}
					}
					else if (b1Room->getSpecialAction() == true)
					{
						player = b2Room;
					}
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Go South
				case 2:
					player = skulltulaRoom;
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Quit
				case 3:
					bossRoom->specialAction();
					cout << "You have given up all hope of saving your fairy, Navi." << endl;
					cout << "You gather up your belongings and walk out of the dungeon, defeated." << endl;
					cout << "GAME OVER" << endl;
					break;
				}

		}
		else if (player == b2Room)
		{
			cout << endl;
			displayFatigue();
			choice = b2Room->dispayMenu();

				switch (choice)
				{
				//Investigate the odd tile
				case 1:
					//Add the key to inventory
					inventory.push_back(b2Room->getSpecialItem());
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Go South
				case 2:
					player = b1Room;
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Quit
				case 3:
					bossRoom->specialAction();
					cout << "You have given up all hope of saving your fairy, Navi." << endl;
					cout << "You gather up your belongings and walk out of the dungeon, defeated." << endl;
					cout << "GAME OVER" << endl;
					break;
				}
		}
		else if (player == bombRoom)
		{
			cout << endl;
			displayFatigue();
			choice = bombRoom->dispayMenu();

			switch (choice)
			{
			//Investigate rubble
			case 1:
				//Add bombs to inventory
				inventory.push_back(bombRoom->getSpecialItem());
				raiseFatigue();

				if (fatigue == 25)
				{
					cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
				}

				if (fatigue == 50)
				{
					cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
				}

				if (fatigue == 75)
				{
					cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
					cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
				}

				if (fatigue == 100)
				{
					cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
					cout << "You never wake up.  Navi is never saved." << endl;
					cout << "GAME OVER" << endl << endl << endl;
					bossRoom->specialAction();
				}
				break;

			//Return to the entrance
			case 2:
				player = entranceRoom;
				raiseFatigue();

				if (fatigue == 25)
				{
					cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
				}

				if (fatigue == 50)
				{
					cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
				}

				if (fatigue == 75)
				{
					cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
					cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
				}

				if (fatigue == 100)
				{
					cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
					cout << "You never wake up.  Navi is never saved." << endl;
					cout << "GAME OVER" << endl << endl << endl;
					bossRoom->specialAction();
				}
				break;

			//Quit
			case 3:
				bossRoom->specialAction();
				cout << "You have given up all hope of saving your fairy, Navi." << endl;
				cout << "You gather up your belongings and walk out of the dungeon, defeated." << endl;
				cout << "GAME OVER" << endl;
				break;
			}
		}
		else if (player == bossRoom)
		{
			cout << endl;
			displayFatigue();

			//Boss fight
			choice = bossRoom->dispayMenu();
			bossRoom->specialAction();
		}
		else if (player == skulltulaRoom)
		{
			cout << endl;
			displayFatigue();
			choice = skulltulaRoom->dispayMenu();
				switch (choice)
				{
				//Go West
				case 1:
					player = entranceRoom;
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Go North
				case 2:
					player = b1Room;
					raiseFatigue();

					if (fatigue == 25)
					{
						cout << "You notice a slight soreness in your muscles.  You grow slightly tired." << endl << endl << endl;
					}

					if (fatigue == 50)
					{
						cout << "Your muscles begin to ache as you grow somewhat more tired.  Your body starts to slow." << endl << endl << endl;
					}

					if (fatigue == 75)
					{
						cout << "You grow even more tired.  You realize you do not have much energy left." << endl;
						cout << "You must hurry if you wish to save Navi before your body gives way." << endl << endl << endl;
					}

					if (fatigue == 100)
					{
						cout << "You are exhausted and cannot go on.  You drop to the floor and close your eyes." << endl;
						cout << "You never wake up.  Navi is never saved." << endl;
						cout << "GAME OVER" << endl << endl << endl;
						bossRoom->specialAction();
					}
					break;

				//Quit
				case 3:
					bossRoom->specialAction();
					cout << "You have given up all hope of saving your fairy, Navi." << endl;
					cout << "You gather up your belongings and walk out of the dungeon, defeated." << endl;
					cout << "GAME OVER" << endl;
					break;
				}
		}
	}while (bossRoom->getSpecialAction() == false);

	//Add a pause so the user can read the final screen before game quits
	cin.get();
	cin.ignore();

	//Delete pointers
	delete entranceRoom;
	entranceRoom = nullptr;
	delete bombRoom;
	bombRoom = nullptr;
	delete b1Room;
	b1Room = nullptr;
	delete b2Room;
	b2Room = nullptr;
	delete skulltulaRoom;
	skulltulaRoom = nullptr;
	delete bossRoom;
	bossRoom = nullptr;
}

/*****************************************************
** Description: Increases the player's fatigue
******************************************************/
void Game::raiseFatigue()
{
	fatigue++;
}

/*****************************************************
** Description: Displays the player's fatigue
******************************************************/
void Game::displayFatigue()
{
	cout << "Fatigue: " << fatigue << endl << endl;
}

/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for Game Class
****************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "Dungeon.hpp"
#include "B1Room.hpp"
#include "B2Room.hpp"
#include "BombRoom.hpp"
#include "BossRoom.hpp"
#include "EntranceRoom.hpp"
#include "SkulltulaRoom.hpp"
#include "IntInputValid.hpp"
#include <stack>
#include <string>
#include <vector>
#include <iostream>

using std::stack;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Game
{
private:
	//Declare the dungeon
	Dungeon *entranceRoom;
	Dungeon *bombRoom;
	Dungeon *b1Room;
	Dungeon *b2Room;
	Dungeon *skulltulaRoom;
	Dungeon *bossRoom;

	//Create Characteristics
	int fatigue;
	int invMax;
	vector<string> inventory;

	Dungeon *player;
	int choice;

public:
	Game();
	void play();
	void raiseFatigue();
	void displayFatigue();
};
#endif 

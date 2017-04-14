/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for Dungeon abstract Class
****************************************************************/
#ifndef DUNGEON_HPP
#define DUNGEON_HPP
#include <string>
#include "IntInputValid.hpp"

using std::string;

class Dungeon
{
protected:
	//Pointers to other directions
	Dungeon *north;
	Dungeon *south;
	Dungeon *east;
	Dungeon *west;

	//Stuff in room
	string name;
	string specialItem;

	//Specify whether the room status has changed or not
	bool changedStatus;

	//Variable for menu choice
	int choice;

public:
	Dungeon();
	void virtual specialAction() = 0;
	bool virtual getSpecialAction() = 0;
	string virtual getSpecialItem() = 0;
	void virtual setNorth(Dungeon*) = 0;
	void virtual setSouth(Dungeon*) = 0;
	void virtual setEast(Dungeon*) = 0;
	void virtual setWest(Dungeon*) = 0;
	int virtual dispayMenu() = 0;
	
};

#endif 

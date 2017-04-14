/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for EntranceRoom derived Class
****************************************************************/
#ifndef ENTRANCEROOM_HPP
#define ENTRANCEROOM_HPP
#include "Dungeon.hpp"
#include "B1Room.hpp"
#include "B2Room.hpp"
#include "BombRoom.hpp"
#include "BossRoom.hpp"
#include "SkulltulaRoom.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class EntranceRoom : public Dungeon
{
public:
	EntranceRoom();
	void virtual specialAction();
	bool virtual getSpecialAction();
	string virtual getSpecialItem();
	void virtual setNorth(Dungeon*);
	void virtual setSouth(Dungeon*);
	void virtual setEast(Dungeon*);
	void virtual setWest(Dungeon*);
	int virtual dispayMenu();
};

#endif 

/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for SkulltulaRoom derived Class
****************************************************************/
#ifndef SKULLTULAROOM_HPP
#define SKULLTULAROOM_HPP
#include "Dungeon.hpp"
#include "B1Room.hpp"
#include "B2Room.hpp"
#include "BombRoom.hpp"
#include "BossRoom.hpp"
#include "EntranceRoom.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class SkulltulaRoom : public Dungeon
{
public:
	SkulltulaRoom();
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

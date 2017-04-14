/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for BossRoom derived Class
****************************************************************/
#ifndef BOSSROOM_HPP
#define BOSSROOM_HPP
#include "Dungeon.hpp"
#include "B1Room.hpp"
#include "B2Room.hpp"
#include "BombRoom.hpp"
#include "EntranceRoom.hpp"
#include "SkulltulaRoom.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class BossRoom : public Dungeon
{
public:
	BossRoom();
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

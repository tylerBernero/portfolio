/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Header file for B2Room derived Class
****************************************************************/
#ifndef B2ROOM_HPP
#define B2ROOM_HPP
#include "Dungeon.hpp"
#include "B1Room.hpp"
#include "BombRoom.hpp"
#include "BossRoom.hpp"
#include "EntranceRoom.hpp"
#include "SkulltulaRoom.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class B2Room : public Dungeon
{
public:
	B2Room();
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
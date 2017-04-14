/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Menu class
******************************************************/
#include "Creature.hpp"
#include "LineupNode.hpp"
#include "LoserNode.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#ifndef MENU_HPP
#define MENU_HPP

class Menu
{
private:
	int menuChoice;
	int numOfChamps;
	char creatureChoice;
	Lineup p1Line;
	string p1;
	int p1Score;
	Lineup p2Line;
	string p2;
	int p2Score;
	Creature *c1;
	Creature *c2;
	int rando;
	int c1Att;
	int c2Att;
	int round = 1;
	Loser loserPile;
	string name;
	Creature *cPtr1;
	Creature *cPtr2;
	LineupNode *nodePtr1;
	LineupNode *nodePtr2;

public:
	Menu();
	void callMenu();
	void battle(Creature*, Creature*);
	void displayScore();
	void displayWinner();
};
#endif
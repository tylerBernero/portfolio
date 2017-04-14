/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for LineupNode class
******************************************************/
#ifndef LINEUP_HPP
#define LINEUP_HPP
#include "Creature.hpp"

//Struct for a circular queue to hold the player's lineup of champions
struct LineupNode
{
	Creature *creature;
	LineupNode *next;

	//Constructor
	LineupNode(Creature* creature1, LineupNode *next1)
	{
		creature = creature1;
		next = next1;
	}
};

class Lineup
{

private:
	LineupNode *front;
	LineupNode *rear;

public:
	Lineup();
	~Lineup();
	void enqueue(Creature*);
	Creature* dequeue();
	bool isEmpty() const;
	void displayLineup();
	Creature* getChamp();
	LineupNode* getFront();
	void movePtr();
};

#endif

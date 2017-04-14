/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for LoserNode class
******************************************************/
#ifndef LOSERNODE_HPP
#define LOSERNODE_HPP
#include "Creature.hpp"

class Loser
{

	struct LoserNode
	{
		Creature *loser;
		LoserNode *next;

		//Constructor
		LoserNode(Creature *loser1, LoserNode *next1 = nullptr)
		{
			loser = loser1;
			next = next1;
		}
	};

private:
	LoserNode *top;

public:
	Loser();
	~Loser();
	void push(Creature*);
	void pop(Creature* &);
	bool isEmpty() const;
	Creature* getLoser();
	void displayLosers();
};
#endif

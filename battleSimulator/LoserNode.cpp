/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for LoserNode class
******************************************************/
#include "LoserNode.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*****************************************************
** Description: Constructor for Loser class
******************************************************/
Loser::Loser()
{
	top = nullptr;
}

/*****************************************************
** Description: Constructor for Loser class
******************************************************/
Loser::~Loser()
{
	LoserNode *garbage = top;
	while (garbage != nullptr)
	{
		top = top->next;
		garbage->next = nullptr;
		delete garbage->loser;
		garbage->loser = nullptr;
		delete garbage;
		garbage = top;
	}
}

/*****************************************************
** Description: Adds a new creature to the loser pile
******************************************************/
void Loser::push(Creature *creature)
{
	top = new LoserNode(creature, top);
}

/*****************************************************
** Description: Deletes top of stack
******************************************************/
void Loser::pop(Creature* &creat)
{
	LoserNode *temp;

	creat = top->loser;
	temp = top;
	top = top->next;
	delete temp;
}

/*****************************************************
** Description: Returns whether or not stack is empty
******************************************************/
bool Loser::isEmpty() const
{
	return top == nullptr;
}

/*****************************************************
** Description: Returns creature at top of loser pile
******************************************************/
Creature* Loser::getLoser()
{
	if (top == nullptr)
	{
		return nullptr;
	}
	else
	{
		return top->loser;
	}
}

/*****************************************************
** Description: Displays the loser stack
******************************************************/
void Loser::displayLosers()
{
	//Create QueueNode object to pass through node
	Creature *n;
	int num = 1;

	//Make sure Queue isn't empty
	if (top == nullptr)
	{
		cout << "The loser pile is empty! There is nothing to dispay!" << endl << endl;
	}
	else
	{
		do
		{
			//Print the contents of the current node
			n = getLoser();
			cout << num << ". " << n->getUserName() << endl;
			num++;

			//Move to the next node
			top = top->next;
		} while (top != nullptr);
	}
}
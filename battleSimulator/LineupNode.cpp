/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for LineupNode class
******************************************************/
#include "LineupNode.hpp"
#include <iostream>

using std::cout;
using std::endl;

/*****************************************************
** Description: Constructor for Lineup class
******************************************************/
Lineup::Lineup()
{
	front = nullptr;
	rear = nullptr;
}

/*****************************************************
** Description: Deconstructor for Lineup class
******************************************************/
Lineup::~Lineup()
{
	Creature *temp;

	if (front != nullptr)
	{
		while (front != rear)
		{
			//Delete front pointer and set to nullptr
			delete front->creature;
			front->creature = nullptr;

			//If front points to itself, delete front pointer and set to nullptr
			if (front->next == front)
			{
				temp = front->creature;
				delete front;
				front = nullptr;
			}
			else
			{
				temp = front->creature;
				rear->next = front->next;
				delete front;
				front = rear->next;
			}
		}

		//Since front now equals rear, delete last node and set to nullptr
		delete front->creature;
		front->creature = nullptr;

		if (front->next == front)
		{
			temp = front->creature;
			delete front;
			front = nullptr;
		}
		else
		{
			temp = front->creature;
			rear->next = front->next;
			delete front;
			front = rear->next;
		}

		rear = nullptr;
	}
}

/*****************************************************
** Description: Adds item to back of the lineup
******************************************************/
void Lineup::enqueue(Creature *creature)
{
	if (isEmpty())
	{
		front = new LineupNode(creature, front);
		rear = front;
	}
	else
	{
		rear->next = new LineupNode(creature, front);
		rear = rear->next;
	}
}

/*****************************************************
** Description: Deletes top of lineup
******************************************************/
Creature* Lineup::dequeue()
{
	Creature *temp;
	if(isEmpty())
	{
		cout << "Queue is empty!" << endl;
		return nullptr;
	}
	else if (front->next == front)
	{
		temp = front->creature;
		delete front;
		front = nullptr;
	}
	else
	{
		temp= front->creature;
		rear->next = front->next;
		delete front;
		front = rear->next;
	}

	return temp;
}

/*****************************************************
** Description: Returns whether or not lineup is empty
******************************************************/
bool Lineup::isEmpty() const
{
	if (front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*****************************************************
** Description: Displays the lineup
******************************************************/
void Lineup::displayLineup()
{
	//Create LineupNode object to pass through node
	LineupNode *nodePtr = front;
	Creature *temp;
	int i = 1;

	//Make sure Queue isn't empty
	if (nodePtr->next == nullptr)
	{
		cout << "The lineup is empty! There is nothing to dispay!" << endl << endl;
	}
	else
	{
		do
		{
			//Print the contents of the current node
			temp = nodePtr->creature;
			cout << i << ". " << temp->getUserName() << endl;
			i++;

			//Move to the next node
			nodePtr = nodePtr->next;
		} while (nodePtr != rear->next);
	}
}

/*****************************************************
** Description: Returns creature at top of lineup
******************************************************/
Creature* Lineup::getChamp()
{
	if (front == nullptr)
	{
		return nullptr;
	}
	else
	{
		return front->creature;
	}
}

/*****************************************************
** Description: Returns node at top of lineup
******************************************************/
LineupNode * Lineup::getFront()
{
	if (front == nullptr)
	{
		return nullptr;
	}
	else
	{
		return front;
	}
}

/*****************************************************
** Description: Moves front and rear pointers to next
******************************************************/
void Lineup::movePtr()
{
	if (front != nullptr)
	{
		front = front->next;
		rear = rear->next;
	}
}

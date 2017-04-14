/***************************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Harry Potter class
****************************************************************/
#include "HarryPotter.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


/*****************************************************
** Description: Default constructor for Harry Potter
** class.  Sets all variables to appropriate values
******************************************************/
HarryPotter::HarryPotter()
{
	name = "Harry Potter";
	att = 0;
	def = 0;
	arm = 0;
	maxStr = 10;
	str = 10;
	totalAtt = 0;
	death = 0;
	charm = 0;
}

/*****************************************************
** Description: Return armor
******************************************************/
int HarryPotter::getArm()
{
	return arm;
}

/*****************************************************
** Description: Sets strength
******************************************************/
void HarryPotter::setStr(int x)
{
	str = x;
}

/*****************************************************
** Description: Return strength
******************************************************/
int HarryPotter::getStr()
{
	return str;
}

/*****************************************************
** Description: Set max strength
******************************************************/
void HarryPotter::setMaxStr(int x)
{
	maxStr = x;
}

/*****************************************************
** Description: Return name
******************************************************/
string HarryPotter::getName()
{
	return name;
}

/*****************************************************
** Description: Set user name
******************************************************/
void HarryPotter::setUserName(string n)
{
	userName = n;
}

/*****************************************************
** Description: Return user name
******************************************************/
string HarryPotter::getUserName()
{
	return userName;
}

/*****************************************************
** Description: Return death
******************************************************/
int HarryPotter::getDeath()
{
	return death;
}

/*****************************************************
** Description: Set death
******************************************************/
void HarryPotter::setDeath(int x)
{
	death = x;
}

/*****************************************************
** Description: Rolls 2d6 to calculate attack then
**dispays and returns the attack value
******************************************************/
int HarryPotter::attack()
{
	att = d6.roll() + d6.roll();
	cout << "Attack is: " << att << endl;
	return att;
}

/*****************************************************
** Description: Rolls 2d6 to calculate defense then
** subtracts defense and armor from attack to get
** total attack value and returns that. If strength
** hits 0, revives with 20 strength and sets death
** to 1 so as to not be revived again
******************************************************/
int HarryPotter::defend(int att)
{
	def = d6.roll() + d6.roll();
	cout << "Defense is: " << def << endl;
	totalAtt = att - def;
	cout << "Armor is: " << arm << endl;
	totalAtt -= arm;
	cout << "Total Attack is: " << totalAtt << endl;

	//If damage is less than 0, do not apply damage. Otherwise, apply damage as normal
	if (totalAtt < 1)
	{
		cout << "No damage was done." << endl;
		return str;
	}
	else
	{
		str -= totalAtt;

		//Hogwarts - on first death, revive Harry with 20 strength
		if (str < 1)
		{
			if (death == 0)
			{
				cout << "Harry Potter has " << str << " strength." << endl;
				cout << "Harry Potter is dead. But wait. . ." << endl;
				cout << "Praise be to Hogwarts! Harry Potter has been revived, stronger than ever before!" << endl;
				cout << "Harry Potter now has 20 strength!" << endl;
				setStr(20);
				maxStr = 20;
				setDeath(1);
				return str;
			}
			else
			{
				return str;
			}
		}
		else
		{
			return str;
		}
	}
}

void HarryPotter::recover()
{
	maxStr = maxStr + 2;
	setStr(maxStr);
}

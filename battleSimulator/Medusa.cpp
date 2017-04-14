/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Medusa class
******************************************************/
#include "Medusa.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/*****************************************************
** Description: Default constructor for Medusa
** class.  Sets all variables to appropriate values
******************************************************/
Medusa::Medusa():Creature()
{
	name = "Medussssssa";
	att = 0;
	def = 0;
	arm = 3;
	maxStr = 8;
	str = 8;
	totalAtt = 0;
	death = 0;
	charm = 0;
}

/*****************************************************
** Description: Returns armor
******************************************************/
int Medusa::getArm()
{
	return arm;
}

/*****************************************************
** Description: Sets strength
******************************************************/
void Medusa::setStr(int x)
{
	str = x;
}

/*****************************************************
** Description: Sets max strength
******************************************************/
void Medusa::setMaxStr(int x)
{
	maxStr = x;
}

/*****************************************************
** Description: Returns strength
******************************************************/
int Medusa::getStr()
{
	return str;
}

/*****************************************************
** Description: Returns name
******************************************************/
string Medusa::getName()
{
	return name;
}

/*****************************************************
** Description: Set user name
******************************************************/
void Medusa::setUserName(string n)
{
	userName = n;
}

/*****************************************************
** Description: Return user name
******************************************************/
string Medusa::getUserName()
{
	return userName;
}

/*****************************************************
** Description: Return death
******************************************************/
int Medusa::getDeath()
{
	return 0;
}

/*****************************************************
** Description: Set death
******************************************************/
void Medusa::setDeath(int x)
{
}

/*****************************************************
** Description: Rolls 2d6 to get attack value then 
** displays and returns it.  If a 12 is rolled, return
** 100 attack so the Battle program knows to petrify
** the opponent
******************************************************/
int Medusa::attack()
{
	att = d6.roll() + d6.roll();
	cout << "Attack is: " << att << endl;

	if (att == 12)
	{
		cout << "GLARE! Medusa has turned her opponent to stone!" << endl;
		att = 100;
		return att;
	}
	else
	{
		return att;
	}
}

/*****************************************************
** Description: Rolls 1d6 to calculate defense then
** subtracts defense and armor from attack to get
** total attack value and returns that.  
******************************************************/
int Medusa::defend(int att)
{
	def = d6.roll();
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
		return str;
	}
}

void Medusa::recover()
{
	maxStr = maxStr + 2;
	setStr(maxStr);
}

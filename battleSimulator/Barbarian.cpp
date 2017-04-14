/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Barbarian class
******************************************************/
#include "Barbarian.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


/*****************************************************
** Description: Default constructor for Barbarian
** class.  Sets all variables to appropriate values
******************************************************/
Barbarian::Barbarian():Creature()
{
	name = "Barbarian";
	att = 0;
	def = 0;
	arm = 0;
	maxStr = 12;
	str = 12;
	totalAtt = 0;
	death = 0;
	charm = 0;
}


/*****************************************************
** Description: Returns armor
******************************************************/
int Barbarian::getArm()
{
	return arm;
}

/*****************************************************
** Description: Sets strength
******************************************************/
void Barbarian::setStr(int x)
{
	str = x;
}

/*****************************************************
** Description: Sets max strength
******************************************************/
void Barbarian::setMaxStr(int x)
{
	maxStr = x;
}

/*****************************************************
** Description: Returns strength
******************************************************/
int Barbarian::getStr()
{
	return str;
}

/*****************************************************
** Description: Return name
******************************************************/
string Barbarian::getName()
{
	return name;
}

/*****************************************************
** Description: Set user name
******************************************************/
void Barbarian::setUserName(string n)
{
	userName = n;
}

/*****************************************************
** Description: Return user name
******************************************************/
string Barbarian::getUserName()
{
	return userName;
}

/*****************************************************
** Description: Return death
******************************************************/
int Barbarian::getDeath()
{
	return 0;
}

/*****************************************************
** Description: Set death
******************************************************/
void Barbarian::setDeath(int x)
{
}

/*****************************************************
** Description: Rolls 2d6 to calculate attack then 
**dispays and returns the attack value
******************************************************/
int Barbarian::attack()
{
	att = d6.roll() + d6.roll();
	cout << "Attack is: " << att << endl;
	return att;
}

/*****************************************************
** Description: Rolls 2d6 to calculate defense then
** subtracts defense and armor from attack to get 
** total attack value and returns that
******************************************************/
int Barbarian::defend(int att)
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
		return str;
	}
}
void Barbarian::recover()
{
	maxStr = maxStr + 2;
	setStr(maxStr);
}

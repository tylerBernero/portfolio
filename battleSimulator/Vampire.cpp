/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Vampire class
******************************************************/
#include "Vampire.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

/*****************************************************
** Description: Default constructor for Vampire
** class.  Sets all values to appropriate values
******************************************************/
Vampire::Vampire():Creature()
{
	name = "Vampire";
	att = 0;
	def = 0;
	arm = 1;
	maxStr = 18;
	str = 18;
	totalAtt = 0;
	death = 0;
	charm = 0;
}

/*****************************************************
** Description: Return armor
******************************************************/
int Vampire::getArm()
{
	return arm;
}

/*****************************************************
** Description: Set strength
******************************************************/
void Vampire::setStr(int x)
{
	str = x;
}

/*****************************************************
** Description: Set max strength
******************************************************/
void Vampire::setMaxStr(int x)
{
	maxStr = x;
}

/*****************************************************
** Description: Return strength
******************************************************/
int Vampire::getStr()
{
	return str;
}

/*****************************************************
** Description: Return name
******************************************************/
string Vampire::getName()
{
	return name;
}

/*****************************************************
** Description: Set user name
******************************************************/
void Vampire::setUserName(string n)
{
	userName = n;
}

/*****************************************************
** Description: Return user name
******************************************************/
string Vampire::getUserName()
{
	return userName;
}

/*****************************************************
** Description: Get death
******************************************************/
int Vampire::getDeath()
{
	return 0;
}

/*****************************************************
** Description: Set death
******************************************************/
void Vampire::setDeath(int x)
{
}

/*****************************************************
** Description: Rolls 1d12 to get attack value then 
** displays and returns it
******************************************************/
int Vampire::attack()
{
	att = d12.roll();
	cout << "Attack is: " << att << endl;
	return att;
}

/*****************************************************
** Description: Rolls 1d6 to calculate defense then
** subtracts defense and armor from attack to get 
** total attack value and returns that.  Also uses
** RNG to determine if Charm activates are not
******************************************************/
int Vampire::defend(int att)
{
	//Calculate number for Charm.  50% chance to avtivate
	charm = rand() % 2 + 1;

	if (charm == 1)
	{
		cout << "The Vampire's Charm negated the attack. No damage was done." << endl;
		return str;
	}
	else
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
}

void Vampire::recover()
{
	maxStr = maxStr + 2;
	setStr(maxStr);
}

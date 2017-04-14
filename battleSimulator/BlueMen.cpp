/***************************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Blue Men class
****************************************************************/
#include "BlueMen.hpp"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;


/*****************************************************
** Description: Default constructor for Blue Men
** class.  Sets all variables to appropriate values
******************************************************/
BlueMen::BlueMen():Creature()
{
	name = "Blue Men";
	att = 0;
	def = 0;
	arm = 3;
	maxStr = 12;
	str = 12;
	totalAtt = 0;
	death = 0;
	charm = 0;
}

/*****************************************************
** Description: Returns armor
******************************************************/
int BlueMen::getArm()
{
	return arm;
}

/*****************************************************
** Description: Sets strength
******************************************************/
void BlueMen::setStr(int x)
{
	str = x;
}

/*****************************************************
** Description: Sets strength
******************************************************/
void BlueMen::setMaxStr(int x)
{
	maxStr = x;
}

/*****************************************************
** Description: Returns name
******************************************************/
int BlueMen::getStr()
{
	return str;
}

/*****************************************************
** Description: Returns name
******************************************************/
string BlueMen::getName()
{
	return name;
}

/*****************************************************
** Description: Set user name
******************************************************/
void BlueMen::setUserName(string n)
{
	userName = n;
}

/*****************************************************
** Description: Return user name
******************************************************/
string BlueMen::getUserName()
{
	return userName;
}

/*****************************************************
** Description: Return death
******************************************************/
int BlueMen::getDeath()
{
	return 0;
}

/*****************************************************
** Description: Set death
******************************************************/
void BlueMen::setDeath(int x)
{
}

/*****************************************************
** Description: Rolls 2d10 to calculate attack then 
**dispays and returns the attack value
******************************************************/
int BlueMen::attack()
{
	att = d10.roll() + d10.roll();
	cout << "Attack is: " << att << endl;
	return att;
}

/*****************************************************
** Description: Rolls 3d6 to calculate defense then
** subtracts defense and armor from attack to get 
** total attack value and returns that. Loses 1d6
** defense for each 4 health lost
******************************************************/
int BlueMen::defend(int att)
{
	if (str <= 12 && str >=9 )
	{
		def = d6.roll() + d6.roll() + d6.roll();
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
		return str;
	}
	else if(str <= 8 && str >= 5)
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
		return str;
	}
	else if (str <= 4)
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

void BlueMen::recover()
{
	maxStr = maxStr + 2;
	setStr(maxStr);
}

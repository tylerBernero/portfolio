/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Creature class
******************************************************/
#include "Creature.hpp"


/*****************************************************
** Description: Default constructor for Creature
** class.  Sets name to Creature and other variables to 0
******************************************************/
Creature::Creature()
{
	name = "Creature";
	att = 0;
	def = 0;
	arm = 0;
	str = 0;
	totalAtt = 0;
	death = 0;
	charm = 0;
}

/*****************************************************
** Description: Virtual function to return armor
******************************************************/
int Creature::getArm()
{
	return 0;
}

/*****************************************************
** Description: Virtual function to return strength
******************************************************/
int Creature::getStr()
{
	return 0;
}

/*****************************************************
** Description: Virtual function to return name
******************************************************/
string Creature::getName()
{
	return string();
}

/*****************************************************
** Description: Virtual function to set user name
******************************************************/
void setUserName(string)
{
}

/*****************************************************
** Description: Virtual function to return user name
******************************************************/
string getUserName()
{
	return string();
}

/*****************************************************
** Description: Return death
******************************************************/
int Creature::getDeath()
{
	return 0;
}

/*****************************************************
** Description: Set death
******************************************************/
void Creature::setDeath(int x)
{
}

/*****************************************************
** Description: Virtual function to set strength
******************************************************/
void Creature::setStr(int x)
{
}

/*****************************************************
** Description: Virtual function to set max strength
******************************************************/
void Creature::setMaxStr(int)
{
}

/*****************************************************
** Description: Virtual function to attack
******************************************************/
int Creature::attack()
{
	return 0;
}

/*****************************************************
** Description: Virtual function to defend
******************************************************/
int Creature::defend(int)
{
	return 0;
}
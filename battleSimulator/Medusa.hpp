/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Medusa class
******************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"
#include "D6.hpp"

class Medusa :	public Creature
{
public:
	Medusa();
	virtual int getArm();
	virtual void setStr(int x);
	virtual void setMaxStr(int x);
	virtual int getStr();
	virtual string getName();
	virtual string getUserName();
	virtual void setUserName(string);
	virtual int getDeath();
	virtual void setDeath(int x);
	virtual int attack();
	virtual int defend(int);
	virtual void recover();
};
#endif
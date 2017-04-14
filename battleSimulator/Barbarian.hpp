/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Barbarian class
******************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp"
#include "D6.hpp"


class Barbarian :	public Creature
{
public:
	Barbarian();
	virtual int getArm();
	virtual void setStr(int);
	virtual void setMaxStr(int);
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
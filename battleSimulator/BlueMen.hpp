/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Blue Men class
******************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp"
#include "D10.hpp"
#include "D6.hpp"


class BlueMen :	public Creature
{
public:
	BlueMen();
	virtual int getArm();
	virtual void setStr(int);
	virtual void setMaxStr(int);
	virtual int getStr();
	virtual string getName();
	virtual string getUserName();
	virtual void setUserName(string) ;
	virtual int getDeath();
	virtual void setDeath(int x);
	virtual int attack();
	virtual int defend(int);
	virtual void recover();
};
#endif
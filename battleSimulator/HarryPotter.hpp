/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Harry Potter class
******************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp"
#include "D6.hpp"
class HarryPotter :	public Creature
{
public:
	HarryPotter();
	virtual int getArm();
	virtual void setStr(int x);
	virtual int getStr();
	void setMaxStr(int x);
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
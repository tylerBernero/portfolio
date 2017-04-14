/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Vampire class
******************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp"
#include "D6.hpp"
#include "D12.hpp"

class Vampire :	public Creature
{
public:
	Vampire();
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
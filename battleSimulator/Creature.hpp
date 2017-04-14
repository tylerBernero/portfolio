/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Creature class
******************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include "Die.hpp"
#include "D6.hpp"
#include "D10.hpp"
#include "D12.hpp"
#include <string>

using std::string;

class Creature
{
protected:
	D6 d6;
	D10 d10;
	D12 d12;
	string name;
	string userName;
	int att;
	int def;
	int arm;
	int maxStr;
	int str;
	int totalAtt;
	int death;
	int charm;

public:
	Creature();
	virtual int getArm() = 0;
	virtual int getStr() = 0;
	virtual string getName() = 0;
	virtual void setUserName(string) = 0;
	virtual string getUserName() = 0;
	virtual int getDeath() = 0;
	virtual void setDeath(int) = 0;
	virtual void setStr(int) = 0;
	virtual void setMaxStr(int);
	virtual int attack() = 0;
	virtual int defend(int) = 0;
	virtual void recover() = 0;
};
#endif
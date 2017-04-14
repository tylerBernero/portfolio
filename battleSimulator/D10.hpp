/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D10 class
******************************************************/
#ifndef D10_HPP
#define D10_HPP
#include "Die.hpp"
class D10 :	public Die
{
public:
	D10();
	virtual int roll();
};
#endif
/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D6 class
******************************************************/
#ifndef D6_HPP
#define D6_HPP
#include "Die.hpp"
class D6 :	public Die
{
public:
	D6();
	virtual int roll();
};
#endif
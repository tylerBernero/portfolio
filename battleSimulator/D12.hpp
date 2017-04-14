/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D12 class
******************************************************/
#ifndef D12_HPP
#define D12_HPP
#include "Die.hpp"
class D12 : public Die
{
public:
	D12();
	virtual int roll();
};
#endif
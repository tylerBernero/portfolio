/******************************************************
*Title: Project 4
*Author: Tyler Bernero
*Date: February 5, 2017
*Description: Item header file
*******************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

using std::string;


class Item
{
private:
	string itemName;
	string unit;
	int quantBuy;
	double unitPrice;

public:
	Item();
	Item(string, string, int, double);
	string getName();
	string getUnit();
	int getQuant();
	double getPrice();
};
#endif

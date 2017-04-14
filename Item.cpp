/******************************************************
*Title: Project 4
*Author: Tyler Bernero
*Date: February 5, 2017
*Description: Item source code
*******************************************************/
#include "Item.hpp"


Item::Item()
{

}
/******************************************************
						Item::Item
Description: Constructor for Item class
*******************************************************/
Item::Item(string name, string un, int quantity, double price)
{
	itemName = name;
	unit = un;
	quantBuy = quantity;
	unitPrice = price;
}

string Item::getName()
{
	return itemName;
}


string Item::getUnit()
{
	return unit;
}


int Item::getQuant()
{
	return quantBuy;
}


double Item::getPrice()
{
	return unitPrice;
}
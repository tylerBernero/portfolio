/******************************************************
*Title: Project 4
*Author: Tyler Bernero
*Date: February 5, 2017
*Description: List header file
*******************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"
#include <string>

using std::string;

class List 
{
private:
	int capacity = 4;
	Item *itemList;
	int currentSize = 0;
	double extPrice;
	double total = 0.0;
	int choice;

public:
	List();
	bool operator==(Item);
	void addItems(string, string, int, double);
	void remItems(string);
	void displayList();
	void displayMenu();
	void useMenu();
	int inputValid();
	void resize();
	~List();
};
#endif
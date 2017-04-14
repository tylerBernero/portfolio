/******************************************************
*Title: Project 4
*Author: Tyler Bernero
*Date: February 5, 2017
*Description: List source code
*******************************************************/
#include "List.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/******************************************************
						List::List
Description: Constructor for List class
*******************************************************/
List::List()
{
	itemList = new Item[capacity];
}

/******************************************************
						List::operator==
Description: Overload function for == operator to
compare items in list
*******************************************************/
bool List::operator==(Item b)
{
	for (int i = 0; i < capacity; i++)
	{
		if (itemList[i].getName() == b.getName())
		{
			return true;
		}
	}

	return false;
}

/******************************************************
						List::addItems
Description: Adds items to list object
*******************************************************/
void List::addItems(string n, string u, int q, double p)
{
	Item b(n, u, q, p);

	if ((*this == b) == (false))
	{

		//Check if the list is currently full
		if (currentSize == capacity)
		{
			//Resize array and add item
			resize();
			itemList[currentSize] = Item(n, u, q, p);
			currentSize += 1;
		}
		else
		{
			//Add item
			itemList[currentSize] = Item(n, u, q, p);
			currentSize += 1;
		}
	}
}

/******************************************************
						List::remItems
Description: Removes items from list object
*******************************************************/
void List::remItems(string remName)
{
	currentSize -= 1;
	for (int i = 0; i < capacity; i++)
	{
		if (itemList[i].getName() == remName)
		{
			for (int j = i; j < (capacity - 1); j++)
			{
				itemList[j] = itemList[j + 1];
			}
		}
	}
	cout << endl << endl;
}

/******************************************************
						List::displayList
Description: Displays the current list
*******************************************************/
void List::displayList()
{
	for (int i = 0; i < currentSize; i++)
	{
		cout << "Name: " << itemList[i].getName() << endl
			<< "Unit: " << itemList[i].getUnit() << endl
			<< "Quantity: " << itemList[i].getQuant() << endl
			<< "Price: $" << itemList[i].getPrice() << endl << endl;

		extPrice = itemList[i].getPrice() * itemList[i].getQuant();
		cout << "Extended Price: $" << extPrice << endl << endl;
		
		total += extPrice;
	}

	cout << "Total: $" << total << endl << endl;
}

/******************************************************
						List::displayMenu
Description: Displays the menu
*******************************************************/
void List::displayMenu()
{
	cout << "1. Add items to list" << endl;
	cout << "2. Remove items from the list" << endl;
	cout << "3. Display the list" << endl;
	cout << "4. Quit Program" << endl;
}

/******************************************************
						List::useMenu
Description: Activates the menu
*******************************************************/
void List::useMenu()
{
	string name, unit, remName;
	int quant;
	double price;

	do
	{
		displayMenu();
		choice = inputValid();

		while ((choice < 1) || (choice > 4))
		{
			cout << "That is not a valid integer. Please enter an integer between 1 and 4." << endl << endl;
			choice = inputValid();
		}

		if (choice != 4)
		{
			switch (choice)
			{
				//Add items to the list
			case 1:
				cout << "Please enter the following criteria:" << endl;
				cout << "Name of product, unit (e.g. can, box, pound, etc.), "
					<< "quantity to buy, and the unit price. Then hit enter." << endl;
				cout << "Name: ";
				cin >> name;
				cout << endl << "Unit: ";
				cin >> unit;
				cout << endl << "Quantity: ";
				cin >> quant;
				cout << endl << "Unit Price: ";
				cin >> price;

				addItems(name, unit, quant, price);
				cout << endl << endl;
				break;

				//Remove Items from the list
			case 2:
				cout << "Please type the name of the item you would like to remove from the list." << endl;
				cin >> remName;

				remItems(remName);
				break;

				//Display the list
			case 3:
				displayList();
				total = 0.0;
				break;
			}
		}
	} while (choice != 4);
}

/******************************************************
					List::inputValid
Description: Validates user input for the menu
*******************************************************/
int List::inputValid()
{
	int input;
	cin >> input;

	while (cin.fail())
	{
		cout << "That is not a valid input.  Please input a positive integer." << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> input;
	}

	return input;
}


/******************************************************
						List::resize
Description: Transfers the array to a new one and
deletes the old one. Modified from 
"http://www.cplusplus.com/forum/general/11111/"
*******************************************************/
void List::resize()
{
	capacity *= 2;

	//Create new array and copy items from first to second
	Item *itemList1 = new Item[capacity];

	for (int i = 0; i < currentSize; i++)
	{
		itemList1[i] = itemList[i];
	}

	/*for (int i = currentSize; i < capacity; i++)
	{
		itemList1[i] = Item();
	}*/

	delete[] itemList;

	itemList = itemList1;

	itemList1 = nullptr;
}
/******************************************************
						List::~List
Description: Deconstructor for list class
*******************************************************/
List::~List()
{
	delete[] itemList;
	itemList = NULL;
}
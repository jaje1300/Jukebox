//File created on 04/22/2015 10:50 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Header with class declaration for Menu.cpp
// Name: Menu.h
#ifndef MENU_H
#define MENU_H

#include "Main.h"
#include "MenuItem.h"

class Menu
{
private:
	vector<MenuItem> menuItem;
	string menuHeading;
public:
	//const & dest
	Menu();
	Menu(vector<MenuItem> pMenuItem, string pMenuHeading);
	~Menu();
	//get & set
	vector<MenuItem> getMenuItem()const{ return menuItem; }
	string getMenuHeading()const{ return menuHeading; }
	bool getEnabled(const string menuText);
	void setMenuItem(const vector<MenuItem> pMenuItem);
	void setMenuHeading(const string pMenuHeading);
	void setEnabled(const string menuText, const bool enabled);
	//member functions
	void addItem(const string menuText, const bool enabled);
	void printMenuItems()const;
	char getMenuchoice()const;
};


#endif
//***************************************************************************************************************************************************************************************


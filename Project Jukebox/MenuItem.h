//File created on 04/22/2015 11:00 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Header with class declaration for MenuItem.cpp
// Name: MenuItem.h
#ifndef MENUITEM_H
#define MENUITEM_H

#include "Main.h"

class MenuItem
{
private:
	string menuText;
	bool enabled;
public:
	//const & dest
	MenuItem();
	MenuItem(string pMenuText, bool pEnabled);
	~MenuItem();
	//set & get
	string getMenuText()const{ return menuText; }
	bool getEnabled()const{ return enabled; }
	void setMenuText(const string pMenuText);
	void setEnabled(const bool pEnabled);
};


#endif
//***************************************************************************************************************************************************************************************

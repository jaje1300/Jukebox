//File created on 04/22/2015 11:00 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Implementation with definitions for MenuItem.h
// Name: MenuItem.cpp
#include "MenuItem.h"

//***************************************************************************************************************************************************************************************
//Constructors & destructor
//***************************************************************************************************************************************************************************************
//
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: MenuItem
//Task: Default constructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MenuItem::MenuItem()
{
	menuText;
	enabled = false;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: MenuItem
//Task: Initiate data members
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MenuItem::MenuItem(string pMenuText, bool pEnabled){
	menuText = pMenuText;
	enabled = pEnabled;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: ~Menu
//Task: Destructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MenuItem::~MenuItem()
{
}

//***************************************************************************************************************************************************************************************
//SET function definitions
//***************************************************************************************************************************************************************************************
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: setMenuText
//Task: Takes string and adds to class element
//Input: string pMenuText
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MenuItem::setMenuText(const string pMenuText){
	menuText = pMenuText;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: setEnabled
//Task: Takes bool value and adds to class element
//Input: bool pEnabled
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void MenuItem::setEnabled(const bool pEnabled){
	enabled = pEnabled;
}
//_______________________________________________________________________________________________________________________________________________________________________________________













//***************************************************************************************************************************************************************************************
//File created on 04/22/2015 09:40 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Implementation with class declaration for time.cpp
// Name: Time.h
#ifndef TIME_H
#define TIME_H

#include "Main.h"

class Time
{
private:
	//datamembers
	int hours;
	int minutes;
	int seconds;
public:
	//const & dest
	Time();
	Time(int pHours, int pMinutes, int pSeconds);
	~Time();
	//get & set
	int getHours() const{ return hours; }
	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }
	void setHours(const int pHours);
	void setMinutes(const int pMinutes);
	void setSeconds(const int pSeconds);
	//overloads
	Time operator+(const Time &time) const;
	bool operator<(const Time &time) const;
	bool operator==(const Time &time) const;


};
//***************************************************************************************************************************************************************************************
//Stand-alone function definitions
//***************************************************************************************************************************************************************************************
//overloads
ostream &operator<<(ostream &os, const Time &time);
istream &operator>>(istream &is, Time &time);


#endif
//***************************************************************************************************************************************************************************************

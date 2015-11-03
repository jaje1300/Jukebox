//File created on 04/22/2015 09:40 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Implementation with definitions for time.h
// Name: Time.cpp

#include "Time.h"

//***************************************************************************************************************************************************************************************
//Constructors & destructor
//***************************************************************************************************************************************************************************************
//
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: Time
//Task: Default constructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: Time
//Task: Initiate data members
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time::Time(int pHours, int pMinutes, int pSeconds)
{
	hours = pHours;
	minutes = pMinutes;
	seconds = pSeconds;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: ~Time
//Task: Destructor
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time::~Time()
{
}
//_______________________________________________________________________________________________________________________________________________________________________________________



//***************************************************************************************************************************************************************************************
//SET function definitions
//***************************************************************************************************************************************************************************************
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: setHours
//Task: Takes int and adds to class element
//Input: int pHours
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Time::setHours(const int pHours){
	hours = pHours;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: setMinutes
//Task: Takes int and adds to class element
//Input: int pMinutes
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Time::setMinutes(const int pMinutes){
	minutes = pMinutes;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: setSeconds
//Task: Takes int and adds to class element
//Input: int pSeconds
//Output: 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Time::setSeconds(const int pSeconds){
	seconds = pSeconds;
}
//_______________________________________________________________________________________________________________________________________________________________________________________


//***************************************************************************************************************************************************************************************
//Overload operator definitions
//***************************************************************************************************************************************************************************************
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator+
//Task: Overload '+' to add time objects together
//Input: const Time &time
//Output: return Time object
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time Time::operator+(const Time &time)const{
	Time sum;

	sum.minutes = minutes + time.minutes;
	sum.hours = hours + time.hours;
	sum.seconds = seconds + time.seconds;		

	//format time
	if (sum.getMinutes() < 60){
	}
	else{
		int mins = sum.getMinutes() % 60;
		sum.setMinutes(mins);
		sum.setHours(sum.getHours() + 1);
	}

	if (sum.getSeconds() < 60){

	}
	else{
		int secs = sum.getSeconds() % 60;
		sum.setSeconds(secs);
		sum.setMinutes(sum.getMinutes() + 1);
	}
	
	return sum;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator<
//Task: Overload '<' to compare size of time objects to eachother
//Input: const Time &time
//Output: return bool value (true if less than)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Time::operator<(const Time &time)const{
	return ((hours * 60 * 60) + (minutes * 60) + seconds) < ((time.hours * 60 * 60) + (time.minutes * 60) + time.seconds);
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator==
//Task: Overload '==' to compare sameness of time objects to eachother
//Input: const Time &time
//Output: return bool value (true if same)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Time::operator==(const Time &time) const{
	return (hours == time.hours) && (minutes == time.minutes) && (seconds == time.seconds);
}
//_______________________________________________________________________________________________________________________________________________________________________________________


//***************************************************************************************************************************************************************************************
//Stand-alone function definitions
//***************************************************************************************************************************************************************************************
//overloads********
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator<<
//Task: Overload '<<' to print time objects together
//Input: ostream &os, const Time &time
//Output: return os
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Time &time){
	int sumInSeconds = 0;
	sumInSeconds = (time.getHours() * 60 * 60) + (time.getMinutes() * 60) + (time.getSeconds());
	os << sumInSeconds;

	return os;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator>>
//Task: Overload '>>' to read elements to file
//Input: istream &is, Time &time
//Output: return is
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
istream &operator>>(istream &is, Time &time){
	int tmpHolder = 0, tmpHours = 0, tmpMinutes = 0, tmpSeconds = 0;
	is >> tmpHolder;

	tmpHours = tmpHolder / 60 / 60;			
	tmpMinutes = (tmpHolder / 60) - (tmpHours * 60);		
	tmpSeconds = tmpHolder % 60;		
	
	time.setHours(tmpHours);
	time.setMinutes(tmpMinutes);
	time.setSeconds(tmpSeconds);

	return is;
}
//_______________________________________________________________________________________________________________________________________________________________________________________





//***************************************************************************************************************************************************************************************

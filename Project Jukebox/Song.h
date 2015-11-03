//File created on 04/22/2015 09:30 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Header with class declaration for song.cpp
// Name: Song.h
#ifndef SONG_H
#define SONG_H

#include "Main.h"
#include "Time.h"

class Song
{
private:
	string title;
	string artist;
	Time time;
public:
	//const & destr
	Song();
	Song(string pTitle, string pArtist, Time pDuration);
	~Song();

	//get & set
	string getTitle() const { return title; }
	string getArtist()const { return artist; }
	Time getTime() const { return time; }
	void setTitle(const string pTitle);
	void setArtist(const string pArtist);
	void setTime(const Time pTime);
	//overloads

};
//***************************************************************************************************************************************************************************************
//Stand-alone function definitions
//***************************************************************************************************************************************************************************************
//overloads
ostream &operator<<(ostream &os, const Song &song);
istream &operator>>(istream &is, Song &song);

#endif
//***************************************************************************************************************************************************************************************


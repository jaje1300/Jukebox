//File created on 04/22/2015 09:55 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Header with class declaration for album.cpp
// Name: Album.h
#ifndef ALBUM_H
#define ALBUM_H

#include "Main.h"
#include "Song.h"

class Album
{
private:
	//data members
	string name;
	vector<Song> songlist;
public:
	//const & dest
	Album();
	Album(string pName, vector<Song> pSonglist);
	~Album();
	//get & set
	string getName()const{ return name; }
	vector<Song> getSonglist()const{ return songlist; }
	void setName(const string pName);
	void setSonglist(const vector<Song> pSonglist);
	//member functions
	void addSong(const Song pSong);
	string getFormatedTime(const Time pTime) const ;
	
	//overloads
	bool operator<(const Album &album) const;

};
//***************************************************************************************************************************************************************************************
//Stand-alone function definitions
//***************************************************************************************************************************************************************************************
//overloads
ostream &operator<<(ostream &os, const Album &album);
istream &operator>>(istream &is, Album &album);
bool compareNames(const Album& lhs, const Album& rhs);

#endif
//***************************************************************************************************************************************************************************************

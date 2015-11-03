//File created on 04/22/2015 10:15 PM
//Author: Jacob J
// Created: 2015-04-22
// Last edited: 2015-04-27
// Description: Header with class declaration for Jukebox.cpp. User interface class.
// Name: Jukebox.h
#ifndef JUKEBOX_H
#define JUKEBOX_H

#include "Main.h"
#include "Album.h"
#include "Menu.h"
#include "Queue.h"

class Jukebox
{
private:
	//data members
	vector<Album> albumList;
	Menu fileMenu, albumAddMenu, albumDelMenu, printMenu, playMenu, runMenu;
	Queue playlist;

	//member functions
	void addAlbum();
	void removeAlbum();
	void file();
	void print();
	void play();
public:
	Jukebox();	
	Jukebox(vector<Album> pAlbumList, Menu pFileMenu, Menu pAlbumAddMenu, Menu pAlbumDelMenu, Menu pPrintMenu, Menu pPlayMenu, Menu pRunMenu, Queue pPlaylist);
	~Jukebox();
	//public run function
	void run();
};


#endif
//***************************************************************************************************************************************************************************************

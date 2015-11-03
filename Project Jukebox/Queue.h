//File created on 04/23/2015 10:30 PM
//Author: Jacob J
// Created: 2015-04-23
// Last edited: 2015-04-27
// Description: Header with class declaration for Queue.cpp
// Name: Queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include "Main.h"
#include "Song.h"

typedef Song Item;
class Node;
class Queue
{
private:
	Song *pointer;																					//pointer to array of Song elements
	int size;																						//arraysize
	Node *first, *last;																				//index first and last
public:
	//const & dest
	Queue() : pointer(new Song[5]), size(0), first(nullptr), last(nullptr) {}						//constructor to initiate data members
	~Queue();
	//member functions
	void enque(const Item pData);
	bool deque(Item &pData);
	//overload
	const Queue &operator=(const Queue &q);
};


#endif
//***************************************************************************************************************************************************************************************

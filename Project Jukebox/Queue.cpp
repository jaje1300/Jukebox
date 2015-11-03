//File created on 04/23/2015 10:30 PM
//Author: Jacob J
// Created: 2015-04-23
// Last edited: 2015-04-27
// Description: Implementation with definitions for Queue.h
// Name: Queue.cpp
#include "Queue.h"

//***************************************************************************************************************************************************************************************
//Class definition Node
//***************************************************************************************************************************************************************************************
// Public datamembers reachable by Queue
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Name: Node 
//Task: Represent node in linked list
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Node
{
public:
	Node *next;
	Item data;
	Node(Node *n, Item newData) : next(n), data(newData) {}
};

//***************************************************************************************************************************************************************************************
//Constructors & destructor
//***************************************************************************************************************************************************************************************
//(Constructor is in Queue.h)
//_______________________________________________________________________________________________________________________________________________________________________________________
//// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Name: ~QList
//Task: Destructor: release allocated memory
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Queue::~Queue()
{
	while (!(first == nullptr)){
		Node *tmp = first;
		first = first->next;
		delete tmp;													
	}
	delete[] pointer;
	pointer = nullptr;
}
//***************************************************************************************************************************************************************************************
//Member function definitions
//***************************************************************************************************************************************************************************************
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: enque
//Task: Add data to last place i que
//Input: Item pData (Song object)
//Output: -
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Queue::enque(const Item pData){
	//if full, increase by five
	if (((size % 5) == 0) && size != 0){												
		Song *tmpPointer = new Song[size+5];								//allocate memory for temporary array of appropriate size
		for (int i = 0; i < size; i++){
			tmpPointer[i] = pointer[i];										//store values in temp
		}
		delete [] pointer;													//release old array memory

		pointer = new Song[size + 5];										//allocate memory for new size
		for (int i = 0; i < size; i++){
			pointer[i] = tmpPointer[i];										//fill back up
		}
		delete [] tmpPointer;													//release temp

	}

	//add Song object to array pointer
	pointer[size] = pData;

	Node *pNew = new Node(0, pData);
	if ((first == nullptr)){
		first = pNew;
	}
	else{
		last->next = pNew;
	}
	last = pNew;
	
	size++;																	//increase size								
	
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: deque
//Task: Remove data from first in que (basically stack pop)
//Input: Item &pData
//Output: bool value (false if empty)
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Queue::deque(Item &pData){
	if ((first == nullptr)){																//if que is empty
		return false;
	}

	Node *n = first;																		//temp pointer pointing at first node
	pData = n->data;																		//return node data through parameter reference
	
	first = first->next;																	//point first at second node
	if ((first == nullptr)) {																// if que becomes empty
		last = nullptr;																			//last needs to point at null
	}
	delete n;																				//release memory from temp
	size--;																					//decrease size

	return true;
}
//_______________________________________________________________________________________________________________________________________________________________________________________
//Name: operator=
//Task: Overload '=' to copy queue object as per request from requirements specification
//Input: const Queue &q
//Output: return this
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
const Queue &Queue::operator=(const Queue &q){
	if (this != &q){
		delete [] pointer;

		//find appropriate array size
		if (!(((q.size % 5) == 0) && q.size != 0)){											//(I'm guessing containers still need to be handled in steps of five)
			int stepsNeeded = 0;
			int stepsOfFive = 5;
			bool foundIt = false;
			do{
				if (q.size < stepsOfFive){
					stepsNeeded = stepsOfFive - q.size;										//if size wasn't divisable by five, these are the amount of steps required to reach it
					foundIt = true;
				}
				else{
					stepsOfFive += 5;
				}
			} while (!foundIt);

			pointer = new Song[q.size + stepsNeeded];										//allocate memory for temporary array of appropriate size
		}
		else{
			pointer = new Song[q.size];														//-
		}
		size = q.size;																		//keep track of how many elements are actually occupied

		//add objects to array and arrange indexes
		for (int i = 0; i < size; i++){
			pointer[i] = q.pointer[i];

			Node *pNew = new Node(0, q.pointer[i]);
			if ((first == nullptr)){
				first = pNew;
			}
			else{
				last->next = pNew;
			}
			last = pNew;
		}
	}

	return *this;
}
//_______________________________________________________________________________________________________________________________________________________________________________________






//***************************************************************************************************************************************************************************************

#ifndef LINKLIST_H
#define LINKLIST_H


#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"

template<class T>

class LinkList
{
public:
	/*CONSTRUCTORS+DESTRUCTOR*/
	LinkList();							//Default Constructors- empty container
	LinkList(LinkList<T>& source);		//Copy Constructor
	~LinkList();						//Destructor
		
	/*OPERATOR OVERLOADS*/
	LinkList<T>& operator=(const LinkList<T>& source);//Assignment Operator

	/*PUBLIC MEMBER FUNCTIONS*/
	void append(T dataIn);							//adds data to end of link list
	void addItem (T dataIn);						//adds data to beginning of link list
	void removeFirst();								//Removes first node of linked list
	void removeNode(T item);						//Removes any given node
	void removeAll();								//Clear all items from linked list
	bool isEmpty();									//returns true if linkedlist is empty
	void printForwards();							//prints linked list forward
	void printBackwards() { printBackwards(first); }//calls private function
	bool readFile(std::string fileName);			//Read from csv and insert into linked list
	bool writeFile(std::string fileName);			//Write from linked list into csv
	int getItemCount();								//Returns number of nodes/items in linked list
	T getRandomItem();								//Gets a randon node, returns the data and deletes the node
	
private:
	/*PRIVATE DATA MEMBERS*/
	Node<T>* first;		//Head pointer
	Node<T>* last;		//Tail pointer
		
	/*PRIVATE MEMBER FUNCTIONS*/
	Node<T>* alloc(T dataIn);									//Allocates new memory for a new node
	void free();												//free memory on heap
	void printBackwards(Node<T>* cursor);						//prints linked list backwards
	Node<T>* findNode(T item);									//Finds node and Returns pointer to given node
};

#include "LinkList.template"

#endif
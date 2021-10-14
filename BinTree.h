#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
#include "BinNode.h"
#include "Question.h"

template<class T>

class BinTree
{
public:
	BinTree();														//Default Constructor
	BinTree(const BinTree<T>& source);								//Copy Constructor
	BinTree<T>& operator=(const BinTree<T>&source);					//Assignment Operator
	~BinTree();														//Destructor
	
	void Add(T dataIn);												//This function adds a new node to the Binary Tree
	void Print();													//Prints all nodes of binary tree in order
	void WriteFile(std::string fileName);							//Writes data to csv file
	bool ReadFile(std::string fileName);							//Reads data from csv file to fill binary tree
	int CountItems();												//Counts number of nodes in binary tree and returns count
	void inOrderTraversal(int, void process(T, int&, int&));		//Traverses binary tree in order and completes specified process

private:
	BinNode<T>* root;												//Pointer to first node in tree
	BinNode<T>* alloc(T dataIn);									//Allocates new memory for additional nodes
	void free(BinNode<T>* cursor);									//frees all nodes from Binary tree
	void print(BinNode<T>* cursor);									//Prints all nodes of tree
	void copyTree(BinNode<T>* cursor);								//Copys tree into new tree
	void inOrderTraversal(int& count1, int& count2, void process(T, int&, int&), BinNode<T>* cursor); 
	void writeFile(BinNode<T>* cursor, std::ofstream& ofs);			//Writes tree data to csv file
	int countItems(BinNode<T>* cursor);								//Counts number of nodes in tree
};

#include "BinTree.template"

#endif
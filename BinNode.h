#ifndef BINNODE_H
#define BINNODE_H

#include <iostream>
#include <string>

template<class T>

class BinNode
{
	template <class T>
	friend class BinTree;  //friend class BinTree;

public:

	//CONSTRUCTORS
	BinNode();			//default constructor
	BinNode(T dataIn);  //


	//DATA MEMEBERS
	T data;
	BinNode<T>* leftLink;
	BinNode<T>* rightLink;


private:
	
	

};

#include "BinNode.template"

#endif
#ifndef NODE_H
#define NODE_H

template <class T>

class Node
{
public:

	Node();
	Node(T dataIn);

	//DATA MEMBERS
	T data;
	Node<T>* next;

};

#include "Node.template"

#endif
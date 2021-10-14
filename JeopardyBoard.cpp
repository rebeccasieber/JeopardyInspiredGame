/*
FinalJeopardy
Rebecca Sieber
CSC161-470
4/16/21
Project #5. JEOPARDY BOARD. With help from provided HTLM files, This program creates a jeopardy
board visual in an internet brower with 6 randomly chosen categories (from a pool of 21 potential CSV files). This program
allows the user/player choose questions from the board, guess the correct answer, and then reveal the correct answer.
*/

#include <iostream>									// istream & ostream
#include <string>									// string class
#include "Field.h"									// Field class that inherits from std::string
#include "Question.h"									// Question class
#include "LinkList.h"									// List template ordered container class
#include "BinNode.h"									// BinNode class- friends with Bintree 
#include "BinTree.h"									//Bintree data structure template
#include "HTMLfunc.h"									//forms visual Jeopardy board in web browser

int main()
{
	/*VARIABLES*/
	BinTree<Question> questions1;							//Creating binary tree of Questions object for cat1
	BinTree<Question> questions2;							//Creating binary tree of Questions object for cat2
	BinTree<Question> questions3;							//Creating binary tree of Questions object for cat3	
	BinTree<Question> questions4;							//Creating binary tree of Questions object for cat4
	BinTree<Question> questions5;							//Creating binary tree of Questions object for cat5
	BinTree<Question> questions6;							//Creating binary tree of Questions object for cat6
	LinkList<std::string> categories;						//Creating linked list of string objects

	/*The array below holds names of all potential category files. 6 files to be chosen at random per game*/
	std::string potCategories [22] = {"Astronomy.csv","Audio.csv","Biking.csv","biology.csv",
		"Cars.csv", "compsci.csv", "Computers.csv","games.csv","Geography.csv","Instruments.csv",
		"Linux.csv","movies.csv","random.csv","RhymesWithMost.csv","Sea Creatures.csv","StateMottos.csv",
		"swimming.csv","Television.csv","TheExpanse.csv","Video-Games.csv","videogames.csv","woodworking.csv"};	
	
	std::string randCategories[6];							//1d array that holds 6 categories chosen randomly from array above

for (int i = 0; i<22; i++)						
	{	
		categories.append(potCategories[i]);					//loading all elements of potCategories array into linked list
	}

for (int i = 0; i < 6; i++)
{
	randCategories[i] = categories.getRandomItem();					//loading 6 random elements (strings) from categories list 
}											//into array randCategories

questions1.ReadFile(randCategories[0]);							//reading rand cat 1 into binary tree
questions2.ReadFile(randCategories[1]);							//reading rand cat 2  into binary tree
questions3.ReadFile(randCategories[2]);							//reading rand cat 3 into binary tree
questions4.ReadFile(randCategories[3]);							//reading rand cat 4 into binary tree
questions5.ReadFile(randCategories[4]);							//reading rand cat 5 into binary tree
questions6.ReadFile(randCategories[5]);							//reading rand cat 6 into binary tree

printHTMLindex(randCategories);								//passing in the array of category names to HTLM file
printHTMLpages(questions1, 1);								//pass in the BinTree collection of Questions and the category counter 1 - 6 
printHTMLpages(questions2, 2);
printHTMLpages(questions3, 3);
printHTMLpages(questions4, 4);
printHTMLpages(questions5, 5);
printHTMLpages(questions6, 6);
system("index.htm");									// this will open the index.htm page in the default browser to display the game

	return 0;
}


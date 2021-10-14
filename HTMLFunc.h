/*
Julie Schneider - Faculty RRCC - Fall 2019
CSC 161 Backwards Jeopardy Game
*/

#ifndef HTMLFUNC_H
#define HTMLFUNC_H

#define CRT_SECURE_NO_WARNINGS
#define CRT_NONSTDC_NO_WARNINGS
#define NO_CRT_STDIO_INLINE

#include	<fstream>		// ifstream & ofstream
#include	<iostream>		// istream & ostream
#include	<cstdio>		// sprintf_s
#include	<stdio.h>		// C sprintf_s
#include 	<string>		// C++ string class
#include	<string.h>		// C-style string
#include	<cstdlib>

#include	"BinTree.h"
#include	"Question.h"

void	printHTMLindex(std::string categories[]);

// Takes binary tree of Question objects and prints the HTML page for each Question.

void	printHTMLpages(BinTree<Question> questionSet, int catCount);

// Takes an Question and prints an HTML page.

void	printHTMLpage(Question item, int& catCount, int& score);

// Misc HTML functions helper functions

void	printHTMLhead(std::ofstream &os, std::string title);
void	printHTMLcontent(std::ofstream& os, std::string categories[]);
void	printHTMLend(std::ofstream &os);


#endif
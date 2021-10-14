//This is a child class to the string class. It includes added functionality to the stringclass
//by allowing for conversion of all characters in a string/field to upper and lowercase,
//it allows for a long string/field to be split into smaller strings/fields based on a delimiter,
//finally it allows string comparison that is not case sensitive.

#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

class Field : public std::string
{
public:
	//CONSTRUCTORS
	Field();														//default constructor
	Field(const Field& fld);										//copy constructor
	Field(const std::string& fld, size_t pos, size_t len = npos);	//substring
	Field(const char* s);											//from c-string
	Field(const char* s, size_t n);									//from sequence
	Field(size_t n, char c);										//fill in a char

	~Field();														//destructor

	//MEMBER FUNCTIONS
	Field strToUpper();												//converts a field object to all uppercase
	Field strToLower();												//converts a field object to all lowercase
	int compareIgnoreCase(const Field& fld);						// Compares 2 strings (non case sensitive) and returns 0, -1, or, 1  
	Field* split(char delimiter = ',');								//this function creates a dynamic array of Field objects based upon the delimiter and populates the array by splitting the Field
	//Field subfld(int start, int end);								//extracting subfields from a field based on start and end index
	
	//OVERLOADED OPERATORS
	friend std::istream& operator>>(std::istream& is, Field& fld);		//imports Field data from keyboard
	friend std::ifstream& operator>>(std::ifstream& iFS, Field& fld);	//imports Field data from CSV file

private: 
	Field* splitData; //pointer for splitting a field into array of subfields via delimiter
	//int arraySize;
};

#endif 
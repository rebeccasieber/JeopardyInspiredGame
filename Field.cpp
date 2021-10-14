#include "Field.h"											//field header file

Field::Field() : std::string()								//default constructorr inherited from string class
{
	splitData = nullptr;									//initializing pointer to nullptr
	//arraySize = 0;
}
Field::Field(const Field& fld)								 //copy constructor inherited from string class
	: std::string(fld)
{
	splitData = nullptr;									//initializing pointer to nullptr
	//arraySize = 0;
}
Field::Field(const std::string& str, size_t pos, size_t len) //substring inherited from string class
	: std::string(str, pos, len)
{
	splitData = nullptr;									//initializing pointer to nullptr
	//arraySize = 0;
}
Field::Field(const char* s)									//from c-string inherited from string class
	: std::string(s)
{
	splitData = nullptr;									//initializing pointer to nullptr
	//arraySize = 0;
}
Field::Field(const char* s, size_t n)						//from sequence inherited from string class
	: std::string(s)
{
	splitData = nullptr;									//initializing pointer to nullptr
}
Field::Field(size_t n, char c)								//fill in a char inherited from string class
	: std::string(n, c)
{
	splitData = nullptr;									//initializing pointer to nullptr
}

	
Field::~Field()												//Destructor
{
	if (splitData != nullptr)								//checking to see if its already empty, in which case we do not need to destroy it
	{
		delete[] splitData;									//destroying splitData memory from heap
		splitData = nullptr;								//reseting pointer to null so it doesnt dingle-dangle
	}
}

//OPERATOR OVERLOADS

/*Istream Overloading >> operator reads from keyboard until the enter key or newline*/
std::istream& operator>>(std::istream& is, Field& fld) 
{
	if (is.peek() == '\n')					// check to make sure a newline (enter key) exists
		is.ignore();						// from previous input cin >> ...; was not left
	std::getline(is, fld, '\n');			//extracts from keyboard up to newline <enter>
	return is;								//returning extracted data
}

//ifstream Overloading >> operator reads until a comma
std::ifstream& operator>>(std::ifstream& iFS, Field& fld)
{
	if (iFS.peek() == '\n')					//check to make sure a newline (enter key) exists
		iFS.ignore(1);						//ignoring single character newline
	std::getline(iFS, fld, ',');			//extracting line from fld up to first comma delimiter
	return iFS;								//returning extracted line
}

//MEMBER FUNCTIONS

/*This function converts a field object to all uppercase characters*/
Field Field::strToUpper() 
{
	Field fld = *this;						//this pointer that points to object used to call function
	for (int i = 0; i < fld.length(); i++)  //looping thru field char array from 0 to end
	{
		char c = fld[i];					//extracting char from field array @ index i
		fld[i] = toupper(c);				//converting character at idex i to upper case and putting back into array
	}
		return fld;							//returning new uppercase field
}

/*This function converts a field object to all lowercase characters*/
Field Field::strToLower()
{
	Field fld = *this;						//this pointer that points to object used to call function
	for (int i = 0; i < fld.length(); i++)  //extracting char from field array @ index i
	{
		char c = fld[i];					//extracting char from field array @ index i
		fld[i] = tolower(c);				//converting character at index i to upper case and putting back into array
	}

	return fld;								//returning new lowercase field
}

/* This function compares 2 strings (not case sensitive). It returns 
0 if the strings are equal (the same), 
-1 if the first is less than the second and 
1 if the first is greater than the second */


int Field::compareIgnoreCase(const Field& fld) 
{
	Field str2 = fld;									//creating temp variable so I dont accidentally change variable inside this function;
	Field str1 = *this;									//pointer to object being used to call function

	str2 = str2.strToUpper();							//converting temp variables to uppercase to be able to ignore case in comparison below
	str1 = str1.strToUpper();							//converting temp variables to uppercase to be able to ignore case in comparison below

	//if (str1.compare(str2) == 0) { return 0;}			//REDUNDANT First string and second string are equal

	//else if (str1.compare(str2) < 0)  {return -1;}	//REDUNDANT first field string is less than the second field string

	return str1.compare(str2);							//first field string is greater than the second field string
}


/*This function creates a dynamic array of Field objects. It populates 
the array by splitting the Field into various subfields (based on a delimiter) 
and placing them back into the original field.*/

Field* Field::split(char delimiter)
{
	Field fld = *this;								//pointer to object being used to call function 

	int used = 0;									//initializing used to 0- it will increment in while loop
	int max = 1;									//to be used for array below
	int endIndex = fld.find(delimiter);				//finds first delimiter and logs index of delimiter into endIndex variable

	while (endIndex != std::string::npos)			//while the endIndex still exists in the field
	{
	Field* tmp = new Field[++max];					//creating temp to hold fields data
	std::copy(splitData, splitData + used, tmp);	//copying entire spltData into tmp 
	delete[] splitData;								//emptying splitData so it can be filled with subfields
	splitData = tmp;								//Setting fields to point to tmp
	splitData[used++] = Field(fld, 0, endIndex);	//Puttiong data into array up to delimiter
	fld.erase(0, endIndex + 1);						//erasing first sub field was already extracted
	endIndex = fld.find(delimiter);					//resetting end index to next delimiter
	}
		
	splitData[used++] = Field(fld, 0);				//Adding last item since there typically wont be a comma at the very end of a string
													//and the while loop will not extract the last subfield due to the lack of comma
	return splitData;
	
}


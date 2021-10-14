/*
Julie Schneider - Faculty RRCC - Fall 2019
Backwards Jeopardy Game
*/

#include "HTMLFunc.h"

// Global file object so that it doesn't have to be passed around
// to each function in order to create the HTML files

std::ofstream	htmlIndex;

/*
* Function: printHTMLindex(std::string categories[])
*
* This function takes the a 1D array of string objects representing
* the names of the categories that were read from the 6 category files
* and generates the HTML index page for the Backwards Jeopardy Game. The index
* is in the file index.htm.
*
* Parameters:
*
*	categories	- the 1D array of category names as strings
*
* Returns:
*
* NONE
*
*/

void	printHTMLindex(std::string categories[])
{
	htmlIndex.open("index.htm");
	printHTMLhead(htmlIndex, "Jeopardy CSC161 Game");
	printHTMLcontent(htmlIndex, categories);
	printHTMLend(htmlIndex);
	htmlIndex.close();
}



/*
* Function: printHTMLpages(BinTree<Question> questionSet, int catCount)
*
* This function takes the questionSet (which is a binary tree collection)
* and generates the HTML pages for each of the individual Question objects in the tree.
*
* This function uses the inOrderTraverse() member function of the
* binary tree template code to generate the individual HTML pages. It passes
* the stand-alone function printHTMLpage() to actually generate each page.
*
* Parameters:
*
*	questionSet	- the binary tree data structure of question objects
*	catCount	- the category number 1-6
*
* Returns:
*
* NONE
*
*/

void	printHTMLpages(BinTree<Question> questionSet, int catCount)
{
	questionSet.inOrderTraversal(catCount, printHTMLpage);
}

/*
* Function: printHTMLpage(Question item, int& catCount, int& score)
*
* This function takes an item entry and generates the HTML
* page assocated with each Question object.  The file for the page is named
* cat#_N00.htm, where # is the category counter (1-6) and where N is the score (100-500).
*
*
* Parameters:
*
*	item	- the item entry as a Question object
*	catCount - the category counter 1-6
*	score	 - the score of the question 100-500
*
*	catCount and score are used to generate a unique HTML file reference
*
* Returns:
*
* NONE
*
*/

void	printHTMLpage(Question item, int& catCount, int& score)
{
	char		fileName[18];
	std::ofstream	htmlPage;
	std::string		title;

	sprintf_s(fileName, "cat%d_%d00.htm", catCount, score);

	htmlPage.open(fileName);
	if (!htmlPage)
	{
		std::cout << "Unable to write HTML page: " << fileName << "\n";
		return;
	}

	title = item.getCategory();
	printHTMLhead(htmlPage, title);

	// Here's the formatted item

	htmlPage << "<h2 align=\"center\">CATEGORY: " << item.getCategory() << "</h2>\n";
	htmlPage << "<h3 align=\"center\">Question: " << item.getQuestion() << "</h3>\n";
	htmlPage << "<p align=\"center\">Click "
		<< "<a onclick = \"showDiv();return false\">HERE</a>"
		<< " to Show/Hide answer</p>\n";
	htmlPage << "<div id=\"ANS\" style=\"display: none;\" align=\"center\">"
		<< "Answer: " << item.getAnswer() << "</div>";

	htmlPage << "\n<p align=\"center\"><a href=\"#\" onclick=\"history.go(-1)\">Go Back</a><\p>\n\n";

	printHTMLend(htmlPage);
	htmlPage.close();
}

// This function prints the required HTML code to start an HTML page

void		printHTMLhead(std::ofstream& os, std::string title)
{
	std::string	pageTitle;

	if (title == "")
		pageTitle = "HTML Page";
	else
		pageTitle = title;

	os << "<html>\n<head>\n<title>" << pageTitle << "</title>\n";
	os << "<script type = 'text/javascript'>\n"
		<< "function askQuestion(cell) {\n"
		<< "\tcell.style.backgroundColor = '#000000';\n"
		<< "}\n"
		<< "function showDiv() {\n"
		<< "\tvar x = document.getElementById(\"ANS\");\n"
		<< "\tif (x.style.display === \"none\") {\n"
		<< "\t\tx.style.display = \"block\";\n"
		<< "\t}\n"
		<< "\telse {\n"
		<< "\t\tx.style.display = \"none\";\n"
		<< "\t}\n"
		<< "}\n"
		<< "</script></head>" << "\n<body bgColor='#FFFFFF'>\n";
}

// This function prints the HTML code for the content of the index.htm HTML page

void	printHTMLcontent(std::ofstream& os, std::string categories[])
{
	os << "\n<h1 align = \"center\">Backwards Jeopardy Game</h1>"
		<< "\n<p align = \"center\">"
		<< "\n<table border = \"1\" cellpadding = \"20\" cellspacing = \"20\">"
		<< "\n<tr>";
	os << "\n<td align = \"center\">" << categories[0] << "</td>"
		<< "\n<td align = \"center\">" << categories[1] << "</td>"
		<< "\n<td align = \"center\">" << categories[2] << "</td>"
		<< "\n<td align = \"center\">" << categories[3] << "</td>"
		<< "\n<td align = \"center\">" << categories[4] << "</td>"
		<< "\n<td align = \"center\">" << categories[5] << "</td>"
		<< "\n</tr>" << "\n<tr>";
	os << "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat1_100.htm\">100</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat2_100.htm\">100</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat3_100.htm\">100</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat4_100.htm\">100</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat5_100.htm\">100</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat6_100.htm\">100</a></td>"
		<< "\n</tr>" << "\n<tr>";
	os << "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat1_200.htm\">200</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat2_200.htm\">200</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat3_200.htm\">200</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat4_200.htm\">200</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat5_200.htm\">200</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat6_200.htm\">200</a></td>"
		<< "\n</tr>" << "\n<tr>";
	os << "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat1_300.htm\">300</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat2_300.htm\">300</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat3_300.htm\">300</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat4_300.htm\">300</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat5_300.htm\">300</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat6_300.htm\">300</a></td>"
		<< "\n</tr>" << "\n<tr>";
	os << "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat1_400.htm\">400</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat2_400.htm\">400</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat3_400.htm\">400</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat4_400.htm\">400</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat5_400.htm\">400</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat6_400.htm\">400</a></td>"
		<< "\n</tr>" << "\n<tr>";
	os << "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat1_500.htm\">500</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat2_500.htm\">500</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat3_500.htm\">500</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat4_500.htm\">500</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat5_500.htm\">500</a></td>"
		<< "\n<td align = \"center\" onclick = \"askQuestion(this);\"><a href = \"cat6_500.htm\">500</a></td>"
		<< "\n</tr>" << "\n</table>"
		<< "\n</p>";
}
// This function prints the required HTML code to end an HTML page

void		printHTMLend(std::ofstream& os)
{
	os << "</body>\n</html>\n";
}
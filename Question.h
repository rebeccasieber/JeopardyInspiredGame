/*
author: Julie Schneider 3/2020

Question class declaration header

Question has private data members of:
category as a string
question as a string
answer as a string
points as an int
status as a bool indicating if the question has been asked or not

Two Question objects are compared upon their score, only if their
categories are the same.
*/

#ifndef QUESTION_H			// macro guard
#define QUESTION_H

#include <iostream>
#include <fstream>
#include <string>

#include "Field.h"

class Question
{
public:
	// Constructor - default parameters 
	// Question() default constructor - no arguments
	// Question(std::string categoryIn) 
	// Question(std::string category, std::string question)
	// Question(std::string category, std::string question, std::string ans)
	Question(Field catIn = "CAT",
		Field quest = "QUEST",
		Field ans = "ANS");

	// Accessor member functions
	Field getCategory() const { return category; }
	Field getQuestion() const { return question; }
	Field getAnswer() const { return answer; }
	int getPoints() const { return points; }
	bool getQuestionStatus() const { return status; }

	// Modifier member functions
	void setCategory(Field cat) { category = cat; }
	void setQuestion(Field quest) { question = quest; }
	void setAnswer(Field ans) { answer = ans; }
	void setPoints(int pointIn) { points = pointIn; }
	void askQuestion() { status = true; }
	void resetQuestionStatus() { status = false; }

	// Other member functions
	std::string toString() const;
	std::string toFileString() const;

	// stream operator functions
	friend std::istream& operator>>(std::istream& is, Question& q);
	friend std::ifstream& operator>>(std::ifstream& ifs, Question& q);
	friend std::ostream& operator<<(std::ostream& os, const Question& q);
	friend std::ofstream& operator<<(std::ofstream& ofs, const Question& q);

	// relational operator functions
	friend bool operator==(const Question& q1, const Question& q2);
	friend bool operator!=(const Question& q1, const Question& q2);
	friend bool operator>=(const Question& q1, const Question& q2);
	friend bool operator<=(const Question& q1, const Question& q2);
	friend bool operator>(const Question& q1, const Question& q2);
	friend bool operator<(const Question& q1, const Question& q2);

private:
	// private data members / fields
	Field category;
	Field question;
	Field answer;
	int points;
	bool status;
};

#endif

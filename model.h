#pragma once
#include <string>
#include <iostream>
using namespace std;
class model
{
	string underscore; 
	string answer=""; //empty string for the answer to replace
	string Word; 
	string WordList[20];

	int tries = 5; //User has 5 tries
	
	bool correct_letter = false;
	bool replace = false;
	bool finish = false;

public:

	void GetLetter(); //Method for generating random words and underscores
	void CheckLetter(char tWhat); //Check for correct letter

	int GetTries(); //Count the tries and return
	
	string Append(); //Convert letter to underscore 
	string CurrentDisplay(); //Display current status
	string AnswerDisplay(); //Display the answer

	bool correct(); 
	bool ReturnFinish();

};


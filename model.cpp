#include "model.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
void model::GetLetter() { //Method for generating random words and reading txt file
	srand(time(NULL));
	ifstream randomword;
	randomword.open("wordlist.txt");
	if (randomword.fail())
	{
		exit(1);
		randomword.clear();
	}
	   for (int i = 0; i < 20; i++) { //Loop through all words to read in txt file
		 getline(randomword,WordList[i]); //Reading words with space
	                                }
							     
    int random = rand() % 21; 
	Word = WordList[random]; //Store a random word in that list
	randomword.close(); //close file
	                     }

string model::Append() { //Method to insert underscores in the empty string for later replacing
	for (int i = 0; i < Word.size(); i++) { //Replace word by word
		if (Word[i] == ' ') { //If found the space in the word
			answer.append(" "); //Then forget about undersocre, we'll add space instead
		                    }
		else { //If we don't find space then just add underscore like normal
			answer.append("-");    //Convert to underscore
		     }
	                                	
	                                      }
	return answer;
                        }

void model::CheckLetter(char tWhat) { //Method to check the guess vs the word
			int pos = Word.find(tWhat); //find the position in word
			while (pos != -1) { 
				answer.replace(pos, 1, 1, tWhat); //replace word found in that position
				pos = Word.find(tWhat, pos + 1); //Move on other position
				
			                   }
			for (int i = 0; i < Word.length(); i++) { ///loop to check if the word matches
				if (Word[i] != tWhat) { //If they don't then...
					correct_letter = false; //not correct
					finish = false; //haven't finished program
									  }
				
				 if (Word[i] == tWhat) { //If they do then...
				 correct_letter = true; //correct
				 break; //break here cause we when got the found, we don't have to care the rest 
									   }
							                               
	                                                }
			if (correct_letter == false) { //If user guess wrong then they lose 1 try
				tries--;
			}
			
			if (answer == Word) { //If all of the letter guessed matches the answer
				finish = true; //Finish the program
				
			                    }
		
									   }

string model::CurrentDisplay() { //Method to display the replacement of underscores and letters 
	return answer;
							   }
string model::AnswerDisplay() { //Display answer
	return Word;
							  }
bool model::correct() { //If the word is corrected send it back to the View to check true or false
	return correct_letter;
					  }
bool model::ReturnFinish() { //Method for determining whether the program finished or not
	return finish;
						   }
int model::GetTries() { //Method for returning the tries back to the view to count
	return tries;
					  }


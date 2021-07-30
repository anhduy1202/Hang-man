// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "View.h"
#include "model.h"
using namespace std;
int main()
{
	char letter;
	bool restart = false; //boolean value for restarting the game
	bool again = true; //boolean value for repeating the input letter from user
	char input; //Get the quit or restart input
	
	while (again == true) { 
		cout << "Press y for restart q for quit \n"; //Condition for restarting or quit the game
		cin >> input;
		if (input == 'y' || input == 'Y') { //Choose restart
			again = true;
		}
		if (input == 'q' || input == 'Q') { //Choose quit
			again = false;
		}
		if (again == false) { //Exit the game if quit
			break;
		}
		system("cls"); //clear the console screen for restart
		model* tAModel = new model; 
		View* tAView = new View(tAModel);
		//DISPLAY PROMPT
		cout << "	HANGMAN           " << endl;
		cout << "By Quoc Anh Duy Truong" << endl;
		cout << endl;
		cout << "|======================| " << endl;
		cout << "|======================| " << endl;
		cout << "|______________________| " << endl;
		cout << "|______________________|" << endl;
		cout << "|______________________|" << endl;
		cout << "|______________________|" << endl;
		cout << "|______________________|" << endl;
		cout << "|______________________|" << endl;
		cout << "|______________________|" << endl << endl;
		tAView->Start(); //Call start method from view to get the rendom word
		
		do { //Loop for input each letter

			cout << "\n GUESS YOUR LETTER \n";
			cin >> letter;
			tAView->OnKeypress(letter); //Send letter input to the View
			if (tAView->Restart() == true) { //Call Restart method from View when user win or lose, they'll decide to quit or restart the game 
				restart = true;
			}
			else {
				restart = false;
			}
		} while (restart);

	} 
	cout << "THANKS FOR PLAYING MY FINAL PROJECT \n";
	return 0;
	
	
	
}
//cout << "|======================| " << endl;
//cout << "|======================| " << endl;
//cout << "|___________|__________| " << endl;
//cout << "|___________|__________|" << endl;
//cout << "|_________#_0_#________|" << endl;
//cout << "|__________#|#_________|" << endl;
//cout << "|___________|__________|" << endl;
//cout << "|__________#_#_________|" << endl;
//cout << "|_________#___#________|" << endl;

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

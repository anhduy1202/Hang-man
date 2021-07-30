#include "View.h"
#include "model.h"
#include <iostream>
using namespace std;
 View::View(model* tModel)
{
	mMymodel = tModel;
}
 void View::Start() //Method to receive data from main input
 {
	 mMymodel->GetLetter(); //Method from Model to read file and get random words
	 string answer = mMymodel->Append(); //store underscores length
	 cout <<"YOUR WORD: "<< answer << " " << endl; //Display underscores
 }
 bool View::Restart()  // restart and quit method
 {
	 return again;
 }

 void View::OnKeypress(char tWhat) //Method that get char input from main() as value
 {
	    
		 mMymodel->CheckLetter(tWhat); //Call method in Model to check if user's guess match the letter
		 
		 if (mMymodel->correct() == true) //If it matches
		 { 
			 cout << tWhat << " is one of the correct letter \n";
			 cout << mMymodel->CurrentDisplay() << " " << endl; //Display the replacement
		 }
		
		 if (mMymodel->correct() == false) //Doesn't match
		 { 
			 cout << "You got it wrong \n";
			 cout << mMymodel->CurrentDisplay() << " " << endl; //Display the original
			 //tries--; //You lost one try
		 }
		 if (mMymodel->ReturnFinish() == true) 
		 {
			 cout << "YOU WON \n"; //If user finish the game, they got all correct
			 cout <<"THE WORD WAS: "<< mMymodel->CurrentDisplay() << " " << endl; //Display the word
			 again = false; //Call back to main to restart or quit the game
		 }
		 switch (mMymodel->GetTries()) //ASCII drawing + Call the get tries method to count the tries
		 {
			 
			
		 case 4:
		 {
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|___________|__________| " << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 break;
		 }
		 case 3: 
		 {
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|___________|__________| " << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|___________0__________|" << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 break;
		 }
		 case 2:
		 {
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|___________|__________| " << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|___________0_#________|" << endl;
			 cout << "|___________|#_________|" << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 break;
		 }
		 case 1:
		 {
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|___________|__________| " << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|_________#_0_#________|" << endl;
			 cout << "|__________#|#_________|" << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 break;
		 }
		 case 0: 
		 {
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|___________|__________| " << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|_________#_0_#________|" << endl;
			 cout << "|__________#|#_________|" << endl;
			 cout << "|___________|__________|" << endl;
			 cout << "|__________#_#_________|" << endl;
			 cout << "|_________#___#________|" << endl;
			 cout << "\n YOU LOSE, THE WORD IS " << mMymodel->AnswerDisplay() << " \n"; 
			 again = false; //Exit to main to restart or quit
			
			 break;
		 }
		
		 default: //If user guess correctly at the first time then print out the defult shape of the game
			 cout << "|======================| " << endl;
			 cout << "|======================| " << endl;
			 cout << "|______________________| " << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl;
			 cout << "|______________________|" << endl << endl;
		 }
}
	 
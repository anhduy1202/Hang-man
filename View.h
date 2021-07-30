#pragma once

class model;
class View
{
	model* mMymodel;
	bool again = true; //boolean value to restart/quit when win or lose
	

public:
	View(model* tmodel);
	bool Restart(); //Method for restart the game
	void Start(); //Method to get the word
	void OnKeypress(char tWhat); //Method to receive data from main input
	
};



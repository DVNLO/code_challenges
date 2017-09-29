/*This programm finds the number a person has 
guessed within the bounds 1-100.
Orignial prompt from Bjarne Stroustrup's book
Programming Principles and Practice. 
Author: Dan Vyenielo
Date: 9/11/2017*/
#include "stdafx.h"
#include <iostream>
using namespace std;

constexpr int UPPER_LIMIT = 100;

void prompt_user() {
	cout << "Guess a number between 1 and " << UPPER_LIMIT << '.' << endl;
}

/*Shower thought greather than, less than, equal to?*/

//Ahhh this is terrible.
void determine_player_guess() {
	bool correct_guess = false;
	int midpoint = UPPER_LIMIT / 2, lower_limit = 1, upper_limit = UPPER_LIMIT;
	char response;
	cout << "Respond yes (Y) or no (N) to the following sequence of questions." << endl;
	while (!correct_guess) {
		cout << "Is your number greater than or equal to " << midpoint << '?' << endl;
		cin >> response;
		if (response == 'Y' || response == 'y') {
			lower_limit = midpoint;
			midpoint += (upper_limit - lower_limit) / 2;
			if (lower_limit == midpoint)
			{
				cout << "Is your number " << midpoint << '?' << endl;
				cin >> response;
				if (response == 'Y' || response == 'y') {
					cout << "BOOM!" << endl;
					correct_guess = true;
				}
				else if (response == 'N' || response == 'n') {
					cout << "You win!";
					exit(0);	//resolve this logic.
				}
				else
					cout << "Please enter a valid response. Y or N for yes and no, respectively." << endl;
			}
		}
		else if (response == 'N' || response == 'n') {
			upper_limit = midpoint;
			midpoint -= (upper_limit - lower_limit) / 2;
		}
		else
			cout << "Please enter a valid response. Y or N for yes and no, respectively." << endl;

	}
}



int main()
{
	prompt_user();
	determine_player_guess();
    return 0;
}



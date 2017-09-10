/*This program prompts the user for input to initialize 
an object of a Staircase class. The object is printed to
the screen.
Author: Dan Vyenielo
Date: 9/10/2017*/

#include "stdafx.h"
#include <iostream>
using namespace std;

class Staircase {
public:
	Staircase::Staircase(unsigned int in) {
		steps = in;
	}
	void print() {
		for (unsigned int i = 0; i < steps; i++) {
			for (unsigned int j = 0; j < steps - i; j++)
				cout << ' ';
			for (unsigned int k = steps; k >= steps - i; k--)
				cout << '#';
			cout << endl;
		}
	}
private:
	int steps;
};

int main()
{
	unsigned int input;
	cin >> input;
	Staircase challenge(input);
	challenge.print();
    return 0;
}


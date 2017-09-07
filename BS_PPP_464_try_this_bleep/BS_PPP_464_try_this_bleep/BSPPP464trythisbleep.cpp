/*The following program "bleeps" out disliked words by
reading input and filtering out censured words. Input is
read via a for loop that utilizes the condition of reading
in a string, which can be terminated via CTRL+Z on windows.
The words are stored in a vector, and sent as output to the
screen if they are not considered a censured word. Censured
words are replaced by BLEEP.*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool is_word_censured(const vector<string> &censure, const string word);

int main()
{
	vector<string> words;
	vector<string> censure = { "phuck","shat" };
	cout << "Type a sentence. When complete, press CTRL+Z." << endl;
	for (string word; cin >> word; )	//no need to increment - interesting.
		words.push_back(word);
	for (int i = 0; i < words.size(); i++){
		if (is_word_censured(censure, words[i]))
			cout << "BLEEP ";
		else
			cout << words[i] << ' ';
	}
	cout << endl;
    return 0;
}

bool is_word_censured(const vector<string> &censure, const string word) {
	int i = 0;
	bool flag = false;
	while (i < censure.size() && !flag)
	{
		if (word == censure[i])
			flag = true;
		i++;
	}
	return flag;
}

/*Type a sentence. When complete, press CTRL+Z.
phuck you shat face
^Z
BLEEP you BLEEP face
Press any key to continue . . .*/
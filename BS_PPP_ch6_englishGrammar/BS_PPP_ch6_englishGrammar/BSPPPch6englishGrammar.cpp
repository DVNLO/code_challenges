// BSPPPch6englishGrammar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool sentence();
bool is(const string& in, const vector<string>& list);

const vector<string> article_list{ "the" };
const vector<string> noun_list{ "birds", "fish", "C++" };
const vector<string> verb_list{ "rules", "fly", "swim" };
const vector<string> conjunction_list{ "and", "or", "but" };

int main()
{
	while (cin) {
		bool is_sentence = sentence();
		if (is_sentence)
			cout << "OKAY\n";
		else
			cout << "NOT OKAY\n";
	}
	return 0;
}

bool sentence() {
	string first, noun, verb, next;
	
	cin >> first;
	
	if (is(first, article_list))
		cin >> noun >> verb;
	else
	{
		noun = first;	//maybe the first is a noun
		cin >> verb;
	}
	
	if (is(noun, noun_list) && is(verb, verb_list)) {
		cin >> next;
		if (is(next, conjunction_list))
			sentence();
		else
			return true;
	}	
	else 
		return false;
}

bool is(const string& in, const vector<string>& list) {
	for (unsigned int i = 0; i < list.size(); i++)
	{
		if (list[i] == in)
			return true;
	}
	return false;
}


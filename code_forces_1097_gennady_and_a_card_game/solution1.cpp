#include <array>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	pair<char, char>table_card;
	array<pair<char, char>, 5> hand_cards;
	cin >> table_card.first >> table_card.second;
	for(int i = 0; i < 5; ++i)
	{
		cin >> hand_cards[i].first >> hand_cards[i].second;
	}
	for(auto hand_card : hand_cards)
	{
		if(hand_card.first == table_card.first
			|| hand_card.second == table_card.second)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 1;
}

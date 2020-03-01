#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<string, unsigned> grams;
	string max_gram{ "" };
	grams.insert( { "", 0U } );
	for(int i{ 1 }; i < n; ++i)
	{
		string g;
		g += s[i - 1];
		g += s[i];
		if(!grams.count(g))
			grams[g] = 1;
		else
			++grams[g];
		if(grams[max_gram] < grams[g])
			max_gram = g;
	}
	cout << max_gram << endl;
}

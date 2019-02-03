/* The following computes the longest common substring between two
 * strings s1 and s2. The longest string is iterated over in the
 * external loop, and only elements greater than the anchor are
 * considered. Note this is not extensively tested.
 * Author: Dan Vyenielo
 */

#include <iostream>
#include <string>

using namespace std;

string longest_common_substr(string const s1, string const s2)
{
	if(s1.size() < s2.size())
		return longest_common_substr(s2, s1);
	const unsigned size_s1 = s1.size();
	const unsigned size_s2 = s2.size();
	unsigned i = 0;
	unsigned anchor = i;
	string common = "";
	while(i < size_s1)
	{
		unsigned j = anchor;
		while(j < size_s2)
		{
			if(s1[i] == s2[j])
			{
				common += s2[j];
				anchor = j + 1;
				break;
			}
			++j;
		}
		++i;
	}
	return common;
}
		
int main()
{
	string s1 = "ABAZDC";
	string s2 = "BACBAD";
	string s3 = "AGGTAB";
	string s4 = "GXTXAYB";
	string common1 = longest_common_substr(s1, s2);
	string common2 = longest_common_substr(s3, s4);
	cout << common1 << '\n';
	cout << common2 << '\n';
}

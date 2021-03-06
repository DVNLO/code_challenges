#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
	const char LOCAL_AND_DOMAIN_SEPERATOR = '@';

public:
	string* parse(const string& email) {
		string* unique = new string("");
		const int size = email.size();
		int i = 0;
		char c = email[i];
		while (c != LOCAL_AND_DOMAIN_SEPERATOR) {
			if (c == '.') {
				i++;
				c = email[i];
			}
			else if (c == '+') {
				while (c != LOCAL_AND_DOMAIN_SEPERATOR) {
					i++;
					c = email[i];
				}
			}
			else {
				*unique += c;
				i++;
				c = email[i];
			}
		}
		while (i < size) {
			*unique += email[i];
			i++;
		}
		return unique;
	}


	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> unique_emails;
		for (const string email : emails) {
			string* tmp = parse(email);
			unique_emails.insert(*tmp);
			delete tmp;
		}
		return unique_emails.size();
	}
};

int main()
{
	vector<string> test_list = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
	Solution prompt;
	std::cout << prompt.numUniqueEmails(test_list);
}
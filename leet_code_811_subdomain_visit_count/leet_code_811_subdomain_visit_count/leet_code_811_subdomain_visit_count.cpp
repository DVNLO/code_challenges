/*
The following is a solution to prompt 811. Subdomain Visit Count
from leetcode.com. The prompt can be found here: https://leetcode.com/problems/subdomain-visit-count/description/
Author: Dan Vyenielo dvyenielo@gmail.com
Date: 28 June 2018*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains) {
		std::string count;
		std::string domain;
		std::string subDomain;
		std::unordered_map<std::string, int> domainVisits;
		for (const std::string cpdomain : cpdomains)
		{
			count = "";
			domain = "";
			subDomain = "";
			char c = cpdomain.front();
			int i = 0;
			while (c != ' ')
			{
				count += c;
				i++;
				c = cpdomain[i];
			}
			domain = cpdomain.substr(i);
			const int integral_count = stoi(count);
			const int domainLength = domain.length();
			for (unsigned int j = 0; j < domainLength; j++)
			{
				if (domain[j] == ' ' || domain[j] == '.')
				{
					subDomain = domain.substr(j + 1);
					auto got = domainVisits.find(subDomain);
					if (got == domainVisits.end()) //not found
						domainVisits.emplace(subDomain, integral_count);
					else    //found
						domainVisits[subDomain] += integral_count;
				}
			}
		}
		std::vector<std::string> visits;
		for (auto it = domainVisits.begin(); it != domainVisits.end(); ++it)
			visits.emplace_back(std::to_string(it->second) + " " + it->first);
		return visits;
	}
};

int main()
{
	Solution prompt;
	//["9001 discuss.leetcode.com"]
	std::vector<std::string> input = { "900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org" };
	std::vector<std::string> output = prompt.subdomainVisits(input);
    return 0;
}


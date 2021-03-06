/*
The following is a solution to prompt 933 number of Recent calls from 
leetcode.com. The prompt and driver can be found here: 
https://leetcode.com/problems/number-of-recent-calls/
Author: Dan Vyenielo
*/
#include "pch.h"
#include <iostream>
#include <set>
#include <queue>

using namespace std;

class RecentCounter {
private:
	//set<int> requests;	//first attempt
	queue<int> requests;
public:
	RecentCounter() {}
	/*
	//first attempt
	int ping(int t) {
		requests.insert(t);
		const int initial = t - 3000;
		for (int request : requests) {
			if (request < initial) {
				requests.erase(request);
			}
			else {
				break;
			}
		}
		return requests.size();
	}
	*/

	int ping(int t) {
		requests.push(t);
		const int initial = t - 3000;
		while (requests.front() < initial) {
			requests.pop();
		}
		return requests.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */


int main()
{
    std::cout << "Hello World!\n"; 
}

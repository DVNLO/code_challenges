/* The following is my solution to leetcode prompt 953 verify alien dictionary.
 * The program verifies lixicographical ordering of the words argument. A
 * priorities map is built for character lookup accoording to the ordering
 * string argument passed in isAlienSorted.
 * Author: Dan Vyenielo
 */

class Solution {
public:
	unordered_map<char, unsigned> priorities;

	bool isNonDecreasing(string const & left, string const & right) {
		unsigned const size = min(left.size(), right.size());
		for (unsigned i = 0; i < size; ++i) {
			if (priorities[left[i]] < priorities[right[i]])
				return true;
			else if (priorities[left[i]] > priorities[right[i]])
				return false;
		}
		return right.size() >= left.size();
	}

	bool isAlienSorted(vector<string>& words, string order) {
		unsigned priority = 1;
		for (char const c : order) {
			priorities[c] = priority;
			++priority;
		}
		unsigned const size = words.size();
		for (unsigned i = 1; i < size; ++i) {
			if (!isNonDecreasing(words[i - 1], words[i]))
				return false;
		}
		return true;
	}
};
/* The following is a collection of two solutions to leet code prompt
 * 985. The solutions are O(M*N) and O(N) time complexity. For the instances
 * of the problem computed when submitted the difference in execution times 
 * was an order of magnitude different. This is yet another important example
 * of the value efficient algorithms play in computation.
 * Author: Dan Vyenielo
 */

class Solution {
public:
	//O(N*M) | N is size of queries and M is size of A.
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		const unsigned size = queries.size();
		vector<int> B(size, 0);
		for (unsigned i = 0; i < size; ++i) {
			int val = queries[i][0];
			unsigned j = queries[i][1];
			A[j] += val;
			for (const int a : A) {
				if (!(a % 2))
					B[i] += a;
			}
		}
		return B;
	}	// execution time roughly 3000ms

	// O(N) | N is the size of queries.
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		const unsigned size = queries.size();
		vector<int> res(size, 0);
		int even_sum = 0;
		for (int const & a : A)
			if (!(a & 1))
				even_sum += a;
		for (unsigned i = 0; i < size; ++i) {
			int val = queries[i][0];
			unsigned j = queries[i][1];
			int & a = A[j];
			if (!(a & 1))    // a is initially even subtract it from our even_sum
				even_sum -= a;
			a += val;   // a is sum of initial value of a and queried value
			if (!(a & 1))    // a is finally even add it to our even_sum
				even_sum += a;
			res[i] = even_sum;    // store the current even_sum in res
		}
		return res;
	}	// execution time roughly 120ms.
};
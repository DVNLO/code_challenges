#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int * v = new int[n];
	for(int i{ 0 }; i < n; ++i)
	{
		scanf("%d", v + i);
	}
	// each student will take place = 1 + count(students with greater rating than his/her)
	// ai is the rating of th i-th student
	// eg
	// in 
	// 3
	// 1 3 4 
	// out 
	// 3 1 1 
	map<int, unsigned> rating_counts;
	for(int i{ 0 }; i < n; ++i)
	{
		if(rating_counts.count(v[i]))
			++rating_counts[v[i]];
		else
			rating_counts[v[i]] = 1U;
	}
	unordered_map<int, unsigned> rating_to_count_students_with_greater_rating;
	unsigned remaining_students = static_cast<unsigned>(n);
	for(auto const rating_count : rating_counts)
	{
		rating_to_count_students_with_greater_rating[rating_count.first] = remaining_students - rating_count.second + 1;
		remaining_students -= rating_count.second;
	}
	for(int i{ 0 }; i < n; ++i)
	{
		cout << rating_to_count_students_with_greater_rating[v[i]] << ' ';
	}
	cout << endl;
}



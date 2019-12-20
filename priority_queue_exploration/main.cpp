#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct point
{
    int x;
    int y;
};


bool operator<(point const & lhs, point const & rhs)
{
    return lhs.x < rhs.x && lhs.x < rhs.x;
}

bool operator>(point const & lhs, point const & rhs)
{
    return lhs.x > rhs.x && lhs.y > rhs.y;
}

// An example of a custom defined comparator. Note that
// the comparator must be compile time available. 
// It's a bit confusing that we've overloaded operator()
// for a comparisonm but that's the way it is. 
template<typename T>
struct comp
{
    bool operator()(T const & lhs, T const & rhs)
    {
        return lhs < rhs;
    }
};


// Example template specialization of the std::greater
// comparator for a pair<int, int>
template<>
constexpr bool greater<pair<int, int>>::operator()(pair<int, int> const & lhs, 
                                                    pair<int, int> const & rhs) const
{
    return lhs.second > rhs.second;
}

// The following is an exploration of the container
// adaptor priority queue. I have found, in multiple
// problems, that this data structure is exceptionally
// useful and performant. However, the syntax for the
// STL is a bit confusing with non-standard types. 
// The following utilizes the simple struct point, 
// defined above, as a custom class on which to build
// a priority queue as practice for working with 
// priority queues and classes. 
int main()
{
    // by default the priority queue will use 
    // std::less comparator to maintain a max heap.
    // Therefore, by default, calls to pq.top()
    // will return the max element in the pq.
    // We can iterate through elements in the pq
    // by repetitive calls to pq.top() and pq.pop().
    priority_queue<point> pq;   // max heap

    // In many cases, we desire the minimum element.
    // We can configure a priority que to to maintain
    // a minimum heap through specification of an 
    // alternative comparator function. 
    // The template paramater list for a priority queue
    // looks like:
    // template< class T,   // T is our internal data type
    //           class Container = std::vector<T>,  // This is our composing container
    //           class Compare = std::less<typename Container::value_type>  // This is the default comparator.
    //          > class priority_queue;
    // Notice that for the pq above, we can get away
    // with using the default comparator because we have
    // implemented the operator< for the data type for the max_heap
    // To implement a min_heap, we need to change our 
    // comparator. Thus, a min_heap can be declared like:
    priority_queue<point, 
                    vector<point>, 
                    greater<point>> pq_min;
    for(int i{ 0 }; i < 5; ++i)
    {
        point p{ i, i };
        pq.push(p);
        pq_min.push(p);
    }

    cout << "MAX HEAP :: ";
    for(int i{ 0 }; i < 5; ++i)
    {
        cout << pq.top().x << ',' << pq.top().y << ' ';
        pq.pop();
    }
    cout << endl;

    cout << "MIN HEAP :: ";
    for(int i{ 0 }; i < 5; ++i)
    {
        cout << pq_min.top().x << ',' << pq_min.top().y << ' ';
        pq_min.pop();
    }
    cout << endl;

    // In other cases, I have wanted to use a priority queue with
    // stl types, such as std::pair, but have not been able 
    // to confidently make the conversion between the two data 
    // types.
    // So the following is an exploration of converstion of an
    // unordered_map to a priority_queue.
    // Lets say we have the following map mp.
    unordered_map<int, int> mp;
    for(int i{ 0 }; i < 5; ++i)
        mp.insert({ i, i });
    // Now we have a map of 5 elements and we wish to construct
    // a priority que in linear time from the elements of 
    // mp. The stl priority que provides constructors for
    // linear time construction using the heapafy algo, we learned. 
    // But first, lets consider the naive way. 
    priority_queue<std::pair<int, int>, 
                    vector<pair<int, int>>,
                    std::greater<pair<int, int>>> pq_naive;
    for(auto const & p : mp)
        pq_naive.push(p);
    // To build pq_naive will take nlg(n) time. We are inserting
    // n objects into the priority que, and in the worst case 
    // insertion takes lg(n) time because we need to make comparisons
    // down the heap structure equivalent to the depth of the tree.
    cout << "PQ_NAIVE :: ";
    while(!pq_naive.empty())
    {
        cout << pq_naive.top().first << ' ';
        pq_naive.pop();
    }
    cout << endl;
    // Now what's unfortunate about the above methodology is the 
    // lack of expressivity regarding the ordering of the pairs
    // within the priority que. We know that the greater
    // comparator has been used, but which element of the 
    // pair is being used for ordering? Turns out the definitions
    // are here:    LEXICOGRAPHICALLY...
    // https://en.cppreference.com/w/cpp/utility/pair/operator_cmp
    // Which can be summarized as comparing the first elements 
    // and only if they are equivalent, compares the second elements.
    // In many situations this isn't the behavior we want,
    // so it's possible to manipulate this comparison functionality
    // by specifying our own comparator. Note, our comparator, must be
    // a compile time entity. However, in this case, we don't really need
    // the fully new comparator, we just want to define a specific
    // instance of std::greater<pair<int, int>> and 
    // std::less<pair<int, int>>. Above i've implemented those to 
    // compare on the second element. Alternatively, we can 
    // define a template specialization of the std::greater or std::less
    // to get the functionality we desire. This is a bit more complex
    // and the syntax might be a bit challenging to remember but I think
    // I can manage it. 

    // Finally lets look a non-naieve way to construct our
    // priority queue from the map we;ve made in linear time.
    unordered_map<int, int> pro{ { 7 , 5 }, { 2, 4 }, { 9, 3 }, { 8, 2 }, { 1, 1 } };
    cout << "pro.size() === " << pro.size() << endl;
    priority_queue<pair<int, int>,
                    vector<pair<int, int>>,
                    greater<pair<int, int>>> pq_pro{ pro.begin(), pro.end() };
    // Note that with range based construction we get ALLLLLLLL
    // the benifits of this construction syntax. Beautiful.
    // When we go to print, the pr_pro it is in ascending order of the second
    // element. 
    cout << "PQ_PRO :: " << pq_pro.size() << " :: ";
    while(!pq_pro.empty())
    {
        pair<int, int> p{ pq_pro.top() };
        pq_pro.pop();
        cout << p.first << ',' << p.second << ' ';
    }
    cout << endl;
    return 0;
}

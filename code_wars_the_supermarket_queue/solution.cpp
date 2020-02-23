// This is my second attempt. I use the stalls
// vector as a min_heap. For each customer. I pop
// the min value from the heap, insert the customer 
// value and insert the customer to the heap.
// The runtime here is O(c lg(n) + n)
long queueTime(std::vector<int> customers,int n)
{
  if(customers.empty())
    return 0;
  std::vector<long> stalls(n, 0);
  size_t const customers_size{ customers.size() };
  auto const STALLS_BEGIN{ stalls.begin() };
  auto const STALLS_END{ stalls.end() };
  long val;
  size_t const TERMINAL_IDX{ n - 1 };
  for(size_t i{ 0 }; i < customers_size; ++i)
  {
    std::pop_heap(STALLS_BEGIN, STALLS_END, std::greater<long>());  // move the minimum element to the TERMINAL_IDX
    stalls[TERMINAL_IDX] += customers[i];
    std::push_heap(STALLS_BEGIN, STALLS_END, std::greater<long>());  // heapify the new value into stalls heap.
  }
  long max_val{ 0 };
  for(auto const & stall : stalls)
  {
    if(stall > max_val)
      max_val = stall;
  }
  return max_val;
}


//O(n^2) solution. Better to use a priority queue.
long queueTime(std::vector<int> customers,int n)
{
  if(customers.empty())
    return 0;
  std::vector<long> stalls(n, 0);
  size_t const customers_size{ customers.size() };
  size_t const stalls_size{ stalls.size() };
  size_t min_stalls_idx;
  for(size_t i{ 0 }; i < customers_size; ++i)
  {
    min_stalls_idx = 0;
    for(size_t j{ 0 }; j < stalls_size; ++j)
    {
      if(stalls[j] < stalls[min_stalls_idx])
        min_stalls_idx = j;
    }
    stalls[min_stalls_idx] += customers[i];
  }
  size_t max_stalls_idx{ 0 };
  for(size_t j{ 0 }; j < stalls_size; ++j)
  {
    if(stalls[j] > stalls[max_stalls_idx])
      max_stalls_idx = j;
  }
  return stalls[max_stalls_idx];
}

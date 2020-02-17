class WhichAreIn
{

  public:
  static
  bool 
  is_substr(std::string const & lhs, 
            std::string const & rhs)
  // returns true if lhs is a substring of rhs.
  // else returns false.
  {
    size_t l{ 0 };
    size_t r{ 0 };
    size_t const LHS_SIZE{ lhs.size() };
    size_t const RHS_SIZE{ rhs.size() };
    while(l < LHS_SIZE 
          && r < RHS_SIZE)
    {
      if(rhs[r] == lhs[l])
        ++l;
      else
        l = 0;
      ++r;
    }
    return l == LHS_SIZE;
  }
  
  static 
  std::vector<std::string> 
  inArray(std::vector<std::string> &arr1, 
          std::vector<std::string> &arr2)
  // returns a lexicographically sorted vector
  // of strings containing strings from arr1
  // which are substrings of strings from arr2.
  {
    std::vector<std::string> r;
    size_t const ARR1_SIZE{ arr1.size() };
    size_t const ARR2_SIZE{ arr2.size() };
    size_t j;
    for(size_t i{ 0 }; i < ARR1_SIZE; ++i)
    {
      j = 0;
      while(j < ARR2_SIZE)
      {
        if(is_substr(arr1[i], arr2[j]))
        {
          r.emplace_back(arr1[i]);
          break;
        }
        ++j;
      }
    }
    sort(r.begin(), r.end());
    return r;
  }
};

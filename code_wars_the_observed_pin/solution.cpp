#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

std::vector<std::string> get_pins(std::string observed) 
{
  if(observed.empty())
    return {};
  static std::unordered_map<char, std::vector<char>> possible_keys
  { 
    { '1', { '1', '2', '4' } },
    { '2', { '2', '1', '3', '5' } },
    { '3', { '3', '2', '6' } },
    { '4', { '4', '1', '5', '7' } },
    { '5', { '5', '2', '4', '6', '8' } },
    { '6', { '6', '3', '5', '9' } },
    { '7', { '7', '4', '8' } },
    { '8', { '8', '0', '5', '7', '9' } },
    { '9', { '9', '6', '8' } },
    { '0', { '0', '8' } } 
  };
  size_t const OBSERVED_SIZE{ observed.size() };
  std::vector<size_t> repetition_counts{ OBSERVED_SIZE };
  repetition_counts[OBSERVED_SIZE - 1] = 1;
  for(size_t i{ 1 }; i < OBSERVED_SIZE; ++i)
  {
    repetition_counts[OBSERVED_SIZE - i - 1] = repetition_counts[OBSERVED_SIZE - i] 
                                                 * possible_keys[observed[OBSERVED_SIZE - i]].size();
    std::cout << repetition_counts[OBSERVED_SIZE - i - 1] << ' ';
  }
  size_t const VARIATIONS_COUNT{ repetition_counts[0] 
                                  * possible_keys[observed[0]].size() };
  std::cout << VARIATIONS_COUNT << '\n';
  std::vector<std::string> variations(VARIATIONS_COUNT, std::string());
  size_t l;
  size_t possible_key_count;
  for(int i{ 0 }; i < OBSERVED_SIZE; ++i)  
  // each of the observed symbols paste the possible key 
  // paste repetition count times into variations
  {
    l = 0;
    while(l < VARIATIONS_COUNT)
    {
      possible_key_count = possible_keys[observed[i]].size();
      for(int j{ 0 }; j < possible_key_count; ++j)
      {
        for(int k{ 0 }; k < repetition_counts[i]; ++k)
        {
          variations[l] += possible_keys[observed[i]][j];
          ++l;
        }
      }
    }
  }
  return variations;
}

int main()
{
  std::vector<std::string> ss{ get_pins("1357") };
  for(auto const & s : ss)
    std::cout << s << '\n';
  std::cout << std::endl;
}

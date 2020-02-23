// Returns the pig_latin conversion of an input word, pig_word.
// A pig_word is a transformation of the input word, such that
// the first alphabetic symbol is moved to the end of the input
// word and the suffix "ay" is appended.
std::string convert_to_pig_latin(std::string const & word)
{
  std::string pig_word;
  size_t const WORD_SIZE{ word.size() };
  if(!WORD_SIZE)
    return pig_word;
  size_t i{ 0 };
  while(i < WORD_SIZE 
        && !isalpha(word[i]))  // copy until first alpha
  {
    pig_word += word[i];
    ++i;
  }
  if(i >= WORD_SIZE)
    return pig_word;
  char first_alpha = word[i];
  ++i;
  while(i < WORD_SIZE)  // copy until the end
  {
    pig_word += word[i];
    ++i;
  }
  pig_word += first_alpha;
  pig_word += "ay";
  return pig_word;
}

// Returns the pig latin transformation of the input sequence
// of words. Assumes words are delimited on spaces.
std::string pig_it(std::string str)
{
    std::string pig_str;
    std::string word;
    size_t const STR_SIZE{ str.size() };
    size_t i{ 0 };
    while(i < STR_SIZE)
    {
      word.clear();
      while(i < STR_SIZE 
            && str[i] == ' ')  // copy whitespace to pig_str
      {
        pig_str += str[i];
        ++i;
      }
      while(i < STR_SIZE 
            && str[i] != ' ')  // copy nonwhitespace to word
      {
        word += str[i];
        ++i;
      }
      pig_str += convert_to_pig_latin(word);
    }
    return pig_str;
}
#include <iostream>
#include <string>
#include <algorithm>

bool
is_equal(std::string const & lhs, 
		 std::string const & rhs)
{
	std::size_t const lhs_size{ lhs.size() };
	std::size_t const rhs_size{ rhs.size() };
	if(lhs_size != rhs_size)
	{
		return false;
	}
	else
	{
		for(std::size_t i{ 0U }; i < lhs_size; ++i)
		{
			if(lhs[i] != rhs[i])
				return false;
		}
		return true;
	}
}

void
my_reverse(std::string & s)
{
	std::size_t const size_s{ s.size() };
	char other_pos;
	for(std::size_t i{ 0U }; i < size_s / 2; ++i)
	{
		other_pos = s[i];
		s[i] = s[size_s - i - 1];
		s[size_s - i - 1] = other_pos;
		//std::swap(s[i], s[size_s - i - 1]);
	}
}

void
moms_implementation()
{
	std::string s;
	std::string t;
	std::cin >> s;	// 123
	std::cin >> t;
	my_reverse(s);
	if(is_equal(s, t))	// t == 321 && s == 321 =>
	{
		std::cout << "YES";	// execute
	}
	else	// t != s
	{
		std::cout << "NO";
	}
	std::cout << std::endl;	// do this now!!!!
}

int main()
{
	moms_implementation();
	/*
	std::string s;
	std::string t;
	std::cin >> s;
	std::cin >> t;
	std::string s_reversed{ my_reverse(s) };
	if(is_equal(s, t))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	std::cout << std::endl;
	*/
}

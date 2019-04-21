#include <chrono>
#include <cstdint>
#include <ctime>
#include <iostream>
#include <string>

void generate(std::string const & str, unsigned const & cur_depth, unsigned const & max_depth)
{
	if (str.size() == max_depth)
		std::cout << str << '\n';
	std::string zero = str + '0';
	std::string one = str + '1';
	if (cur_depth < max_depth) {
		unsigned const next_depth = cur_depth + 1;
		generate(zero, next_depth, max_depth);
		generate(one, next_depth, max_depth);
	}
}

void alphabet()
{
	std::string source{ '0' };
	unsigned const cur_depth{ 0 };
	unsigned const max_depth{ 8 };
	generate(source, cur_depth, max_depth);
}

int main()
{
	volatile uint8_t i = 1;
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();
	while(i)
		++i;
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << elapsed_seconds.count() << '\n';

	char c;
	std::cin >> c;
}
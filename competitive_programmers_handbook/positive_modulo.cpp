#include <cassert>
#include <iostream>

using namespace std;

template <typename T>
inline constexpr T euclidean_modulo(T x, T y)
{
	T mod = x % y;
	if(mod < 0)
	{
		mod = (y < 0) ? mod - y : mod + y;
	}
	return mod;
}

void test_negative_x_negative_y()
{
	int actual = euclidean_modulo(-10, -3);
	int expected = 2;
	cout << "test_negative_x_negative_y : actual == " << actual 
		<< " && expected == " << expected;
	assert(actual == expected);
	cout << " : [ passed ]\n";
}

void test_negative_x_positive_y()
{
	int actual = euclidean_modulo(-10, 3);
	int expected = 2;
	cout << "test_negative_x_positive_y : actual == " << actual 
		<< " && expected == " << expected;
	assert(actual == expected);
	cout << " : [ passed ]\n";
}

void test_positive_x_negative_y()
{
	int actual = euclidean_modulo(10, -3);
	int expected = 1;
	cout << "test_positive_x_negative_y : actual == " << actual 
		<< " && expected == " << expected;
	assert(actual == expected);
	cout << " : [ passed ]\n";
}

void test_positive_x_positive_y()
{
	int actual = euclidean_modulo(10, 3);
	int expected = 1;
	cout << "test_positive_x_positive_y : actual == " << actual 
		<< " && expected == " << expected;
	assert(actual == expected);
	cout << " : [ passed ]\n";
}

int main()
{
	test_negative_x_negative_y();
	test_negative_x_positive_y();
	test_positive_x_positive_y();
	test_positive_x_positive_y();
}

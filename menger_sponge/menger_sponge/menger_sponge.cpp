/*
The following program produces an ASCII art image of a
Sierpinski Carpet. The dimension of the square must be
a product of 3's. isSierpinskiCarpetPixelFilled() was 
sourced from wikipedia. Otherwise, the remaining 
code is my own. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"

int elements(const int& rows, const int& columns) {
	return rows * columns;
}

char* createSquareCloud(const int& side_length, const char& symbol) {
	const int interval = side_length + 1;
	const int sequence_length = elements(side_length, interval);
	char* cloud = new char[sequence_length + 1];
	for (int i = 0; i < sequence_length; i++) {
		if (!((i + 1) % interval)) {
			cloud[i] = '\n';
		}
		else {
			cloud[i] = symbol;
		}
	}
	cloud[sequence_length] = '\0';
	return cloud;
}

/*
* Decides if a point at a specific location is filled or not.  This works by iteration first checking if
* the pixel is unfilled in successively larger squares or cannot be in the center of any larger square.
* x is the x coordinate of the point being checked with zero being the first pixel
* y is the y coordinate of the point being checked with zero being the first pixel
* 1 if it is to be filled or 0 if it is open
* https://en.wikipedia.org/wiki/Sierpinski_carpet
*/
int isSierpinskiCarpetPixelFilled(int x, int y)
{
	while (x > 0 || y > 0) // when either of these reaches zero the pixel is determined to be on the edge 
						   // at that square level and must be filled
	{
		if (x % 3 == 1 && y % 3 == 1) //checks if the pixel is in the center for the current square level
			return 0;
		x /= 3; //x and y are decremented to check the next larger square level
		y /= 3;
	}
	return 1; // if all possible square levels are checked and the pixel is not determined 
			  // to be open it must be filled
}

char* createSierpinskiCarpet(const int& side_length, const char& symbol) {
	const int interval = side_length + 1;
	char* cloud = createSquareCloud(side_length, symbol);
	for (int x = 0; x < side_length; x++) {
		for (int y = 0; y < side_length; y++) {
			if (!isSierpinskiCarpetPixelFilled(x, y))
				cloud[x * interval + y] = ' ';
		}
	}
	return cloud;
}

int main()
{
	const int side_length = 9;
	const char symbol = 219;
	//char* cloud = createSquareCloud(side_length, symbol);
	char* carpet = createSierpinskiCarpet(side_length, symbol);
	printf("%s", carpet);
	//delete[] cloud;
	delete[] carpet;
    return 0;
}


/*This program computes sum, min, max, and mean of
a vector<double>. 
Prompt provided by Bjarne Stroustrup's book Programming
Principles and Practice chapter 4 exercise 3. 
Author: Dan Vyenielo
Date: 9/10/17*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double sumDistance(const vector<double> &in) {
	double sum = 0;
	for (unsigned int i = 0; i < in.size(); i++)
	{
		sum += in[i];
	}
	return sum;
}

double minDistance(const vector<double> &in) {
	double min = in[0];
	for (unsigned int i = 1; i < in.size(); i++)
	{
		if (in[i] < min)
			min = in[i];
	}
	return min;
}

double maxDistance(const vector<double> &in) {
	double max = in[0];
	for (unsigned int i = 1; i < in.size(); i++)
	{
		if (max < in[i])
			max = in[i];
	}
	return max;
}

double meanDistance(const vector<double> &in) {
	return (sumDistance(in) / in.size());
}

int main()
{
	vector<double> distanceBetweenCities = { 3.045, 2.25, 5.55, 7.75};
	cout << "sumDistance == " << sumDistance(distanceBetweenCities) << endl;
	cout << "minDistance == " << minDistance(distanceBetweenCities) << endl;
	cout << "maxDistance == " << maxDistance(distanceBetweenCities) << endl;
	cout << "meanDistance == " << meanDistance(distanceBetweenCities) << endl;
    return 0;
}


/*
The following is a solution to prompt 812. Largest Triangle Area from
leetcode.com. The prompt can be found here: https://leetcode.com/problems/largest-triangle-area/description/
Included with this solution is a set of additional classes I wrote 
while thinking about a more object oriented solution to this program.
The additional functions provide supplementary functionality for
geometric operations in R2.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

namespace R2
{
	double slope(const std::pair<double, double>& point1, const std::pair<double, double>& point2) {
		return (point2.second - point1.second) / (point2.first - point1.first);
	}

	double intercept(const std::pair<double, double>& point, const double& slope) {
		return point.second - (slope * point.first);
	}

	double distance(const std::pair<double, double>& point1, const std::pair<double, double>& point2) {
		return sqrt(pow(point2.second - point1.second, 2) + pow(point2.first - point1.first, 2));
	}

	class Line {
	public:
		Line(const double& slope, const double& intercept);
		Line(const double& slope, const std::pair<double, double>& point);
		Line(const std::pair<double, double>& point1, const std::pair<double, double>& point2);
		double getM() const;
		double getB() const;
	private:
		double m;
		double b;
	};

	Line::Line(const double& slope, const double& intercept) {
		this->m = slope;
		this->b = intercept;
	}

	Line::Line(const double& slope, const std::pair<double, double>& point) {
		this->m = slope;
		this->b = intercept(point, slope);
	}

	Line::Line(const std::pair<double, double>& point1, const std::pair<double, double>& point2) {
		if (point1 == point2)
			throw std::invalid_argument("invalid_argument :: point1 == point2");
		this->m = slope(point1, point2);
		this->b = intercept(point1, this->m);
	}

	double Line::getM() const {
		return this->m;
	}

	double Line::getB() const {
		return this->b;
	}

	class Triangle {
	public:
		Triangle(const std::pair<double, double>& point1, 
			const std::pair<double, double>& point2, const std::pair<double, double>& point3);
		std::pair<double, double> getA() const;
		std::pair<double, double> getB() const;
		std::pair<double, double> getC() const;
	private:
		std::pair<double, double> a;
		std::pair<double, double> b;
		std::pair<double, double> c;
	};

	double area(const Triangle& triangle) {
		//by shoelace formula : https://en.wikipedia.org/wiki/Shoelace_formula
		//wrong formula look at areaTriangle()
		/*
		return 0.5 * ((triangle.getB().first * triangle.getC().second - triangle.getC().first * triangle.getB().second)
		- (triangle.getA().first * triangle.getC().second - triangle.getC().first * triangle.getA().second)
		+ (triangle.getA().first * triangle.getB().second - triangle.getB().first * triangle.getA().second));
		*/
		return 0;
	}

	Triangle::Triangle(const std::pair<double, double>& point1,
		const std::pair<double, double>& point2, const std::pair<double, double>& point3) {
		if (point1 == point2 || point1 == point3 || point2 == point3)
			throw std::invalid_argument("invalid_argument :: point1 == point2 || point1 == point3 || point2 == point3");
		this->a = point1;
		this->b = point2;
		this->c = point3;
	}

	std::pair<double, double> Triangle::getA() const {
		return this->a;
	}

	std::pair<double, double> Triangle::getB() const {
		return this->b;
	}

	std::pair<double, double> Triangle::getC() const {
		return this->c;
	}
}

class Solution {
public:
	double areaTriangle(const std::vector<int>& A, const std::vector<int>& B, const std::vector<int>& C) {
		//by shoelace formula : https://en.wikipedia.org/wiki/Shoelace_formula
		return 0.5 * abs(A[0] * B[1] + B[0] * C[1] + C[0] * A[1] - B[0] * A[1] - C[0] * B[1] - A[0] * C[1]);
	}

	double largestTriangleArea(std::vector<std::vector<int>>& points) {
		double maxArea = 0;
		for (unsigned int i = 0; i < points.size(); i++) {
			for (unsigned int j = i + 1; j < points.size(); j++) {
				for (unsigned int k = j + 1; k < points.size(); k++) {
					double area = areaTriangle(points[i], points[j], points[k]);
					if (area > maxArea)
						maxArea = area;
				}
			}
		}
		return maxArea;
	}
};

int main()
{
	Solution prompt;
	std::vector<std::vector<int> > points = { {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0} };
	prompt.largestTriangleArea(points);
    return 0;
}

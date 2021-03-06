// faster_matrix_algebra_ATLAS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Eigen\Dense"
#include <vector>
#include <array>

/*
class SymMat 
{
private:
	std::vector< std::vector< Eigen::MatrixXd > > upper_triangle;

	bool isSymMat(const Eigen::MatrixXd& subject) const
	{
		int M = subject.rows() - 1;
		int N = subject.rows();
		for (int i = 0; i < M; i++)
		{
			for (int j = i + 3; j < N; j++)
			{
				if (subject(i, j) == subject(j, i))
				{
					std::cout << "s(" << i << "," << j << ")" << " == " << subject(i, j) << " == " << "s(" << j << "," << i << ")" << " == " << subject(j, i) << std::endl;
				}
				else
				{
					std::cout << "s(" << i << "," << j << ")" << " == " << subject(i, j) << " != " << "s(" << j << "," << i << ")" << " == " << subject(j, i) << std::endl;
					return false;
				}
			}
		}
		return true;
	}

	std::vector< std::vector< Eigen::MatrixXd > > buildUpperTriangle(const Eigen::MatrixXd& subject)
	{
		int M = subject.rows() - 1;
		int N = subject.rows();

		std::vector< std::vector< Eigen::MatrixXd > > container;
		container.resize(M);
		
		for (int i = 0; i < M; i++)
		{
			container[i].resize(M - i);
			for (int j = i + 1; j < N; j++)
			{
				container[i][j]; // returns an Eigen::MatrixXd
			}
		}
	}

public:
	SymMat() 
	{
	}

	SymMat(const Eigen::MatrixXd& input)
	{
		if (!isSymMat(input))
		{
			throw std::invalid_argument("non-symetric matrix");
		}
		upper_triangle = buildUpperTriangle(input);
	}
};
*/

//assuming the matrix is square, we can determine if it's symetric.
//A symetric matrix has the property that Aij = Aji


int main()
{
	/*
	//example from wikipedia
	Eigen::MatrixXd m(18,18);
	int mCount = (m.rows() / 3);

	for (int i = 0; i < mCount; i++)
	{
		for (int j = 0; j < mCount; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				for (int l = 0; l < 3; l++)
				{
					m(k + (3 * i), l + (3 * j)) = count;
					if (count == 8)
					{
						count = 0;
					}
					else
					{
						count++;
					}
				}

			}

		}

	}
	std::cout << m << std::endl;
	*/

	std::vector < std::vector< Eigen::Matrix3d > > upper_triangle;
	std::vector < std::vector< Eigen::Matrix3d* > > upper_triangle_ptr;
	int count = 0;
	Eigen::Matrix3d subject;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			subject(i, j) = count;
			count++;
		}
	}


	int size = 30000;
	upper_triangle.resize(size);
	for (int i = 0; i < size; i++)
	{
		upper_triangle.at(i).resize(size - i);
		for (int j = 0; j < (size - i); j++)
		{
			upper_triangle.at(i).at(j) = subject;
		}
	}

	Eigen::Matrix3d* lastMatrix_Ptr = &subject;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - i); j++)
		{
			std::cout << upper_triangle.at(i).at(j) << " " << &upper_triangle.at(i).at(j) 
				<< " - " << lastMatrix_Ptr << " == " << &upper_triangle.at(i).at(j) - lastMatrix_Ptr << std::endl;
			lastMatrix_Ptr = &upper_triangle.at(i).at(j);
		}
	}

	return 0;
}

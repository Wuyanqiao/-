#include <iostream>
#include "Array.h"
int n = 0, m = 0, p = 0, q = 0;
int main()
{
	/*
		while (true) {
		  输入矩阵1行列大小，如果矩阵行为负，跳出循环

		  new矩阵1，输入矩阵1
		  输入矩阵2行列大小
		  new矩阵2，输入矩阵2

		  求矩阵1的转置，输出，清理内存

		  求两个矩阵的和，如果结果不为NULL，输出并清理内存

		  求两个矩阵的乘，如果结果不为NULL，输出并清理内存
		}
		*/

	//输入两个二维数组的维度，直到输入有效值。
	while (true)
	{
		//输入第一个二维数组的维度。
		std::cout << "Input the lines of the 1starray: ";
		std::cin >> n;
		std::cout << "Input the columns of the 1st array: ";
		std::cin >> m;
		if (n == 0 || m == 0)
		{
			std::cout << "Invalid input, please input again." << std::endl;
			continue;
		}
		else if (n < 0 || m < 0)
		{
			std::cout << "Negative, break!" << std::endl;
			break;
		}
		//创建第一个二维数组，二维数组的元素为double型。
		std::cout << "Input the nums in the 1st array:\n";
		double** arr1 = new double* [n];
		for (int i = 0; i < n; i++)
		{
			arr1[i] = new double[m];
			for (int j = 0; j < m; j++)
			{
				std::cin >> arr1[i][j];
			}
		}
		//输入第二个二维数组的维度。
		std::cout << "Input the #lines of the 2ndarray: ";
		std::cin >> p;
		std::cout << "Input the #columns of the 2nd array: ";
		std::cin >> q;
		if (p == 0 || q == 0)
		{
			std::cout << "Invalid input, please input again." << std::endl;
			continue;
		}
		else if (p < 0 || q < 0)
		{
			std::cout << "Negative input, break!" << std::endl;
			break;
		}
		//创建第二个二维数组，二维数组的元素为double型。
		std::cout << "Input the nums in the 2nd array:\n";
		double** arr2 = new double* [q];
		for (int i = 0; i < q; i++)
		{
			arr2[i] = new double[p];
			for (int j = 0; j < p; j++)
			{
				std::cin >> arr2[i][j];
			}
		}
	
		// 调用函数求第一个二维数组的转置。
		double** transposedArr = arrtransp(arr1, n, m);
		// 输出第一个二维数组的转置。
		std::cout << "The transposed array of the 1st array is:" << std::endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << transposedArr[i][j] << " ";
			}
			std::cout << std::endl;
		}
		// 清理转置后数组的内存。
		for (int i = 0; i < m; i++)
		{
			delete[] transposedArr[i];
		}
		delete[] transposedArr;
		// 调用函数求两个二维数组的乘积。
		double** mulArr = arrmul(arr1, arr2, n, q);
		// 输出两个二维数组的乘积。
		if (mulArr != NULL)
		{
			std::cout << "The product of the two arrays is:" << std::endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < q; j++)
				{
					std::cout << mulArr[i][j] << " ";
				}
				std::cout << std::endl;
			}
			// 清理内存。
			for (int i = 0; i < n; i++)
			{
				delete[] mulArr[i];
			}
			delete[] mulArr;
		}
		else
		{
			std::cout << "The product of the two arrays is NULL." << std::endl;
		}

		// 调用函数求两个二维数组的和。
		double** sumArr = arradd(arr1, arr2, n, p, q);
		// 输出两个二维数组的和。
		if (sumArr != NULL)
		{
			std::cout << "The sum of the two arrays is:" << std::endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < q; j++)
				{
					std::cout << sumArr[i][j] << " ";
				}
				std::cout << std::endl;
			}
			// 清理内存。
			for (int i = 0; i < n; i++)
			{
				delete[] sumArr[i];
			}
			delete[] sumArr;
		}
		else
		{
			std::cout << "The sum of the two arrays is NULL." << std::endl;
		}
	}
	return 0;
 }
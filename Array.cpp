#include "Array.h"
#include <iostream>

//转置函数
double** arrtransp(double** arr1, int n, int m)
{
	//创建用于存储转置结果的二维数组，行数为m，列数为n。
	double** arr3 = new double* [m];
	for (int i = 0; i < m; i++)
	{
		arr3[i] = new double[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr3[i][j] = arr1[j][i];
		}
	}
	return arr3;
}

//矩阵乘法函数
double** arrmul(double** arr1, double** arr2, int n, int q)
{
	//判断两个二维数组是否能进行矩阵乘法。
	if (q != n)
	{
		std::cout << "The two arrays cannot be multiplied." << std::endl;
		return NULL;
	}
	else
	{
		//创建用于存储乘积结果的二维数组，行数为n，列数为q。
		double** arr3 = new double* [n];
		for (int i = 0; i < n; i++)
		{
			arr3[i] = new double[q];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < q; j++)
			{
				arr3[i][j] = 0;
				for (int k = 0; k < q; k++)
				{
					arr3[i][j] += arr1[i][k] * arr2[k][j];
				}
			}
		}
		return arr3;
	}
}

//矩阵加法函数
double** arradd(double** arr1, double** arr2, int n, int p, int q)
{
	//判断数组是否能进行加法。
	if (n != p)
	{
		std::cout << "The two arrays cannot be added." << std::endl;
		return NULL;
	}
	else 
	{
		//创建用于存储和结果的二维数组，行数为n，列数为p。
		double** arr3 = new double* [n];
		for (int i = 0; i < n; i++)
		{
			arr3[i] = new double[p];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < q; j++)
			{
				arr3[i][j] = arr1[i][j] + arr2[i][j];
			}
		}
		return arr3;
	}
}
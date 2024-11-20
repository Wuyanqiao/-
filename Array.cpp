#include "Array.h"
#include <iostream>

//ת�ú���
double** arrtransp(double** arr1, int n, int m)
{
	//�������ڴ洢ת�ý���Ķ�ά���飬����Ϊm������Ϊn��
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

//����˷�����
double** arrmul(double** arr1, double** arr2, int n, int q)
{
	//�ж�������ά�����Ƿ��ܽ��о���˷���
	if (q != n)
	{
		std::cout << "The two arrays cannot be multiplied." << std::endl;
		return NULL;
	}
	else
	{
		//�������ڴ洢�˻�����Ķ�ά���飬����Ϊn������Ϊq��
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

//����ӷ�����
double** arradd(double** arr1, double** arr2, int n, int p, int q)
{
	//�ж������Ƿ��ܽ��мӷ���
	if (n != p)
	{
		std::cout << "The two arrays cannot be added." << std::endl;
		return NULL;
	}
	else 
	{
		//�������ڴ洢�ͽ���Ķ�ά���飬����Ϊn������Ϊp��
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
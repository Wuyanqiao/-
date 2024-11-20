#include <iostream>
#include "Array.h"
int n = 0, m = 0, p = 0, q = 0;
int main()
{
	/*
		while (true) {
		  �������1���д�С�����������Ϊ��������ѭ��

		  new����1���������1
		  �������2���д�С
		  new����2���������2

		  �����1��ת�ã�����������ڴ�

		  ����������ĺͣ���������ΪNULL������������ڴ�

		  ����������ĳˣ���������ΪNULL������������ڴ�
		}
		*/

	//����������ά�����ά�ȣ�ֱ��������Чֵ��
	while (true)
	{
		//�����һ����ά�����ά�ȡ�
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
		//������һ����ά���飬��ά�����Ԫ��Ϊdouble�͡�
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
		//����ڶ�����ά�����ά�ȡ�
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
		//�����ڶ�����ά���飬��ά�����Ԫ��Ϊdouble�͡�
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
	
		// ���ú������һ����ά�����ת�á�
		double** transposedArr = arrtransp(arr1, n, m);
		// �����һ����ά�����ת�á�
		std::cout << "The transposed array of the 1st array is:" << std::endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				std::cout << transposedArr[i][j] << " ";
			}
			std::cout << std::endl;
		}
		// ����ת�ú�������ڴ档
		for (int i = 0; i < m; i++)
		{
			delete[] transposedArr[i];
		}
		delete[] transposedArr;
		// ���ú�����������ά����ĳ˻���
		double** mulArr = arrmul(arr1, arr2, n, q);
		// ���������ά����ĳ˻���
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
			// �����ڴ档
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

		// ���ú�����������ά����ĺ͡�
		double** sumArr = arradd(arr1, arr2, n, p, q);
		// ���������ά����ĺ͡�
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
			// �����ڴ档
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
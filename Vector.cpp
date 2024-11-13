/*
dotProduct And crossProduct function
*/
#include "Vetor.h"
#include <iostream>
#define ArraySize 3

int dotProduct()
{
	int N = 0;  // �����С����
	float DotProduct = 0;  // �������
	char selectf;  // ѡ�����

	while (true)  // ����ѭ��
	{
		std::cout << "Please input the size of your array N(0<N<10)\n";
		std::cin >> N;  // �û����������С

		// ��Ҫ���û�������
		if (N <= 0)  // �����˳�ѭ��
		{
			std::cout << "The N is negative!\n";
			break;
		}
		else if (N >= 10)  // ����10��������������
		{
			std::cout << "The N is too large!Please input it again!\n";
			continue;
		}
		else  // ��Ч���ֿ�ʼ���г������
		{
			// ���嶯̬���飬ָ������ڴ�
			float* array1 = new float[N];
			float* array2 = new float[N];

			std::cout << "First array:\n";

			// ѭ����ֵ
			for (int i = 0; i < N; ++i)
			{
				std::cin >> array1[i];
			}

			std::cout << "Next array:\n";

			// ѭ����ֵ
			for (int i = 0; i < N; ++i)
			{
				std::cin >> array2[i];
			}

			// ������
			for (int i = 0; i < N; ++i)
			{
				DotProduct += array1[i] * array2[i];
			}

			// ������
			std::cout << "The result is:" << DotProduct << std::endl;

			delete[] array1;
			delete[] array2;

			std::cout << "Do you want to continue? Input Y/y to continue and input N/n to break��";
			std::cin >> selectf;

			if (selectf == 'Y'|| selectf == 'y')
			{
				continue;
			}
			else if (selectf == 'N' || selectf == 'n')
			{
				break;
			}
			else
			{
				std::cout << "Error!Break!/n";
				break;
			}
		}
	}
	return 0;
}


int crossProduct()
{
	char selectf;  // ѡ�����
	while (true)
	{
		float* CrossProductarray = new float[ArraySize] {0};
		float* array3 = new float[ArraySize] {0};
		float* array4 = new float[ArraySize] {0};

		for (int i = 0; i < ArraySize; ++i)
		{
			std::cout << "Tnput your " << i + 1 << " number inarray3:";
			std::cin >> array3[i];
			std::cout << std::endl;
		}

		for (int i = 0; i < ArraySize; ++i)
		{
			std::cout << "Tnput your " << i + 1 << " number inarray4:";
			std::cin >> array4[i];
			std::cout << std::endl;
		}

		CrossProductarray[0] = array3[1] * array4[2] - array3[2] * array4[1];
		CrossProductarray[1] = array3[2] * array4[0] - array3[0] * array4[2];
		CrossProductarray[2] = array3[0] * array4[1] - array3[1] * array4[0];

		std::cout << "The result is : \n";
		std::cout << "CrossProductarray[" << CrossProductarray[0] << ", " << CrossProductarray[1] << ", " << CrossProductarray[2] << "]\n";

		delete[] CrossProductarray;
		delete[] array3;
		delete[] array4;

		std::cout << "Do you want to continue? Input Y to continue and input N to break��";
		std::cin >> selectf;

		if (selectf == 'Y')
		{
			continue;
		}
		else if (selectf == 'N')
		{
			break;
		}
		else
		{
			std::cout << "Error!Break!\n";
			break;
		}
	}
	return 0;
}
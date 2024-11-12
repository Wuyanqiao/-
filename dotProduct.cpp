/*
dotProduct
*/
#include "Math.h"
#include <iostream>

int dotProduct()
{
	int N = 0;  // 数组大小变量
	float DotProduct = 0;  // 结果变量
	char selectf;  // 选择变量

	while (true)  // 程序循环
	{
		std::cout << "Please input the size of your array N(0<N<10)\n";
		std::cin >> N;  // 用户输入数组大小

		// 必要的用户输入检测
		if (N <= 0)  // 负数退出循环
		{
			std::cout << "The N is negative!\n";
			break;
		}
		else if (N >= 10)  // 大于10的数字重新输入
		{
			std::cout << "The N is too large!Please input it again!\n";
			continue;
		}
		else  // 有效数字开始进行程序计算
		{
			// 定义动态数组，指针分配内存
			float* array1 = new float[N];
			float* array2 = new float[N];

			std::cout << "First array:\n";

			// 循环赋值
			for (int i = 0; i < N; ++i)
			{
				std::cin >> array1[i];
			}

			std::cout << "Next array:\n";

			// 循环赋值
			for (int i = 0; i < N; ++i)
			{
				std::cin >> array2[i];
			}

			// 计算结果
			for (int i = 0; i < N; ++i)
			{
				DotProduct += array1[i] * array2[i];
			}

			// 输出结果
			std::cout << "The result is:" << DotProduct << std::endl;

			delete[] array1;
			delete[] array2;

			std::cout << "Do you want to continue? Input Y/y to continue and input N/n to break：";
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
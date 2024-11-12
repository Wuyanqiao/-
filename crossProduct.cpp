#include "Math.h"
#include <iostream>
#define ArraySize 3

int crossProduct()
{
	char selectf;  // 选择变量
	while (true) 
	{
		float* CrossProductarray = new float[ArraySize] {0};
		float* array3 = new float[ArraySize] {0};
		float* array4 = new float[ArraySize]{0};

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

		std::cout << "Do you want to continue? Input Y to continue and input N to break£º";
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

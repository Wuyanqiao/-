#include <iostream>
#include "Math.h"

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0;
	while (true) 
	{
		std::cout << "Which function do you want to use£¿\n";
		std::cout << "Please input 1(Dot Product) or 2(Cross Product) to choose function!\n";
		std::cin >> choice1;
		std::cout << "------------------------------------------------------------------------------\n";

		if (choice1 == 1) 
		{
			dotProduct();

			std::cout << "Input 1 to choose another function or input anyother number to break£º";
			std::cin >> choice2;
			std::cout << "------------------------------------------------------------------------------\n";

			if (choice2 == 1)
			{
				continue;
			}
			else
			{
				std::cout << "Break!/n";
				break;
			}
		}
		else if (choice1 == 2) 
		{
			crossProduct();

			std::cout << "Input 1 to choose another function or input anyother number to break£º";
			std::cin >> choice3;
			std::cout << "------------------------------------------------------------------------------\n";

			if (choice3 == 1)
			{
				continue;
			}
			else
			{
				std::cout << "Break!\n";
				std::cout << "------------------------------------------------------------------------------\n";
				break;
			}
		}
		else 
		{
			std::cout << "Error,Please choose the function again!";
			std::cout << "------------------------------------------------------------------------------\n";
			continue;
		}
	}
}

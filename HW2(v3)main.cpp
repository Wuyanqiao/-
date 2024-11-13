#include <iostream>
#include "Vector.h"

int main()
{
     while (true)
    {
        int N = 0;
        std::cout << "Please input N (0 < N < 10): ";
        std::cin >> N;
        
        if (N <= 0)
        {
            std::cout << "N is negative or zero! Break!" << std::endl;
            break;
        }
        else if (N >= 10)
        {
            std::cout << "N is too large! Please input it again: ";
            std::cin >> N;
            continue;
        }

        // Allocate memory for the arrays after obtaining a valid N
        float* array1 = new float[N] {0};
        float* array2 = new float[N] {0};

        // Input arrays
        for (int i = 0; i < N; ++i)
        {
            std::cout << "Please input your " << i + 1 << " num in array1: ";
            std::cin >> array1[i];
        }
        for (int i = 0; i < N; ++i) // Changed to start from i = 0
        {
            std::cout << "Please input your " << i + 1 << " num in array2: ";
            std::cin >> array2[i];
        }

        // Function calls
        dotproduct(array1, array2, N);
        if (N == 3)
        {
            std::cout << "Processing crossproduct:\n";
            crossproduct(array1, array2, N);
        }

        // Clean up memory
        delete[] array1;
        delete[] array2;
        continue;
    }

    return 0;
}

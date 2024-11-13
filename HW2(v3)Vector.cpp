#include <iostream>
#include "Vector.h"

int dotproduct(float array1[], float array2[], int N)
{
    float dotproductresult = 0;
    for (int i = 0; i < N; ++i)
    {
        dotproductresult += array1[i] * array2[i];
    }
    std::cout << "Dot product result is: " << dotproductresult << std::endl;
    return 0;
}

int crossproduct(float array1[], float array2[], int N)
{
    if (N != 3)
    {
        std::cerr << "Cross product is only defined for 3D vectors." << std::endl;
        return -1;
    }

    float crossresult[3] = { 0 };
    crossresult[0] = array1[1] * array2[2] - array1[2] * array2[1];
    crossresult[1] = array1[2] * array2[0] - array1[0] * array2[2];
    crossresult[2] = array1[0] * array2[1] - array1[1] * array2[0];

    std::cout << "Cross product result: [" << crossresult[0] << ", " << crossresult[1] << ", " << crossresult[2] << "]" << std::endl;
    return 0;
}
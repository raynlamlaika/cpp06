

#include <iostream>

#include  "iter.hpp"
#include <vector>

int main()
{
    std::vector<int> my; // Declares an empty vector of integers.
    std::vector<int> vec(5); // Declares a vector of 5 integers, initialized to 0.
    int tors[5] = {10, 20, 30, 40, 50}; // Declares and initializes.


    iter<int>(tors, 5, func);
    return 0;
}
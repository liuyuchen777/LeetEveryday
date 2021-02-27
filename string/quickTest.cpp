#include <iostream>
#include <vector>
#include "string.h"

int main()
{
    using Matrix = std::vector<std::vector<int>>;

    Matrix mat(3, vector<int>(3, 0));

    print_vec(mat);
}
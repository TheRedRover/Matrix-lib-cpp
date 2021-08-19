#include "pdmatrix.hh"

#include <iostream>

int main()
{
    Matrix<int> matrix = Matrix<int>({1,2,3,4,5,6},2,3);

    std::cout<<(matrix(0,2)==3)<<"\n";
    matrix(0,2) = 6;
    std::cout<<(matrix(0,2)==6)<<"\n";
}


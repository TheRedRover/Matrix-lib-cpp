#include "pdmatrix.hh"

#include <iostream>

int main()
{
    Matrix<double> m2 = Matrix<double>({1,2,3,4,5,6},2,3);

    Matrix<double> matrix = Matrix<double>({1,2,3,4,5,6},2,3);


    std::cout<<(matrix(0,2)==3)<<"\n";
    matrix(0,2) = 6;
    std::cout<<(matrix(0,2)==6)<<"\n";

    matrix+=m2;
    std::cout<<(matrix(1,2)==12)<<"\n";

    std::cout<<matrix;    
}


#include <array>
#include <iostream>
#include <type_traits>

template <int N, int M, typename T, typename Enable = void>
struct Matrix;

template <int N, int M, typename T>
struct Matrix<N,M, T, typename std::enable_if<std::is_integral<T>::value>::type>
{
    using matrix = std::array<T, M*N>;

    private: matrix matrix_;

    public: auto operator()(const unsigned int i,const unsigned int j) -> T& {
        return matrix_[i*M+j];
    }
};

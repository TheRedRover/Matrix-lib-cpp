#include <array>
#include <iostream>
#include <type_traits>

template <int N, int M, typename T>
struct Matrix
{
    static_assert(std::is_integral<T, "incorrect type for matrix declaration");
    using matrix = std::array<T, M*N>;

    private: matrix matrix_;

    public: auto operator()(const unsigned int i,const unsigned int j) -> T& {
        return matrix_[i*M+j];
    }
};

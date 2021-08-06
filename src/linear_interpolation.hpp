#ifndef CODE_KATA_LINEAR_INTERPOLATION_HPP
#define CODE_KATA_LINEAR_INTERPOLATION_HPP

#include <stdexcept>

template <typename Tx, typename Ty>
Ty linear_interpolation(Tx const x1, Tx const x2, Ty const y1, Ty const y2, Tx const x)
{
    if (x1 > x2)
    {
        throw std::invalid_argument{"x values are not ordered"};
    }
    if (x < x1 || x > x2) {
        throw std::invalid_argument { "x range outside range." };
    }
    if (x == x1) {
        return y1;
    }
    if (x == x2) {
        return y2;
    }

    return y1 + (y2 - y1)/(x2 - x1) *(x- x1);

    // fake impl
    return 42.0;
}

#endif // CODE_KATA_LINEAR_INTERPOLATION_HPP

#ifndef CODE_KATA_LINEAR_INTERPOLATION_HPP
#define CODE_KATA_LINEAR_INTERPOLATION_HPP

#include <stdexcept>

template <typename Tx, typename Ty>
Ty linear_interpolation(Tx const x0, Tx const x1, Ty const y0, Ty const y1, Tx const x)
{
    if (x0 > x1)
    {
        throw std::invalid_argument{"x values are not ordered"};
    }
    if (x < x0 || x > x1) {
        throw std::invalid_argument { "x range outside range." };
    }
    if (x == x0) {
        return y0;
    }
    if (x == x1) {
        return y1;
    }

    return y0 + (y1-y0)/(x1-x0) *(x-x0);

    // fake impl
    return 42.0;
}

#endif // CODE_KATA_LINEAR_INTERPOLATION_HPP

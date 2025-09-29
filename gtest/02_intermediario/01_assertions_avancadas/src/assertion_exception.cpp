#include "assertion_exception.hpp"

double mySqrt(double input)
{
    if(input < 0)
    {
        throw std::runtime_error("Negative argument!");
    }

    return sqrt(input);
}

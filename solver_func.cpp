# include <stdio.h>
# include <assert.h>
# include <math.h>
# include "solver_func.h"
# include "basic_func.h"



//! @brief  function get parametrs and solve equal
//!
//! @param a[in] double  first coefficient in square equation
//! @param b[in] double  second coefficient in square equation
//! @param c[in] double  third coefficient in square equation
//! @param x1[out] double* pointer to x1
//! @param x2[out] double* pointer to x2
//! @return int     how much roots in this equal
//!
//!
int solve_square_func(double a, double b, double c, double* x1, double* x2)
{

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (is_zero(a))
    {
        if (is_zero(b))
        {
            if (is_zero(c))
            {
                return inf_roots;
            }
            return 0;
        }
        *x1 = *x2 = - c / b;
        return 1;
    }

    double d = b * b - 4 * a * c;

    if (is_zero(d))
    {
        *x1 = *x2 = -b / (2 * a);
        return 1;
    }

    if (d < 0) return 0;
    double sqrt_d = sqrt(d);

    *x1 = (-b - sqrt_d) / (2 * a);
    *x2 = (-b + sqrt_d) / (2 * a);

    return 2;
}

#ifndef SOLVER_FUNC_H_INCLUDED
#define SOLVER_FUNC_H_INCLUDED


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
int solve_square_func(double a, double b, double c, double* x1, double* x2);



const static int inf_roots = -1;


#endif // SOLVER_FUNC_H_INCLUDED

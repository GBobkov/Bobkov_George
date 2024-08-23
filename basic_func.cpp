#include <math.h>
#include <stdio.h>
#include "basic_func.h"

//! @brief double number can't be accuracy compared
//!
//! @param x[in] double
//! @return int     1 if x == 0, else 0
//!
//!
int is_zero(double x)
{
    const double proximity_pozitive_null = 0.0000001;
    return  fabs(x) < proximity_pozitive_null;
}




//! @brief function which clean buffer from symbols
//!
//! @param void
//! @return void
//!
//!
void clean_reading_boofer(void)
{
    int clean = getchar();
    while (clean != '\n')
    {
        clean = getchar();
        if (clean == EOF) return;
    }
}


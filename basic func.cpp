#include <math.h>


extern const double proximity_pozitive_null = 0.0000001;


extern int is_zero(double x)
{
    return  fabs(x) < proximity_pozitive_null;
}

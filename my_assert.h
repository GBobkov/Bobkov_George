#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdlib.h>


#define assert(expression) if (!(expression)) {printf("Assertion failed: " #expression ", file %s, line %d.", __FILE__, __LINE__); exit(1);}



#endif



# include <stdio.h>
# include <math.h>
# include <assert.h>

const int inf_roots = -1;
const double proximity_pozitive_null = 0.000000001;

int solve_square_func(double a, double b, double c, double* x1, double* x2);
int is_zero(double x);
int reading_cooficients(double* a, double* b, double* c);


int main()
{
    double a = 0, b = 0, c = 0;
    printf("Write down cooficients in format a b c:\n");

    reading_cooficients(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int n_roots = solve_square_func(a, b, c, &x1, &x2);

    switch (n_roots)
    {
        case 0: printf("There is no roots!");
                break;
        case 1: printf("There is one root: %lg.", x1);
                break;
        case 2: printf("There is two roots: %lg, %lg.", x1, x2);
                break;
        case inf_roots: printf("There is infinity roots!");
                break;
        default: printf("Error: nRoots = %d", n_roots);
    }

}

int is_zero(double x)
{
    return  abs(x) < proximity_pozitive_null;
}

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
        *x1 = *x2 = -c / b;
        return 1;
    }

    if (d < 0) return 0;
    double sqrt_d = sqrt(d);
    *x1 = (-b - sqrt_d) / (2 * a);
    *x2 = (-b + sqrt_d) / (2 * a);

    return 2;
}



int reading_cooficients(double* a, double* b, double* c)
{
    while (scanf("%lg %lg %lg", a, b, c) != 3){
        printf("Wrong input! Try again!\n");
        printf("Write down cooficients in format a b c:\n");
        while (getchar() != '\n');
    }
}
int reading_cooficients(double* a, double* b, double* c);

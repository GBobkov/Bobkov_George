# include <stdio.h>
# include <math.h>
# include <assert.h>
# include <stdlib.h>
#


const int inf_roots = -1;
const double proximity_pozitive_null = 0.0000001;

int solve_square_func(double a, double b, double c, double* x1, double* x2);

int is_zero(double x);

bool reading_cooficients(double* a, double* b, double* c);

int test_of_solver(struct example_for_test test);

void error(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2);

bool check_solver_by_tests(void);
struct example_for_test
{
    int n_of_test;

    double a, b, c;

    int n_roots;
    double root1, root2;
};


struct example_for_test tests[] = {
    // n, a, b, c, r, x1, x2
      {1, 0, 0, 0, inf_roots, 0, 0},
      {2, 0, 1, 0, 1, 0, 0},
      {3, 0, 0, 1, 0, 0, 0},
      {4, 1, 1, 1, 0, 0, 0},
      {5, 2, 3, 1, 2, 0.5, -1},
      {6, 2, -5, 3, 2, 1.5, 1},
      {7, 1, 2, 1, 1, -1, -1},
      {8, 1.5, 3.33, -0.01, 2, 0.0029989517, -2.22299895178147},
      {9, 0, 0.33, -0.2, 1, -0.2/0.33, -0.2/0.33},
      {10, 1.0, 0., -4, 2, -2, -2},
      {11, 1.0, 0, 4, 0, 0, 0},
      {12, 0, 2, 1, 1, -0.5, -0.5},
      {13, 2, 1, 0, 2, -0.5, 0}
    };

int main()
{

    assert(check_solver_by_tests());

    printf("Write down coeficients in format a b c:\n");

    double a = 0, b = 0, c = 0;

    bool flag = reading_cooficients(&a, &b, &c);

    if (flag) return 1;

    double x1 = 0, x2 = 0;
    int n_roots = solve_square_func(a, b, c, &x1, &x2);

    switch (n_roots)
    {
        case 0: printf("There is no roots!");
                break;
        case 1: printf("There is one root: %lg.", x1);
                break;
        case 2: printf("There are two roots: %lg, %lg.", x1, x2);
                break;
        case inf_roots: printf("There are infinity roots!");
                break;
        default: printf("Error: nRoots = %d", n_roots);
    }

}

int is_zero(double x)
{
    return  fabs(x) < proximity_pozitive_null;
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


bool reading_cooficients(double* a, double* b, double* c)
{

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("Wrong input! Try again!\n");
        printf("Write down cooficients in format a b c:\n");

        int clean = getchar();
        while (clean != '\n')
        {
            clean = getchar();
            if (clean == EOF) return true;
        }
    }

    return false;
}



int test_of_solver(struct example_for_test test)
{
    int test_n_roots = 0;
    double x1 = 0, x2 = 0;
    test_n_roots = solve_square_func(test.a, test.b, test.c, &x1, &x2);
    if ((test_n_roots != test.n_roots) || (~is_zero(x1 - test.root1)) || (~is_zero(x2 - test.root2)) )
    {

        error(test_n_roots, x1, x2,
              test.n_roots, test.root1, test.root2);
        printf("Params: a = %lg, b = %lg, c = %lg. Test %d.\n", test.a, test.b, test.c, test.n_of_test);

        return test.n_of_test;
    }
    return 0;
}


void error(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2)

{
    printf("Error!   Expected: n_roots = %d, x1 = %lg, x2 = %lg\n"
                   "\t Output:  n_roots = %d, x1 = %lg, x2 = %lg\n",
                   expctd_n_roots, expct_x1,expctd_x2,
                   out_n_roots, out_x1, out_x2);
    printf("\n");
}


bool check_solver_by_tests(void)
{
    int flag = 0;
    bool correct = true;
    for (int i = 0; i < 13; i++)
    {
        flag = test_of_solver(tests[i]);
        if (flag) correct = false;
    }
    return correct;
}


#include "solver_func.cpp"


extern int test_solver(struct example_for_test test);

extern void error_of_test(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2);

extern bool check_solver_by_tests(void);

struct example_for_test
{
    int n_of_test;

    double a, b, c;

    int n_roots;
    double root1, root2;
};


extern const struct example_for_test tests[] = {
    // n, a, b, c, r, x1, x2
      {1, 0, 0, 0, inf_roots, 0, 0},
      {2, 0, 1, 0, 1, 0, 0},
      {3, 0, 0, 1, 0, 0, 0},
      {4, 1, 1, 1, 0, 0, 0},
      {5, 2, 3, 1, 2, -1, -0.5},
      {6, 2, -5, 3, 2, 1, 1.5},
      {7, 1, 2, 1, 1, -0.5, -0.5},
      {8, 1.5, 3.33, -0.01, 2, -2.22299895178147, 0.0029989517},
      {9, 0, 0.33, -0.2, 1, 0.2/0.33, 0.2/0.33},
      {10, 1.0, 0., -4, 2, -2, 2},
      {11, 1.0, 0, 4, 0, 0, 0},
      {12, 0, 2, 1, 1, -0.5, -0.5},
      {13, 2, 1, 0, 2, -0.5, 0}
    };



extern int test_solver(struct example_for_test test)
{
    int test_n_roots = 0;
    double x1 = 0, x2 = 0;
    test_n_roots = solve_square_func(test.a, test.b, test.c, &x1, &x2);
    if ((test_n_roots != test.n_roots) || (!is_zero(x1 - test.root1)) || (!is_zero(x2 - test.root2)) )
    {

        error_of_test(test_n_roots, x1, x2,
              test.n_roots, test.root1, test.root2);
        printf("Params: a = %lg, b = %lg, c = %lg. Test %d.\n\n\n", test.a, test.b, test.c, test.n_of_test);

        return test.n_of_test;
    }
    return 0;
}


extern void error_of_test(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2)

{
    printf("Error!   Expected: n_roots = %d, x1 = %lg, x2 = %lg\n"
                   "\t Output:   n_roots = %d, x1 = %lg, x2 = %lg\n",
                   expctd_n_roots, expct_x1,expctd_x2,
                   out_n_roots, out_x1, out_x2);
}


extern bool check_solver_by_tests(void)
{
    int flag = 0;
    bool correct = true;
    for (int i = 0; i < 13; i++)
    {
        flag = test_solver(tests[i]);
        if (flag) correct = false;
    }
    return correct;
}

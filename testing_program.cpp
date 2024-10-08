# include <stdio.h>
# include <stdlib.h>
# include "testing_program.h"
# include "solver_func.h"
# include "basic_func.h"
# include "colorful_print.h"





//! @brief      if one test is wrong function print comment
//!
//! @param  int out_n_roots[in]
//! @param  double out_x1[in]
//! @param  double out_x2[in]
//! @param  int expctd_n_roots[in]
//! @param  double expct_x1[in]
//! @param  double expctd_x2[in]
//! @return void
//!
//!
static void error_of_test(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2);




//! @brief          function stop program and write comment if file data is wrong
//!
//! @param void
//! @return void
//!
//!
static void error_of_reading_file(void);





//! @brief  struct contains tests data
//! @param  int n_of_test           number of test
//! @param  double a, b, c          params in equal
//! @param  int n_roots             amount of roots
//! @param  double root1, root2     it's roots (root1 = root2 = 0 if it's INF roots or no roots)
//!
//!
struct example_for_test
{
    int n_of_test;

    double a, b, c;

    int n_roots;
    double root1, root2;
};




static struct example_for_test tests[100] = {
    // n, a, b, c, r, x1, x2
      {1, 0, 0, 0, inf_roots, 0, 0},
      {2, 0, 1, 0, 1, 0, 0},
      {3, 0, 0, 1, 0, 0, 0},
      {4, 1, 1, 1, 0, 0, 0},
      {5, 2, 3, 1, 2, -1, -0.5},
      {6, 2, -5, 3, 2, 1, 1.5},
      {7, 1, 2, 1, 1, -1, -1},
      {8, 1.5, 3.33, -0.01, 2, -2.22299895178147, 0.0029989517},
      {9, 0, 0.33, -0.2, 1, 0.2/0.33, 0.2/0.33},
      {10, 1.0, 0., -4, 2, -2, 2},
      {11, 1.0, 0, 4, 0, 0, 0},
      {12, 0, 2, 1, 1, -0.5, -0.5},
      {13, 2, 1, 0, 2, -0.5, 0}
    };

//! @brief          amount tests in massive of structs
//!
//!
static int number_tests_in_struct = 13;





//! @brief          index of the next position in massive of structs
//!
//!
static int last_test = 13;







//! @brief  function which get struct of tests and put them in solve_square_func()
//! @param                  test[in] struct example_for_test
//! @return int             0 if test is correct else number of incorrect test
//!
//!
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




//!int out_n_roots[in]
//!double out_x1[in]
//!double out_x2[in]
//!int expctd_n_roots[in]
//!double expct_x1[in]
//!double expctd_x2[in]
//! @return void
//!
//!
static void error_of_test(int out_n_roots, double out_x1, double out_x2,
            int expctd_n_roots, double expct_x1, double expctd_x2)

{


    printf("Error!   Expected: n_roots = %d, x1 = %lg, x2 = %lg\n"
                   "\t Output:   n_roots = %d, x1 = %lg, x2 = %lg\n",
                   expctd_n_roots, expct_x1,expctd_x2,
                   out_n_roots, out_x1, out_x2);
}




//! @brief      function start checking by all tests
//!
//! @param void
//! @return bool  true if all tests are correct
//!
//!
bool check_solver_by_tests(void)
{
    int flag = 0;
    bool correct = true;
    for (int i = 0; i < last_test; i++)
    {

        flag = test_solver(tests[i]);
         if (flag) correct = false;
    }
    return correct;
}




//! @brief          function reads tests from file to struct
//!
//! @param          ptr_f FILE*[in]
//! @return bool    true if reading is success false if not
//!
//!
bool reading_coeficients_from_file_to_struct(FILE *ptr_f)
{
    // n, a, b, c, r, x1, x2
    int n = 1;
    double a = 0, b = 0, c = 0;
    int r = 0;
    double x1, x2;

    while (true)
    {
        if (fscanf(ptr_f, "%d %lg %lg %lg %d %lg %lg" ,&n, &a, &b, &c, &r, &x1, &x2) != 7)
        {


            int sym = getc(ptr_f);
            if (sym == EOF)
            {
                fclose(ptr_f);
                return true;
            }

            error_of_reading_file();
            return false;


        }

        int last_c = getc(ptr_f);
        while (last_c == ' ') last_c = getc(ptr_f);




        if (last_c == EOF)
        {
            tests[last_test++] = {n, a, b, c, r, x1, x2};


            fclose(ptr_f);
            return true;
        }


        if (last_c != '\n') {error_of_reading_file(); return false;}

        tests[last_test++] = {n, a,b,c,r,x1,x2};


    }

}






//! @brief          print error
//!
//! @param void
//! @return void
//!
//!
static void error_of_reading_file(void)

{
    change_consol_color(COLOR_RED);
    printf("Wrong input from file in line = %d.", last_test - number_tests_in_struct + 1);
    change_consol_color(COLOR_WHITE);

}






# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "assert.h"
# include <math.h>
# include "testing_program.h"
# include "solver_func.h"
# include "basic_func.h"
# include "colorful_print.h"
# include "ProgrammSquareSolver.h"












//! @brief main function
//!
//! @param argc int
//! @param argv char**
//! @return int 0 if no errors else !0
//!
//!
int main(int argc, char **argv)
{
    bool exit_flag = false;
    exit_flag = user_command(argc, argv);


    if (!exit_flag) return 1;


    printf("Write down coefficients in format a b c:\n");



    double a = 0, b = 0, c = 0;
    exit_flag = reading_coeficients_from_terminal(&a, &b, &c);
    if (exit_flag) return 1;



    double x1 = 0, x2 = 0;
    int n_roots = solve_square_func(a, b, c, &x1, &x2);



    print_answer(n_roots, x1, x2);




    return 0;
}





//! @brief func which write number from user to pointer (input should be correct)
//! @param a[in] double*  first coefficient in square equation
//! @param b[in] double*  second coefficient in square equation
//! @param c[in] double*  third coefficient in square equation
//! @return bool True if read is reading is successfully.
//!
//!
bool reading_coeficients_from_terminal(double* a, double* b, double* c)
{

    while (scanf("%lg %lg %lg", a, b, c) != 3)
    {
        printf("Wrong input! Try again!\n");
        printf("Write down coefficients in format a b c:\n");

        clean_reading_boofer();
    }

    return false;
}



//! @brief                      execute user's command
//!
//! @param arg_count int        number of commands
//! @param arg_vector char**    commands
//! @return bool                true if all ok else if it has errrors
//!
//!
bool user_command(int arg_count, char** arg_vector)
{
    if (arg_count >= 2)
    {
        if (strcmp(arg_vector[1], "-t") == 0)
        {

            FILE *fp;
            fp = fopen("data.txt","r");

            assert(fp);
            if (!reading_coeficients_from_file_to_struct(fp)) exit(1);
            assert(check_solver_by_tests());

            change_consol_color(COLOR_GREEN);
            printf("All Tests are correct!\n");
            change_consol_color(COLOR_WHITE);
        }
        else
         {
            change_consol_color(COLOR_RED);
            printf("Unsupportable command! Exit.");
            change_consol_color(COLOR_WHITE);
            return false;
        }

    }


    return true;
}



//! @brief `                print answer
//!
//! @param roots_n int      amount of roots
//! @param x1 double        first root
//! @param x2 double        second root
//! @return void
//!
//!
void print_answer(int roots_n, double x1, double x2)
{
    switch (roots_n)
    {
        case 0: change_consol_color(COLOR_RED);
                printf("There are no roots!");
                break;
        case 1: change_consol_color(COLOR_GREEN);
                printf("There is one root: %lg.", x1);
                break;
        case 2: change_consol_color(COLOR_BLUE);
                printf("There are two roots: %lg, %lg.", x1, x2);
                break;
        case inf_roots: change_consol_color(COLOR_PURPLE);
                        printf("There are infinity roots!");
                        break;
        default:    change_consol_color(COLOR_ORANGE);
                    printf("Error: nRoots = %d", roots_n);
    }
    change_consol_color(COLOR_WHITE);
}

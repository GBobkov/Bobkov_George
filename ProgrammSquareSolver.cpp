# include <stdlib.h>
# include "testing program.cpp"


bool reading_cooficients(double* a, double* b, double* c);




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




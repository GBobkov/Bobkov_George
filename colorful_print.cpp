# include "colorful_print.h"

void change_consol_color(char *mode)
{
    unsigned int n = 5;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    n = color_mode(mode);
    SetConsoleTextAttribute(hConsole, n);
}



int color_mode(char *mode)
{
    if (strcmp(mode,"blue") == 0) return 3;
    else if (strcmp(mode,"orange") == 0) return 6;
    else if (strcmp(mode,"red") == 0 ) return 4;
    else if (strcmp(mode,"yellow") == 0) return 10;
    else if (strcmp(mode, "pink") == 0)return 5;
    else if (strcmp(mode, "white")== 0) return 15;
    else if (strcmp(mode, "green") == 0) return 2;
    else if (strcmp(mode, "purple") == 0) return 1;
    else if (strcmp(mode, "gray") == 0) return 15;
    return 5;

}

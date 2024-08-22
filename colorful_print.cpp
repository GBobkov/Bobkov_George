# include "colorful_print.h"

void change_consol_color(int mode)
{

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, mode);

}



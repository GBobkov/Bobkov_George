# include "colorful_print.h"

//! @brief change color text in consol
//!
//! @param mode colors[in] number which is defenition of color
//! @return void
//!
//!
void change_consol_color(colors mode)
{

    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, mode);

}



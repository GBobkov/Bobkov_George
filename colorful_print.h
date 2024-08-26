# ifndef COLORFUL_PRINT_H
# define COLORFUL_PRINT_H

# include <windows.h>
# include <stdio.h>




//! @brief        COLOR = NUMBER
//!
enum colors {COLOR_PURPLE = 1, COLOR_GREEN = 2, COLOR_BLUE = 3, COLOR_RED = 4, COLOR_PINK = 5,
            COLOR_ORANGE, COLOR_GRAY = 8, COLOR_YELLOW = 10, COLOR_WHITE = 15};





//! @brief change color text in console
//!
//! @param mode colors[in] number which is definition of color
//! @return void
//!
//!
void change_consol_color(colors mode);


#endif

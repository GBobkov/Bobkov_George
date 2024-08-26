//! @brief func which write number from user to pointer (input should be correct)
//! @param a[in] double*  first coefficient in square equation
//! @param b[in] double*  second coefficient in square equation
//! @param c[in] double*  third coefficient in square equation
//! @return bool True if read is reading is successfully.
//!
//!
bool reading_cooficients_from_terminal(double* a, double* b, double* c);



//! @brief                      execute user's command
//!
//! @param arg_count int        number of commands
//! @param arg_vector char**    commands
//! @return bool                true if all ok else if it has errrors
//!
//!
bool user_command(int arg_count, char** arg_vector);





//! @brief `                print answer
//!
//! @param roots_n int      amount of roots
//! @param x1 double        first root
//! @param x2 double        second root
//! @return void
//!
//!
void print_answer(int roots_n, double x1, double x2);

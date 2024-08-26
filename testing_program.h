#ifndef TESTING_PROGRAM_H_INCLUDED
#define TESTING_PROGRAM_H_INCLUDED



//! @brief  function which get struct of tests and put them in solve_square_func()
//! @param                  test[in] struct example_for_test
//! @return int             0 if test is correct else number of incorrect test
//!
//!
int test_solver(struct example_for_test test);






//! @brief      function start checking by all tests
//!
//! @param void
//! @return bool  true if all tests are correct
//!
//!
bool check_solver_by_tests(void);





//! @brief          function reads tests from file to struct
//!
//! @param          ptr_f FILE*[in]
//! @return bool    true if reading is success
//!
//!
bool reading_coeficients_from_file_to_struct(FILE *ptr_f);




#endif // TESTING_PROGRAM_H_INCLUDED

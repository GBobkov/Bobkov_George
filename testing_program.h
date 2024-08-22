#ifndef TESTING_PROGRAM_H_INCLUDED
#define TESTING_PROGRAM_H_INCLUDED


int test_solver(struct example_for_test test);
bool check_solver_by_tests(void);
bool reading_coeficients_from_file_to_struct(FILE *ptr_f);

#endif // TESTING_PROGRAM_H_INCLUDED

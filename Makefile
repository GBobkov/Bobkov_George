.PHONY: all Release Debug  сlean doxygen

all: ProgrammSquareSolver.exe
Release: run_dir/SquareSolverProject.exe
Debug: run_dir/SquareSolverProject.exe

сlean:
	rm $(DIROBJFILES)



OBJFILES := testing_program.o solver_func.o ProgrammSquareSolver.o colorful_print.o basic_func.o
FLAGS := -Werror -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code  -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

DIROBJFILES := $(addprefix obj/, $(OBJFILES))



doxygen:
	doxygen


run_dir/SquareSolverProject.exe : $(DIROBJFILES)
	g++ $(FLAGS) $(DIROBJFILES) -o $@





obj/%.o : %.cpp
	g++ $< -c  -o $@



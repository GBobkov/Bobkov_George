.PHONY: all Release Debug  сlean doxygen

all: ProgrammSquareSolver.exe 
Release: ProgrammSquareSolver.exe
Debug: ProgrammSquareSolver.exe

сlean:
	rm $(DIROBJFILES)



OBJFILES := testing_program.o solver_func.o ProgrammSquareSolver.o colorful_print.o basic_func.o
DIROBJFILES := $(addprefix obj/tst/, $(OBJFILES) )


doxygen:
	doxygen 


ProgrammSquareSolver.exe : $(DIROBJFILES)
	g++ $(DIROBJFILES) -o ProgrammSquareSolver.exe





obj/tst/%.o : %.cpp
	g++ $< -c  -o $@


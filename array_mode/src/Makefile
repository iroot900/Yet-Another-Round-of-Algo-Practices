#compile and test
SRC+=$(wildcard *.c++)

OBJ=$(SRC:.cc=.o)

CXX=g++
CXXFLAG=-Wall -Werror -std=c++11

a.out : $(OBJ) 
	$(CXX) $(CXXFLAG) -o $@ $^


.PHONY:clean
clean:
	rm -r *.o 

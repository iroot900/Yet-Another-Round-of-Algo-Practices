#compile and test
SRC+=$(wildcard *.java)

OBJ=$(SRC:.java=.class)
CLS=$(OBJ:.class=);

CXX=javac

$(OBJ) : $(SRC) 
	$(CXX) $^

run:
	java $(CLS)

.PHONY:clean
clean:
	rm -r *.class 

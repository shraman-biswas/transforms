CXX	=	gcc
FLAGS	=	-Wall -O3 -ggdb
LIBS	=	-lm -lplplotd
SOURCE	=	main.c dft/dft.c siggen/siggen.c
BIN	=	main

all:
	$(CXX) $(FLAGS) $(SOURCE) -o $(BIN) $(LIBS)

clean:
	rm -f *~ *o $(BIN)

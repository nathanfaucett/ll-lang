CC := clang++

OPT_LVL := -O2

SRC := ./src
AST := ./src/ast
FLAGS := -std=c++98 $(OPT_LVL) -I$(SRC) -I$(AST) -Wall


all: build_test run_test

run_test:
	./test/main

build_test: build_lib.o
	$(CC) $(FLAGS) ./test/lib.o ./test/main.cpp -o ./test/main

build_lib.o:
	$(CC) $(FLAGS) -c ./src/lib.cpp -o ./test/lib.o

clean:
	$(RM) ./test/main **/*.o **/*~
	$(RM) -rf deps

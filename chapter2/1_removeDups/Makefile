CC = g++
CTCI = ../..
MAIN = $(CTCI)/tests_main.o

EXECUTABLES = tests

all: $(EXECUTABLES)

SRC = removedups.cpp

tests: $(SRC)
	$(CC) $(MAIN) $(SRC) -o tests && ./tests -r compact

src: $(SRC)
	$(CC) $(SRC) -c

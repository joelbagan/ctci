CC = g++
CTCI = ../..
MAIN = $(CTCI)/tests_main.o

EXECUTABLES = tests

all: $(EXECUTABLES)

SRC = threeinone.cpp

tests: $(SRC)
    $(CC) $(MAIN) $(SRC) -o tests && ./tests -r compact
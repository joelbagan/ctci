CC = g++
CTCI = ..
MAIN = $(CTCI)/tests_main.o

EXECUTABLES = dll_tests

all: $(EXECUTABLES)

SRC = linkedlist_tests.cpp dll_node.h

dll_tests: $(SRC)
	$(CC) $(MAIN) $(SRC) -o dll_tests; ./dll_tests

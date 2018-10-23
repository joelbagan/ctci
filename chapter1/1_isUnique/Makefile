CC = gcc -m32
OS=linux
CFLAGS = -m32 -g -I$(KHOME)/include -I.

EXECUTABLES = 

all: $(EXECUTABLES)

#header files
INCL = 

#c files
CFILES = 

#.o files
USER = 
kos: $(USER) $(MAIN) $(LIB) $(INCL)
	$(CC) $(CFLAGS) -o kos $(MAIN) $(USER) $(LIB) 

.c.o: $(INCL) $(CFILES)
	$(CC) -c $(CFLAGS) $*.c

clean:
	rm -f *.o core $(EXECUTABLES)

CC = gcc
CFLAGS = -Wall

all: main

# Static library with fred and john
libstatic.a: fred.o john.o
	ar rcs libstatic.a fred.o john.o

# Shared library with bill and sam
libshared.so: bill.o sam.o
	$(CC) -shared -o libshared.so bill.o sam.o -lm

# Compile main program
main.o: main.c
	$(CC) -c main.c

main: main.o libstatic.a libshared.so
	$(CC) -o main main.o -L. -lstatic -lshared -Wl,-rpath,@loader_path -lm

# Interposed shared library
libinterpose.so: bill_interpose.o sam_interpose.o
	$(CC) -shared -o libinterpose.so bill_interpose.o sam_interpose.o -lm

# Interposed static object
fred_interpose.o: fred_interpose.c
	$(CC) -c fred_interpose.c

john_interpose.o: john_interpose.c
	$(CC) -c john_interpose.c

# Test program with interposed fred and john
interposed_main: main.o fred_interpose.o john_interpose.o libshared.so
	$(CC) -o interposed_main main.o fred_interpose.o john_interpose.o -L. -lshared -lm

clean:
	rm -f *.o *.a *.so main interposed_main
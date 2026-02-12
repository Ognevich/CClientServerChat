CC = gcc
CFLAGS = -Wall

OBJ = main.o 

all: main.exe

main.exe: $(OBJ)
	$(CC) $(OBJ) -o main.exe

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o main.exe

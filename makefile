CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror
OBJ = calculator.o terminal.o clear.o writeFile.o LinkedList.o
EXEC = calculator

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

program.o : calculator.c terminal.h condition.h clear.h
	$(CC) $(CFLAGS) calculator.c -c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) terminal.c -c

clear.o : clear.c clear.h
	$(CC) $(CFLAGS) clear.c -c

writeFile.o : writeFile.c writeFile.h
	$(CC) $(CFLAGS) writeFile.c -c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) LinkedList.c -c

clean :
	rm-f $(EXEC) $(OBJ)

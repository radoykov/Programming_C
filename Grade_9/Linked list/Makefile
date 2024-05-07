all: task.exe

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

task.exe: linkedlist.o task.c
	gcc task.c linkedlist.o -o task.exe

clean:
	del *.exe *.o
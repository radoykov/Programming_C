all: tests.exe

tests.exe: tests.c doublelinkedlist.o
	gcc tests.c doublelinkedlist.o -o tests.exe         

doublelinkedlist.o: doublelinkedlist.h doublelinkedlist.c
	gcc -c doublelinkedlist.c -o doublelinkedlist.o

clean:
	del *.o *.exe
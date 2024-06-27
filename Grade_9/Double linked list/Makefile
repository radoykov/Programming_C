all: tests.exe stackTests.exe queueTests.exe

doublelinkedlist.o: doublelinkedlist.h doublelinkedlist.c
	gcc -c doublelinkedlist.c -o doublelinkedlist.o

tests.exe: doublelinkedlist.o tests.c
	gcc tests.c doublelinkedlist.o -o tests.exe

stack.o: stack.h stack.c
	gcc -c stack.c -o stack.o

stackTests.exe: stack.o doublelinkedlist.o stackTests.c
	gcc stackTests.c stack.o doublelinkedlist.o -o stackTests.exe

queue.o: queue.h queue.c
	gcc -c queue.c -o queue.o

queueTests.exe: queue.o doublelinkedlist.o queueTests.c
	gcc queueTests.c queue.o doublelinkedlist.o -o queueTests.exe

clean:
	del *.o *.exe
all: processes.o
	gcc taskmanager.c processes.o -o taskmanager.exe

processes.o:
	gcc -c processes.c -o processes.o

clear:
	del *.o *.exe
all: quadraticroots.o
	gcc main.c quadraticroots.o -o main.exe

quadraticroots.o: 
	gcc -c quadraticroots.c -lm -o quadraticroots.o

clear:
	del *.o *.exe
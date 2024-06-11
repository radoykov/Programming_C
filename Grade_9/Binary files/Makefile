all: task.exe

task.exe: task.c fileUtil.o people.o
	gcc task.c fileUtil.o people.o -o task.exe

people.o: people.c people.h types.h
	gcc -c people.c -o people.o

fileUtil.o: fileUtil.c fileUtil.h
	gcc -c fileUtil.c -o fileUtil.o

clean:
	del *.exe *.o *.bin
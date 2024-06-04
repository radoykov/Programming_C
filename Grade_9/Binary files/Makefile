all: task.exe

fileUtil.o: fileUtil.c fileUtil.h
	gcc -c fileUtil.c -o fileUtil.o

task.exe: task.c fileUtil.o people.h
	gcc task.c fileUtil.o -o task.exe

clean:
	del *.exe *.o
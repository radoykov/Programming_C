all: readFile.exe writeFile.exe

writeFile.exe: writeFile.c employee.o
	gcc writeFile.c employee.o -o writeFile.exe 

readFile.exe: readFile.c employee.o
	gcc readFile.c employee.o -o readFile.exe 

employee.o: employee.c employee.h
	gcc -c employee.c -o employee.o

clean:
	del *.exe *.o *.bin
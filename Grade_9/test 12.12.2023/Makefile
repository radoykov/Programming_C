make: max.exe sum.exe

max.exe:
	gcc -c helpers.c -o helpers.o
	gcc max.c helpers.o -o max.exe


sum.exe:
	gcc -c helpers.c -o helpers.o
	gcc sum.c helpers.o -o sum.exe

clean:
	del *.o *.exe
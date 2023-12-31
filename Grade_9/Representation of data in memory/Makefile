all: safeadd.exe safesubtract.exe safemultiply.exe safedivide.exe task.exe

safeadd.exe: safeint.o 
	gcc safeadd.c safeint.o -o safeadd.exe

safesubtract.exe: safeint.o 
	gcc safesubtract.c safeint.o -o safesubtract.exe

safemultiply.exe: safeint.o 
	gcc safemultiply.c safeint.o -o safemultiply.exe

safedivide.exe: safeint.o
	gcc safedivide.c safeint.o -o safedivide.exe

task.exe:
	gcc task.c -o task.exe
	
safeint.o:
	gcc -c safeint.c -o safeint.o


clean: 
	del *.o *.exe
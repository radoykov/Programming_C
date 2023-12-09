all: help.exe strlength.exe strconcat.exe strcompare.exe 

help.exe:
	gcc print.c -o print.exe

strlength.exe: mystrings.o
	gcc strlength.c mystrings.o -o strlength.exe

strconcat.exe: mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.exe

strcompare.exe: mystrings.o
	gcc strcompare.c mystrings.o -o strcompare.exe 

mystrings.o:
	gcc -c mystrings.c -o mystrings.o 

clean:
	del *.o *.exe
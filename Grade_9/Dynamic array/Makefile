all: tests.exe orphany.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

tests.exe: dynarr.o tests.c
	gcc tests.c dynarr.o -o tests.exe

orphany.exe: dynarr.o orphany.c
	gcc orphany.c dynarr.o -o orphany.exe

clean:
	del *.o *.exe
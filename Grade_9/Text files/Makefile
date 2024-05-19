all: books.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

books.exe: dynarr.o books.c
	gcc books.c dynarr.o -o books.exe

clean:
	del *.o *.exe
APC.exe: main.o apc.o add.o sub.o mul.o div.o
	gcc -o APC.exe main.o apc.o add.o sub.o mul.o div.o
main.o: main.c
	gcc -c main.c
apc.o: apc.c
	gcc -c apc.c
add.o: add.c
	gcc -c add.c
sub.o: sub.c
	gcc -c sub.c
mul.o: mul.c
	gcc -c mul.c
div.o: div.c
	gcc -c div.c
clean:
	rm *.exe *.o
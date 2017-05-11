all: p5a p5b
p5a: main.o partA.o
	gcc main.o partA.o -o p5a
main.o: main.c partA.h
	gcc -c main.c
partA.o: partA.c partA.h
	gcc -c partA.c
p5b: mainb.o partb.o
	gcc mainb.o partb.o -o p5b
mainb.o: mainb.c partb.h
	gcc -c mainb.c
partb.o: partb.c partb.h
	gcc -c partb.c
clean:
	rm -f *.o core

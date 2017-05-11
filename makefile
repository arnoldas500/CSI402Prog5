p1: main.o stats.o insert.o
	gcc main.o stats.o insert.o -o p1
main.o: main.c struct_def.h constants.h
	gcc -c main.c
stats.o: stats.c struct_def.h constants.h
	gcc -c stats.c
insert.o: insert.c struct_def.h constants.h
	gcc -c insert.c
clean:
	rm -f *.o core

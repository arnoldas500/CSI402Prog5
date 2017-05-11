p4: main.o asem.o instruct.o output.o parsing.o symTable.o hash.o
	gcc main.o asem.o instruct.o output.o parsing.o symTable.o hash.o -o p4
main.o: main.c structs.h
	gcc -c main.c
asem: assem.c structs.h
	gcc -c assem.c
instruct.o: instruct.c structs.h
	gcc -c instruct.c
output.o: output.c structs.h
	gcc -c output.c
parsing.o: parsing.c structs.h
	gcc -c parsing.c
symTable.o: symTable.c structs.h
	gcc -c symTable.c
help.o: help.c structs.h
	gcc -c help.c
hash.o: hash.c structs.h
	gcc -c hash.c
clean:
	rm -f *.o core

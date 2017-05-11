p3: main.o InitDataBase.o InitTable.o help.o queryMain.o
	gcc main.o InitDataBase.o InitTable.o help.o queryMain.o -o p3
main.o: main.c structs.h
	gcc -c main.c
InitDataBase.o: InitDataBase.c structs.h
	gcc -c InitDataBase.c
InitTable.o: InitTable.c structs.h
	gcc -c InitTable.c
help.o: help.c structs.h
	gcc -c help.c
queryMain.o: queryMain.c structs.h
	gcc -c queryMain.c
clean:
	rm -f *.o core

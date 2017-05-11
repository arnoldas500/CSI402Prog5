p2: main.o printToStd.o binaryToText.o textToBinary.o
	gcc main.o printToStd.o binaryToText.o textToBinary.o -o p2
main.o: main.c
	gcc -c main.c
printToStd.o: printToStd.c
	gcc -c printToStd.c
binaryToText.o: binaryToText.c
	gcc -c binaryToText.c
textToBinary.o: textToBinary.c
	gcc -c textToBinary.c
clean:
	rm -f *.o core

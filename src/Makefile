lab1: main.o functions.o

	cc -o lab1 main.o functions.o

clean:
	rm -f *.o lab1 *# *~ .#*

run:
	./lab1

functions.o: tokenizer.h functions.c

main.o: tokenizer.h main.c

lab1: main.o functions.o history.o

	cc -o lab1 main.o functions.o history.o

clean:
	rm -f *.o lab1 *# *~ .#*

run:
	./lab1

functions.o: tokenizer.h functions.c

history.o: history.h history.c tokenizer.h

main.o: tokenizer.h history.h main.c

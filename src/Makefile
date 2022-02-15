# comments begin with #





# for convenience, define variable $(OBJS) to list of object files

OBJS= main.o functions.o



#            this rule includes $(CFLAGS) as one of cc's parameters

CFLAGS=-g -O3 # -g for debug, -O3 for optimization


all: lab1



lab1: $(OBJS)

	cc -o lab1 $(CFLAGS) $(OBJS)


$(OBJS): tokenizer.h

clean:
	rm -f *.o lab1

run:lab1

	./lab1

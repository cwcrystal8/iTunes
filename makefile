all: driver.o linkedlist.o library.o
	gcc driver.o linkedlist.o library.o

driver.o: driver.c linkedlist.h library.h
	gcc -c driver.c

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c

library.o: library.c library.h
	gcc -c library.c

clean:
	rm *.o

run:
	./a.out

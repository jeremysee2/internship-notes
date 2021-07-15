asyncDynamic.elf: main.o queue.o observer.o linkedList.o
	gcc -g main.o queue.o observer.o linkedList.o -o asyncDynamic.elf
	-rm *.o
main.o: main.c queue.h linkedList.h observer.h
	gcc -c -g main.c -o main.o

queue.o: queue.c queue.h
	gcc -c -g queue.c -o queue.o

linkedList.o: linkedList.c linkedList.h observer.h queue.h
	gcc -c -g linkedList.c -o linkedList.o

observer.o: observer.c observer.h queue.h
	gcc -c -g observer.c -o observer.o

clean:
	-rm *.o asyncDynamic.elf
main:consumer.o producer.o task.o main.o
	gcc $(CFLAGS) consumer.o producer.o task.o main.o -o main
main.o:main.c
	gcc $(CFLAGS) -c -lpthread main.c
consumer.o:consumer.c
	gcc $(CFLAGS) -c -lpthread consumer.c
producer.o:producer.c
	gcc $(CFLAGS) -c -lpthread producer.c
task.o:task.c
	gcc $(CFLAGS) -c -lpthread task.c


.PHONY:clean
clean:
	-rm *.o main
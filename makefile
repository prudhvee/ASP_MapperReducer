CC = gcc
CFLAGS = -c

all:
	$(CC) mapper.c -o mapper.out
	$(CC) reducer.c -o reducer.out
	$(CC) combiner.c -o combiner.out

mapper: mapper.c
	$(CC) $(CFLAGS) mapper.c
	$(CC) mapper.c -o mapper.out

reducer: reducer.c
	$(CC) $(CFLAGS) reducer.c
	$(CC) reducer.c -o reducer.out

combiner: combiner.c
	$(CC) $(CFLAGS) combiner.c
	$(CC) combiner.c -o combiner.out
	
clean:	
	rm mapper.out reducer.out combiner.out

CC = gcc
CFLAGS = -g

objects = temp_api.o main.o
prog: $(objects)
	$(CC) $^ -o prog

$(objects): %.o: %.c
	$(CC) -c $^ -o $@

clean:
	rm -rf *.o prog
CC = gcc
CFLAGS = -g

objects = temp_api.o main.o db.o
all: $(objects)
	$(CC) $(CFLAGS) $^ -o prog

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o prog
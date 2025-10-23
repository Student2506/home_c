CC = gcc
CFLAGS = -g -D__USE_MINGW_ANSI_STDIO -Wall -Wextra -Werror -std=gnu99
LDFLAGS =

objects = main.o original_methods.o service_functions.o solution_methods.o
all: $(objects)
	$(CC) $(CFLAGS) $^ -o main $(LDFLAGS)

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LDFLAGS)

clean:
	rm -rf *.o main
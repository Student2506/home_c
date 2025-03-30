CC = gcc
CFLAGS = -g -D__USE_MINGW_ANSI_STDIO -Wall -Wextra -Werror -std=gnu99
LDFLAGS = -lintl.dll -liconv

objects = temp_api.o main.o db.o
all: $(objects)
	$(CC) $(CFLAGS) $^ -o prog $(LDFLAGS)

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LDFLAGS)

clean:
	rm -rf *.o prog
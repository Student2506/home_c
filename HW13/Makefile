CC = gcc
CFLAGS = -g -D__USE_MINGW_ANSI_STDIO -Wall -Wextra -Werror -std=gnu99
LDFLAGS = -lintl.dll -liconv

objects = temp_api.o main.o db.o parser.o
all: $(objects)
	$(CC) $(CFLAGS) $^ -o prog $(LDFLAGS)

$(objects): %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(LDFLAGS)

strings: $(objects:.o=.c)
	xgettext --keyword=_ --language=C --add-comments --sort-output -o po/sensor_reader.pot $^
	msgmerge --update po/fr/sensor_reader.po po/sensor_reader.pot
	msgmerge --update po/ru/sensor_reader.po po/sensor_reader.pot

translation:
	msgfmt --output-file=po/fr/sensor_reader.mo po/fr/sensor_reader.po
	msgfmt --output-file=po/ru/sensor_reader.mo po/ru/sensor_reader.po
	cp po/ru/sensor_reader.mo ru/LC_MESSAGES/
	cp po/fr/sensor_reader.mo fr/LC_MESSAGES/

clean:
	rm -rf *.o prog
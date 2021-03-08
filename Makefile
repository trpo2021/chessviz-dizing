CFLAGS = -Wall -Werror


APP_SOURCES = $(shell find src -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/%.c=obj/%.o)


bin/chessviz: $(APP_OBJECTS)
	gcc $(CFLAGS) $< -o $@


obj/%.o: src/%.c
	gcc -c $(CFLAGS) $< -o $@


clean:
	rm bin/*
	rm obj/*
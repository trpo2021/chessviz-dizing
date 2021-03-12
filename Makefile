CFLAGS = -Wall -Werror -I src -MP -MMD


APP_SOURCES = $(shell find src/chessviz -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/chessviz/%.c=obj/chessviz/%.o)

LIB_SOURCES = $(shell find src/libchessviz -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/libchessviz/%.c=obj/libchessviz/%.o)
LIB_PATH = obj/libchessviz/libchessviz.a

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

-include $(DEPS)

bin/chessvizRun: $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

obj/chessviz%.o: src/chessviz%.c
	gcc -c $(CFLAGS) $< -o $@

obj/libchessviz%.o: src/libchessviz%.c
	gcc -c $(CFLAGS) $< -o $@


clean:
	rm $(APP_OBJECTS) $(LIB_PATH) $(LIB_OBJECTS) bin/chessvizRun $(DEPS)
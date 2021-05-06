CFLAGS = -Wall -Werror -I src -I thirdparty -MP -MMD


APP_SOURCES = $(shell find src/chessviz -name '*.c')
APP_OBJECTS = $(APP_SOURCES:src/chessviz/%.c=obj/chessviz/%.o)

LIB_SOURCES = $(shell find src/libchessviz -name '*.c')
LIB_OBJECTS = $(LIB_SOURCES:src/libchessviz/%.c=obj/libchessviz/%.o)
LIB_PATH = obj/libchessviz/libchessviz.a

TEST_SOURCES = $(shell find test -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:test/%.c=obj/test/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

-include $(DEPS)


.PHONY: all
all: bin/chessvizRun

bin/chessvizRun: $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

obj/chessviz/%.o: src/chessviz/%.c
	gcc -c $(CFLAGS) $< -o $@

obj/libchessviz/%.o: src/libchessviz/%.c
	gcc -c $(CFLAGS) $< -o $@


.PHONY: test
test: bin/chessvizTest

bin/chessvizTest: $(TEST_OBJECTS) $(LIB_PATH) 
	gcc $(CFLAGS) $^ -o $@

obj/test/%.o: test/%.c
	gcc -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm $(APP_OBJECTS) $(LIB_PATH) $(LIB_OBJECTS) bin/chessvizRun bin/chessvizTest $(DEPS) $(TEST_OBJECTS)

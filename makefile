PROGRAM := DSA

CC := clang
CFLAGS := -Wall -Wextra -Iinclude -Ilib/unity/src -g

SRC := $(shell find src -name "*.c")
OBJ := $(patsubst src/%.c,build/%.o,$(SRC))

# === Main Program Rules ===

build/%.o: src/%.c | build
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bin/$(PROGRAM): $(OBJ) | bin
	$(CC) $(CFLAGS) $^ -o $@

# === Test ===
UNITY_OBJ := build/test/unity.o
UNITY_SRC := lib/unity/src/unity.c

TEST_SRC := $(shell find test -name "*.c")
TEST_OBJ := $(patsubst test/%.c,build/test/%.o,$(TEST_SRC))

LIB_SRC := $(filter-out src/main.c, $(SRC))
LIB_OBJ := $(patsubst src/%.c,build/%.o,$(LIB_SRC))

bin/test: $(LIB_OBJ) $(TEST_OBJ) $(UNITY_OBJ) | bin
	$(CC) $(CFLAGS) $^ -o $@

build/test/%.o: test/%.c | build/test
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/test/unity.o: $(UNITY_SRC) | build
	$(CC) $(CFLAGS) -c $< -o $@

# === Directories & Files ===

build:
	@mkdir -p build

build/test: build
	@mkdir -p build/test

bin:
	@mkdir -p bin

compile_commands.json:
	bear -- make


# === Shortcuts ===

all: bin/$(PROGRAM) compile_commands.json

clean:
	rm -rf build bin compile_commands

run: bin/$(PROGRAM)
	@./$<

test: bin/test
	@./$<



.PHONY: all clean run test compile_commands.json

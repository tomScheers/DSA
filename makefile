PROGRAM = DSA

CC := clang
CFLAGS := -Wall -Wextra -Iinclude -Ilib/unity/src
SRC := $(wildcard src/*.c)
LIB_SRC := $(filter-out src/main.c, $(SRC))
APP_OBJ := build/main.o
LIB_OBJ := $(patsubst src/%.c, build/%.o, $(LIB_SRC))
BIN := bin/$(PROGRAM)

# Include test runner file explicitly
TEST_SRC := $(wildcard test/*.c)
UNITY_SRC := lib/unity/src/unity.c
TEST_OBJ := $(patsubst test/%.c, build/test/%.o, $(TEST_SRC)) build/unity.o $(LIB_OBJ)
TEST_BIN := bin/test

# === Default build ===
all: $(BIN) compile_commands.json

# === Build app binary ===
$(BIN): $(APP_OBJ) $(LIB_OBJ) | bin
	$(CC) $(CFLAGS) $^ -o $@

# === Build test binary ===
$(TEST_BIN): $(TEST_OBJ) | bin
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/test/%.o: test/%.c | build/test
	$(CC) $(CFLAGS) -c $< -o $@

build/unity.o: $(UNITY_SRC) | build
	$(CC) $(CFLAGS) -c $< -o $@

# === Directories ===
build:
	mkdir -p build

build/test:
	mkdir -p build/test

bin:
	mkdir -p bin

# === Compile commands ===
compile_commands.json: clean
	bear -- make $(BIN)

# === Clean everything ===
clean:
	rm -rf build bin compile_commands.json

# === Build and run test ===
test: $(TEST_BIN)
	@./$(TEST_BIN)

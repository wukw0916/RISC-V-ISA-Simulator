# gcc compiler
CC = gcc

# Compile-time flags
CFLAGS = -O3 -std=c99 -ggdb -Wall -flto

all: build/eGP01_Simulator

build/eGP01_Simulator: src/main.o src/simulator.o src/instructions.o
	@mkdir $(@D) 2>/dev/null || true
	$(CC) $^ $(CFLAGS) -o $@

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/instructions/%.o: tests/instructions/%.c tests/instructions/test_main.h
	$(CC) $(CFLAGS) -c $< -o $@

tests/instructions/%: src/instructions.o tests/instructions/%.o
	$(CC) $^ -o $@

tests/simulation/%.o: tests/simulation/%.c tests/simulation/test_main.h
	$(CC) $(CFLAGS) -c $< -o $@

tests/simulation/%: src/instructions.o src/simulator.o tests/simulation/%.o
	$(CC) $^ -o $@

tests/c_code/%: tests/c_code/%.mem build/eGP01_Simulator
	./build/eGP01_Simulator --load-file $< --verbose

tests/c_code/%.mem: tests/c_code/%.c
	./tools/c_to_mem $<

clean:
	-rm -rf src/*.o tests/*/*.o build
	-git clean -dfX

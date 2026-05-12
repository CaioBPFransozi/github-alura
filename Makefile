all: BIN_FOLDER main.o
	gcc -o bin/bin build/main.o

main.o: BUILD_FOLDER
	gcc -o build/main.o -c src/main.c

BIN_FOLDER:
	mkdir -p bin

BUILD_FOLDER:
	mkdir -p build

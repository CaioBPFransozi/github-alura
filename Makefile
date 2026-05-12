.PHONY: clean all

OBJS = main.o
BIN_FOLDER = bin
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: BIN_FOLDER $(OBJS)
	gcc -o $(BIN_FOLDER)/bin $(BUILD_FOLDER)/main.o

main.o: BUILD_FOLDER
	gcc -o $(BUILD_FOLDER)/main.o -c $(SOURCE_FOLDER)/main.c

BIN_FOLDER:
	mkdir -p $(BIN_FOLDER)

BUILD_FOLDER:
	mkdir -p $(BUILD_FOLDER)

clean:
	rm $(BUILD_FOLDER)/*

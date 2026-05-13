.PHONY: clean all

OBJS = main.o
BIN_FOLDER = bin
RELEASE_FOLDER = $(BIN_FOLDER)/release
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: BIN_FOLDER $(OBJS)
	gcc -o $(BIN_FOLDER)/bin $(BUILD_FOLDER)/main.o

release: RELEASE_FOLDER $(OBJS)
	gcc -O2 -o $(RELEASE_FOLDER)/release $(BUILD_FOLDER)/main.o

main.o: BUILD_FOLDER
	gcc -O2 -o $(BUILD_FOLDER)/main.o -c $(SOURCE_FOLDER)/main.c

BIN_FOLDER:
	mkdir -p $(BIN_FOLDER)

RELEASE_FOLDER:
	mkdir -p $(RELEASE_FOLDER)

BUILD_FOLDER:
	mkdir -p $(BUILD_FOLDER)

clean:
	rm $(BUILD_FOLDER)/*

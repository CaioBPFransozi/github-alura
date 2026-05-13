.PHONY: clean all

OBJS = main.o readline.o trim.o
CFLAGS = -Wall -Werror
BIN_FOLDER = bin
RELEASE_FOLDER = $(BIN_FOLDER)/release
BUILD_FOLDER = build
SOURCE_FOLDER = src

all: BIN_FOLDER $(OBJS)
	gcc $(CFLAGS) -o $(BIN_FOLDER)/bin $(BUILD_FOLDER)/main.o $(BUILD_FOLDER)/readline.o $(BUILD_FOLDER)/trim.o

release: CFLAGS += -O2

release: all

main.o: BUILD_FOLDER
	gcc $(CFLAGS) -o $(BUILD_FOLDER)/main.o -c $(SOURCE_FOLDER)/main.c

readline.o: BUILD_FOLDER
	gcc $(CFLAGS) -o $(BUILD_FOLDER)/readline.o -c $(SOURCE_FOLDER)/readline.c

trim.o: BUILD_FOLDER
	gcc $(CFLAGS) -o $(BUILD_FOLDER)/trim.o -c $(SOURCE_FOLDER)/trim.c

BIN_FOLDER:
	mkdir -p $(BIN_FOLDER)

RELEASE_FOLDER:
	mkdir -p $(RELEASE_FOLDER)

BUILD_FOLDER:
	mkdir -p $(BUILD_FOLDER)

clean:
	rm $(BUILD_FOLDER)/*

# universify installer
CC = gcc
SRC = src
BIN = bin
FILES = $(SRC)/main.c $(SRC)/get.c $(SRC)/utils.c
NAME = sit
OUTPUT = $(BIN)/$(NAME)
DIR = /usr/bin

build:
	$(CC) $(FILES) -o $(OUTPUT)

install:
	make build
	cp -f $(OUTPUT) $(DIR)/$(NAME)
	echo "Successfully installed $(NAME)."

uninstall:
	rm -f $(DIR)/$(NAME)
	echo "Successfully uninstalled $(NAME)."



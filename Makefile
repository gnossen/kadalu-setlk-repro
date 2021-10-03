.phony: all
all: repro

repro: main.c
	gcc -Wall main.c -o repro

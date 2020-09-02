#!/bin/bash -x

CC=gcc

all: test

test:test.o
	$(CC) -g -o $@ $^ -L../opus-tools-git/.libs -lopusdec_api

%.o:%.c
	$(CC) -fPIC -I../opusapi -c -o $@ $<

.PHONY:

clean:
	rm -f test.o test

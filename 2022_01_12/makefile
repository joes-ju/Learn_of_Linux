.PHONY:all
all:mytest
mytest:test.c mystdio.h mystdio.c
	gcc -o $@ $^ -g -std=c99

.PHONY:clean
clean:
	rm -f mytest


test:
	gcc -o test main.c -lm

libtest:
	gcc -shared -o bin/libtest.dll $(wildcard src/*.c) -lm -msse2

travis: libtest
	gcc -o test travis_test.c -lm -msse2
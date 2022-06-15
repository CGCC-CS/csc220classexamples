all: stringsargs

stringsargs: projecthelp.c
	gcc --std=c11 -pedantic -Wall stringsargs.c -o stringsargs

clean:
	rm -f *.o *.exe *.out stringsargs *~

greet:
	echo "Hello `whoami`"
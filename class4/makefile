all: stringsarg 

stringsarg: stringsargs.c
	gcc --std=c11 -Wall -pedantic stringsargs.c -o stringsarg

clean:
	rm -f *.o *.exe *.out stringsarg *.s *~

greeting:
	echo "Hi, `whoami`"
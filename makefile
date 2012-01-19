GCC = gcc -Wall -Os -O2
#GCC = gcc -Wall -g

build: clean linkedlist brainfuck
	$(GCC) -o brainfuck linkedlist.o brainfuck.o
	
linkedlist:
	$(GCC) -c linkedlist.c -o linkedlist.o

brainfuck:
	$(GCC) -c brainfuck.c -o brainfuck.o

documentation:
	gzip -c docs/brainfuck.1 --best > brainfuck.1.gz 

clean:
	rm -f *.o
	rm -f brainfuck
	rm -f brainfuck.1.gz

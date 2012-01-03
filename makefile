GCC = gcc -Wall -Os -O2
#GCC = gcc -Wall -g

build: linkedlist brainfuck
	$(GCC) -o brainfuck linkedlist.o brainfuck.o
	
linkedlist:
	$(GCC) -c linkedlist.c -o linkedlist.o

#debugger:
#	$(GCC) -c bfdebug.c -o bfdebug.o

brainfuck:
	$(GCC) -c brainfuck.c -o brainfuck.o

documentation:
	gzip -c docs/brainfuck.1 --best > brainfuck.1.gz 

clean:
	rm *.o
	rm brainfuck

cleanbuild: clean build

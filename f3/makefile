#_____________________________________________________________
# handling all the files via syntax

objects := foo.o bar.o all.o
CC = gcc

all: $(objects)
	$(CC) $^ -o $@

# syntax = targets ... " target-pattern : prereq-patterns

$(objects): %.o: %.c 
	$(CC) -c $^ -o $@

all.c:
	echo "int main() {return 0;}" > all.c

%.c:
	touch $@

clean:
	rm -rf *.o all *.c

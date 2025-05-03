#_____________________________________________________________
# cc = gcc # preferred c compiler
# LDFLAGS = # Linker flags (eg, -L/path/to/libs)
# LDLIBS = # Libraries to link (eg, -lm for math library)
# TARGET = n

# all : $(TARGET)

# $(TARGET) : $(TARGET).o
# 	$(CC) ${LDFLAGS} $< ${LDLIBS} -o $@ 	

# $(TARGET).o : $(TARGET).c
# 	$(CC) -c $< -o $@

# clean: rm -rf $(TARGET) $(TARGET).o

#_____________________________________________________________
# handling all files one by one

objects := foo.o bar.o all.o
CC = gcc

all: $(objects)
	$(CC) $^ -o $@

foo.o: foo.c
	$(CC) -c $< -o $@

bar.o: bar.c
	$(CC) -c $< -o $@

all.o: all.c
	$(CC) -c $< -o $@

all.c:
	echo "int main() {return 0;}" > $@

foo.c:
	touch $@

bar.c:
	touch $@

clean:
	rm -rf *.o all *.c
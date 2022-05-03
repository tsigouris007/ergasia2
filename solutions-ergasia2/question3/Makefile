CC=gcc
CFLAGS=-I.
DEPS = tree.h
OBJ = tree.o main.o
MAIN = main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv $@ $(MAIN)

clean:
	rm -rf $(OBJ) $(MAIN)

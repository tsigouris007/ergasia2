CC=gcc
CFLAGS=-I.
DEPS = Item_base.h Item.h BST.h
OBJ = Item.o BST.o main.o
MAIN = main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv $@ $(MAIN)

clean:
	rm -rf $(OBJ) $(MAIN)

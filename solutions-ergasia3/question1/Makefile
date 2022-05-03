CC=gcc
CFLAGS=-I.
DEPS = filehandler.h helper.h edge.h graph.h
OBJ = filehandler.o helper.o edge.o graph.o main.o
MAIN = main

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	mv $@ $(MAIN)

clean:
	rm -rf $(OBJ) $(MAIN)

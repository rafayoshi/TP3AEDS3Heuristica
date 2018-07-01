CC = gcc
CFLAGS = -Wall -Werror
OBJ = main.o forcabruta.o
DEPS = forcabruta.h
VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes
EXEC = ./tp3fb < TesteHeuristica/entrada9.txt
TIMED_RUN = time ./tp3fb

all: tp3fb

tp3fb: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o tp3fb forcabruta.

valgrind:
	valgrind $(VFLAGS) $(EXEC)
run:
	$(EXEC)
timed:
	$(TIMED_RUN)

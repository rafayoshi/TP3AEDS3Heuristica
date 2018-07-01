CC = gcc
CFLAGS = -Wall -Werror
OBJ = main.o
VFLAGS = --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes
EXEC = ./tp3h
TIMED_RUN = time ./tp3h

all: tp3h

tp3h: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o tp3h

valgrind:
	valgrind $(VFLAGS) $(EXEC)
run:
	$(EXEC)
timed:
	$(TIMED_RUN)

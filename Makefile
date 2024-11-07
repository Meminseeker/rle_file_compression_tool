# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Target executable
TARGET = main

# Default rule
all: run

run: $(TARGET)
	./$(TARGET)

compile: $(TARGET)

# Rule to build the target
$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

# Rule to create object file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Rule to clean up
clean:
	rm -f $(TARGET) *.o

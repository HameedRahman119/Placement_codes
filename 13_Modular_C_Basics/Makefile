CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = array_stats

all: $(TARGET)

$(TARGET): main.o array_utils.o
	$(CC) $(CFLAGS) main.o array_utils.o -o $(TARGET)

main.o: main.c array_utils.h
	$(CC) $(CFLAGS) -c main.c

array_utils.o: array_utils.c array_utils.h
	$(CC) $(CFLAGS) -c array_utils.c

clean:
	rm -f $(TARGET) *.o

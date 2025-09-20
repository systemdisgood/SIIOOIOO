#CC=clang++
CC=gcc
CFLAGS=-c -Wall -pedantic -std=c89 
LDFLAGS=
SOURCES=siiooioo.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=siiooioo.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	rm ./*.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


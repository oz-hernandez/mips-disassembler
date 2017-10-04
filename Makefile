

CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := bin/runner
OBJECTS := Decoder.o Format.o IType.o RType.o main.o

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
CFLAGS := -g -Wall
INC := -I include

$(TARGET): $(OBJECTS)
	@echo linking…
	$(CC) $^ -o $(TARGET)
	rm -r $(OBJECTS)

$(OBJECTS): $(SOURCES)
	@echo compiling…
	$(CC) $(CFLAGS) $(INC) -c $(SOURCES)

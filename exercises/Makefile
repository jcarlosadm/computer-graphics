LIBS  = -lGLU -lGL -lglut
CFLAGS = -Wall
CC = g++

# Should be equivalent to your list of C files, if you don't build selectively
SRC=$(wildcard *.c)

objects = blocks windmill
all: $(objects)

$(objects): %: %.c ; $(CC) $< -o $@ $(CFLAGS) $(LIBS)

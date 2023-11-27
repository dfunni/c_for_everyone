CC=gcc
CFLAGS=-Wall -g

SRCS = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SRCS))

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)
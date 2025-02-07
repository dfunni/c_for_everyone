CC=g++

SRCS = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SRCS))

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)
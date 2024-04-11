
LINK.o = $(LINK.cc)
CXXFLAGS = -std=c++20 -Wall -Wextra -g
MAIN = main

all: correctness persistence

correctness: kvstore.o correctness.o

persistence: kvstore.o persistence.o

kvstore : kvstore.o 

$(MAIN):  kvstore.o main.o
	$(CXX) -o $@ $^

clean:
	-rm -f correctness persistence *.o

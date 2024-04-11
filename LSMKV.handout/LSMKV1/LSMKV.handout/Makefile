
LINK.o = $(LINK.cc)
CXXFLAGS = -std=c++14 -Wall
MAIN = main

all: correctness persistence

correctness: kvstore.o correctness.o

persistence: kvstore.o persistence.o

kvstore : kvstore.o 

$(MAIN):  kvstore.o main.o
	$(CXX) -o $@ $^

clean:
	-rm -f correctness persistence *.o

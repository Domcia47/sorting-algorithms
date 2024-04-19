CXX := g++
CXXFLAGS := -Wall -o3 -march=native
LDFLAGS := -s
LDLIBS := -lm

# Lista plików źródłowych i docelowych
SOURCES := BubbleSort.cpp SelectionSort.cpp InsertionSort.cpp Generator.cpp
EXECUTABLES := BubbleSort.x SelectionSort.x InsertionSort.x Generator.x

# Pliki obiektowe
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean make

all: $(EXECUTABLES)


BubbleSort.x: BubbleSort.o
SelectionSort.x: SelectionSort.o
InsertionSort.x: InsertionSort.o 
Generator.x: Generator.o

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

make: $(OBJECTS) $(EXECUTABLES)

clean:
	$(RM) $(EXECUTABLES) $(OBJECTS)


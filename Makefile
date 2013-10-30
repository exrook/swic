CXX = clang++
CXXFLAGS = -std=c++11 -g
LDFLAGS =
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = swic

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

.cpp:.o
	$(CXX) $(CFLAGS) -c -o $@ $<
.PHONY: clean
	
clean:
	rm -r $(OBJECTS)

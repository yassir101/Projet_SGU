CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = sgu
LDLIBS = -lsqlite3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(EXEC) $(OBJ)


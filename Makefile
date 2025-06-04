CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
SRC = $(wildcard src/*.cpp)
OBJDIR = obj
OBJ = $(patsubst src/%.cpp,$(OBJDIR)/%.o,$(SRC))
EXEC = sgu
LDLIBS = -lsqlite3

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

$(OBJDIR)/%.o: src/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(EXEC) $(OBJDIR)


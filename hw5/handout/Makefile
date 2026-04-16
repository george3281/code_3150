CXX      := g++
CXXFLAGS := -std=c++17 -g -Wall -Wextra -pedantic

TARGET   := solution
SRC      := solution.cpp

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

test: $(TARGET)
	python3 -m pytest test_game.py

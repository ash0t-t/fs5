CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17
TARGET := manual-append
SRC := manual-append.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
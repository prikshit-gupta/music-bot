
CXX := g++

CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Iinclude

LDFLAGS := -L/usr/local/lib -ldpp -pthread

SRCS := main.cpp music_queue.cpp

TARGET := aurax_music

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean

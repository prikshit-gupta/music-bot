CXX := g++

CXXFLAGS := -std=c++17 -O2 -Wall -Wextra -Iinclude

LDFLAGS := -Wl,-Bstatic -ldpp -Wl,-Bdynamic -pthread

SRCS := main.cpp music_queue.cpp

TARGET := app

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
LDFLAGS := -ldpp -pthread

SRC := main.cpp \
       music_queue.cpp \
       audio_player.cpp \
       music_commands.cpp

TARGET := aurax_music

all:
	$(CXX) $(CXXFLAGS) -Iinclude $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

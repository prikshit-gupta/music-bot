CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall -Wextra
LDFLAGS := -ldpp -pthread

SRC := src/main.cpp \
       src/music_queue.cpp \
       src/audio_player.cpp \
       src/music_commands.cpp

TARGET := aurax_music

all:
	$(CXX) $(CXXFLAGS) -Iinclude $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

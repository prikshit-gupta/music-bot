#pragma once

#include <string>
#include <queue>
#include <mutex>

namespace aurax {

struct Track {
    std::string url;
    std::string title;
    uint64_t requester;
};

class MusicQueue {
private:
    std::queue<Track> tracks;
    mutable std::mutex mutex;

public:
    void add(const Track& track);
    bool next(Track& track);
    void clear();
    size_t size() const;
};

}

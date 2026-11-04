#include "music_queue.hpp"

namespace aurax {

void MusicQueue::add(const Track& track)
{
    std::lock_guard<std::mutex> lock(mutex);
    tracks.push(track);
}

bool MusicQueue::next(Track& track)
{
    std::lock_guard<std::mutex> lock(mutex);

    if (tracks.empty())
        return false;

    track = tracks.front();
    tracks.pop();

    return true;
}

void MusicQueue::clear()
{
    std::lock_guard<std::mutex> lock(mutex);

    std::queue<Track> empty;
    tracks.swap(empty);
}

size_t MusicQueue::size() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return tracks.size();
}

}

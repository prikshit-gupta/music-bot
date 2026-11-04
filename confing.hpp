#pragma once

#include <cstdint>
#include <cstdlib>
#include <string>

namespace aurax {

inline constexpr uint64_t MUSIC_ROLE_ID = 123ULL;

inline std::string getToken()
{
    const char* token = std::getenv("DISCORD_TOKEN");

    if (!token)
        return {};

    return token;
}

}

#pragma once

#include <cstdint>
#include <cstdlib>
#include <string>

namespace aurax {

inline constexpr uint64_t MUSIC_ROLE_ID = 1563569384893587616ULL;

inline std::string getToken()
{
    const char* token = std::getenv("MTU2NTY4ODc5Nzg1OTk0NjU0Nw.GG6eMb.sglRzo8aDEUumNNjMln4cGn5O_wqWglcMnz9C8
    ");

    if (!token)
        return {};

    return token;
}

}

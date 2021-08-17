#pragma once

// This concept is borrowed from SerenityOS (https://github.com/SerenityOS/serenity/blob/1682f0b760c736e7bbb62bea86248bd83579bec7/AK/Badge.h).
// See also: https://awesomekling.github.io/Serenity-C++-patterns-The-Badge. 

namespace HLU {

template<typename T>
class Badge {
private:
    friend T;
    constexpr Badge() = default;
    
    Badge(const Badge&) = delete;
    Badge& operator=(const Badge&) = delete;

    Badge(Badge&&) = delete;
    Badge& operator=(Badge&&) = delete;
};

}

using HLU::Badge;

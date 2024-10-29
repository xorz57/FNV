#pragma once

#include <cstdint>

namespace fnv0 {
    constexpr std::uint32_t hash32(const char* str) noexcept {
        std::uint32_t prime = 0x1000193;
        std::uint32_t hash = 0;
        for (; *str != '\0'; ++str) {
            hash = (hash * prime) ^ static_cast<std::uint32_t>(static_cast<uint8_t>(*str));
        }
        return hash;
    }

    constexpr std::uint64_t hash64(const char* str) noexcept {
        std::uint64_t prime = 0x100000001b3;
        std::uint64_t hash = 0;
        for (; *str != '\0'; ++str) {
            hash = (hash * prime) ^ static_cast<std::uint64_t>(static_cast<uint8_t>(*str));
        }
        return hash;
    }
}

namespace fnv1 {
    constexpr std::uint32_t hash32(const char* str) noexcept {
        std::uint32_t prime = 0x1000193;
        std::uint32_t offset_basis = 0x811c9dc5;
        std::uint32_t hash = offset_basis;
        for (; *str != '\0'; ++str) {
            hash = (hash * prime) ^ static_cast<std::uint32_t>(static_cast<uint8_t>(*str));
        }
        return hash;
    }

    constexpr std::uint64_t hash64(const char* str) noexcept {
        std::uint64_t prime = 0x100000001b3;
        std::uint64_t offset_basis = 0xcbf29ce484222325;
        std::uint64_t hash = offset_basis;
        for (; *str != '\0'; ++str) {
            hash = (hash * prime) ^ static_cast<std::uint64_t>(static_cast<uint8_t>(*str));
        }
        return hash;
    }
}

namespace fnv1a {
    constexpr std::uint32_t hash32(const char* str) noexcept {
        std::uint32_t prime = 0x1000193;
        std::uint32_t offset_basis = 0x811c9dc5;
        std::uint32_t hash = offset_basis;
        for (; *str != '\0'; ++str) {
            hash = (hash ^ static_cast<std::uint32_t>(static_cast<uint8_t>(*str))) * prime;
        }
        return hash;
    }

    constexpr std::uint64_t hash64(const char* str) noexcept {
        std::uint64_t prime = 0x100000001b3;
        std::uint64_t offset_basis = 0xcbf29ce484222325;
        std::uint64_t hash = offset_basis;
        for (; *str != '\0'; ++str) {
            hash = (hash ^ static_cast<std::uint64_t>(static_cast<uint8_t>(*str))) * prime;
        }
        return hash;
    }
}

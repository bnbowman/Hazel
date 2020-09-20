//
// Created by Brett Bowman on 9/12/20.
//
#pragma once

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#ifdef HZ_DEBUG
    #if defined(HZ_PLATFORM_WINDOWS)
        #define HZ_DEBUGBREAK() __debugbreak()
    #elif defined(HZ_PLATFORM_LINUX)
        #include <signal.h>
        #define HZ_DEBUGBREAK() raise(SIGTRAP)
    #elif defined(HZ_PLATFORM_MAC)
        #define HZ_DEBUGBREAK() __asm("int $3")
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
    #define HZ_ENABLE_ASSERTS 1
#else
    #define HZ_DEBUGBREAK()
#endif

// TODO: Make this macro able to take in no arguments except condition
#if HZ_ENABLE_ASSERTS == 1
    #define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); HZ_DEBUGBREAK(); } }
    #define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); HZ_DEBUGBREAK(); } }
#else
    #define HZ_ASSERT(x, ...)
    #define HZ_CORE_ASSERT(x, ...)
#endif

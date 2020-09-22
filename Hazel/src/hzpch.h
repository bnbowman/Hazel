//
// Created by Brett Bowman on 9/12/20.
//
#pragma once

#ifdef HZ_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See
// github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif

#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "Hazel/Core/Log.h"

#ifdef HZ_PLATFORM_WINDOWS
#include <Windows.h>
#endif

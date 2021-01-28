#pragma once

#include "util/download.hpp"
#include "util/logger.hpp"

namespace cppitch
{
    inline Logger* g_log = new Logger(Logger::LogLevel::Verbose);
}
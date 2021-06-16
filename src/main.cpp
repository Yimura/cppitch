#include "common.hpp"
#include <filesystem>

int main(int argc, const char** args)
{
    using namespace cppitch;

    g_log->set_log_level(Logger::LogLevel::Verbose);

    g_log->verbose("MAIN", "Attempting File Download...");

    if (argc != 3)
    {
        g_log->warning("MAIN", "No link or target download file given...");

        return 1;
    }

    auto location = std::filesystem::current_path() / args[2];
    g_log->verbose("DOWNLOAD", location.c_str());

    download::file(args[1], location.c_str());

    g_log->verbose("MAIN", "Downloaded file.");
    
    return 0;
}
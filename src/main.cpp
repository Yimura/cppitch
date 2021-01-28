#include "common.hpp"

int main()
{
    using namespace cppitch;

    g_log->set_log_level(Logger::LogLevel::Verbose);

    Download* download = new Download();

    g_log->verbose("MAIN", "Attempting File Download...");

    download->download_file();

    g_log->verbose("MAIN", "Downloaded file.");
    
    return 0;
}
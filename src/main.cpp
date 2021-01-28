#include "common.hpp"

int main()
{
    using namespace cppitch;

    Logger* log = new Logger(Logger::LogLevel::Verbose);
    Download* download = new Download();

    log->verbose("MAIN", "Attempting File Download...");

    download->download_file();

    log->verbose("MAIN", "Downloaded file.");
    
    return 0;
}
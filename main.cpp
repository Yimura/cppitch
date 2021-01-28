#include "src/util/Logger.hpp"
#include "src/util/Download.hpp"

int main()
{
    Logger* log = new Logger(Logger::LogLevel::Verbose);
    Download* download = new Download();

    log->verbose("MAIN", "Attempting File Download...");

    download->download_file();
    
    return 0;
}
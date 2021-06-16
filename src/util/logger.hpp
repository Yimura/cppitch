#pragma once
#include <cstring>
#include <iostream>

namespace cppitch
{
    class Logger
    {
    public:
        enum LogLevel {
            Verbose,
            Info,
            Warning,
            Error,
            Critical
        };

        Logger(LogLevel logLevel)
        {
            this->m_log_level = logLevel;
        }

        ~Logger()
        {
        }

        void critical(const char* service, const char* message)
        {
            this->log(LogLevel::Critical, service, message);
        }

        void error(const char* service, const char* message)
        {
            this->log(LogLevel::Error, service, message);
        }

        void info(const char* service, const char* message)
        {
            this->log(LogLevel::Info, service, message);
        }

        void verbose(const char* service, const char* message)
        {
            this->log(LogLevel::Verbose, service, message);
        }

        void warning(const char* service, const char* message)
        {
            this->log(LogLevel::Warning, service, message);
        }


        void set_log_level(LogLevel level)
        {
            this->m_log_level = level;
        }

    private:
        const char* blue = "\x1b[34m";
        const char* green = "\x1b[32m";
        const char* yellow = "\x1b[33m";
        const char* red = "\x1b[31m";
        const char* reset = "\x1b[0m";
    
        LogLevel m_log_level;

        void log(LogLevel level, const char* service, const char* message)
        {
            char color[16];
            char level_string[16];

            switch (level)
            {
            case LogLevel::Verbose:
                strcpy(color, blue);
                strcpy(level_string, "VERB");

                break;
            case LogLevel::Info:
                strcpy(color, green);
                strcpy(level_string, "INFO");

                break;
            case LogLevel::Warning:
                strcpy(color, yellow);
                strcpy(level_string, "WARN");

                break;
            case LogLevel::Error:
                strcpy(color, red);
                strcpy(level_string, "ERR");

                break;
            case LogLevel::Critical:
                strcpy(color, red);
                strcpy(level_string, "CRIT");

                break;
            }
            
            std::cout << color << "[" << level_string << "/" << service << "] " << reset << message << std::endl;
        }
    };
}

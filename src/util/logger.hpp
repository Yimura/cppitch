#pragma once

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

    Logger(LogLevel logLevel);
    ~Logger();

    void critical(const char* service, const char* message);
    void error(const char* service, const char* message);
    void info(const char* service, const char* message);
    void verbose(const char* service, const char* message);
    void warning(const char* service, const char* message);

    void set_log_level(LogLevel level);
private:
    LogLevel m_log_level;

    void log(LogLevel level, const char* service, const char* message);
};

#include "Logger.hpp"

Logger* Logger::m_instance = nullptr;

Logger::Logger()
{
    m_fileName = "log-" + GetDate() + ".txt"; // Holds the logfile name
}

Logger::~Logger()
{
}

Logger* Logger::GetInstance()
{
    // Check if there is already an instance
    if (m_instance == nullptr)
        m_instance = new Logger();
    
    return m_instance;
}

void Logger::Log(const std::string& arg_message, LOG_TYPE arg_messageType)
{
    std::string l_messageType = " [UNDEF] ";
    
    // Convert a enum to a print able string
    switch (arg_messageType) {
        case LOG_INFO:
            l_messageType = " [INFO] ";
            break;
        case LOG_DEBUG:
            l_messageType = " [DEBUG] ";
            break;
        case LOG_WARN:
            l_messageType = " [WARN] ";
            break;
        case LOG_ERROR:
            l_messageType = " [ERROR] ";
            break;
    }
    
    // Place message in logfile
    m_logFileStream.open(m_fileName, std::ofstream::app);
    m_logFileStream << GetDate() + " " + GetTime() + l_messageType + arg_message << std::endl;
    m_logFileStream.close();
}

std::string Logger::GetDate()
{
    time_t l_currentTime = time(0);
    struct tm* l_pTimeNow = localtime(&l_currentTime);
    
    std::ostringstream l_stringstream;
    l_stringstream << l_pTimeNow->tm_mday << "." << l_pTimeNow->tm_mon + 1 << "." << l_pTimeNow->tm_year + 1900;
    
    return l_stringstream.str();
}

std::string Logger::GetTime()
{
    time_t l_currentTime = time(0);
    struct tm* l_pTimeNow = localtime(&l_currentTime);
    
    std::ostringstream l_stringstream;
    l_stringstream << l_pTimeNow->tm_hour << ":" << l_pTimeNow->tm_min << ":" << l_pTimeNow->tm_sec;
    
    return l_stringstream.str();
}

#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

enum LOG_TYPE
{
    LOG_INFO,
    LOG_DEBUG,
    LOG_WARN,
    LOG_ERROR
};

// Singleton
class Logger
{
public:
    ~Logger();
    
    static Logger* GetInstance();
    void Log(const std::string& arg_message, LOG_TYPE arg_messageType);
    
private:
    Logger();
    
    static Logger* m_instance;
    std::string m_fileName;
    std::ofstream m_logFileStream;
    
    std::string GetDate();  // Returns the current date
    std::string GetTime();  // Returns the current time
    
};

#endif /* Logger_hpp */

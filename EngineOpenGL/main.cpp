#include "Logger.hpp"

int main()
{
    Logger::GetInstance()->Log("Hello World!", LOG_INFO);
    
    return 0;
}

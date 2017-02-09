#include "Logger.hpp"
#include "Kernel.hpp"

int main()
{
    Logger::GetInstance()->Log("----- Starting Engine -----", LOG_INFO);
    
    Kernel l_kernel = Kernel();
    l_kernel.RunMainLoop();
    
    Logger::GetInstance()->Log("----- Stopping Engine -----", LOG_INFO);
}

#include "Kernel.hpp"

Kernel::Kernel()
{
    Logger::GetInstance()->Log("Kernel: Created", LOG_INFO);
    
    // Create WindowManager
    // Create Renderer
}

Kernel::~Kernel()
{
    Logger::GetInstance()->Log("Kernel: Deleting", LOG_INFO);
    
    // Delete WindowManager
    // Delete Renderer
}

void Kernel::RunMainLoop()
{
    Logger::GetInstance()->Log("Kernel: Starting Mainloop", LOG_INFO);

    // Mainloop
    while (1)
    {
        
    }
}

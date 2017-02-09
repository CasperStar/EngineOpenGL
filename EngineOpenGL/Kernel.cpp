#include "Kernel.hpp"

Kernel::Kernel()
{
    Logger::GetInstance()->Log("Kernel: Created", LOG_INFO);
    
    // Create WindowManager
    m_pWindowManager = new WindowManager();
    
    // Create Renderer
}

Kernel::~Kernel()
{
    Logger::GetInstance()->Log("Kernel: Deleting", LOG_INFO);
    
    // Delete WindowManager
    delete m_pWindowManager;
    
    // Delete Renderer
}

void Kernel::RunMainLoop()
{
    Logger::GetInstance()->Log("Kernel: Starting Mainloop", LOG_INFO);

    // Create Window
    Window* l_window1 = m_pWindowManager->CreateWindow(1);
    l_window1->CreateWindow(1024, 768, "Window 1", false);
    l_window1->MakeCurrentContext();
    
    // Mainloop
    while (!l_window1->ShouldClose())
    {
        
        // OpenGL Code
        
        l_window1->SwapBuffer();
        l_window1->PollEvents();
    }
}

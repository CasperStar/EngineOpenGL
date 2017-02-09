#ifndef Kernel_hpp
#define Kernel_hpp

#include "Logger.hpp"

class Kernel
{
public:
    Kernel();
    ~Kernel();
    
    void Init();
    void RunMainLoop();
    
private:
    // WindowManager* m_pWindowManager
    // Renderer*    m_pRenderer
    
};

#endif /* Kernel_hpp */

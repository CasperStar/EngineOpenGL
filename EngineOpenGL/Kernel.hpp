#ifndef Kernel_hpp
#define Kernel_hpp

#include "Logger.hpp"

#include "Renderer.hpp"
#include "WindowManager.hpp"
#include "Window.hpp"
#include "ShaderManager.hpp"

struct Matrix4f
{
    float m[4][4];
};


class Kernel
{
public:
    Kernel();
    ~Kernel();
    
    void RunMainLoop();
    
private:
    WindowManager* m_pWindowManager;
    Renderer*   m_pRenderer;
    
};

#endif /* Kernel_hpp */

#ifndef Window_hpp
#define Window_hpp

#include "Logger.hpp"
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
    Window();
    ~Window();
    
    bool CreateWindow(int arg_width, int arg_height, const std::string& arg_rWindowTitle, bool arg_fullscreen);
    
    void MakeCurrentContext();
    void SwapBuffer();
    void PollEvents();
    bool ShouldClose();
    
private:
    GLFWwindow* m_pWindow;
};

#endif /* Window_hpp */

#include "Window.hpp"

Window::Window()
{

}

Window::~Window()
{
    glfwDestroyWindow(m_pWindow);
}

bool Window::CreateWindow(int arg_width, int arg_height, const std::string& arg_rWindowTitle, bool arg_fullscreen)
{
    // Check if fullscreen: True = PrimaryMonitor, False = nullptr
    GLFWmonitor* l_pMonitor = arg_fullscreen ? glfwGetPrimaryMonitor() : nullptr;
    
    m_pWindow = glfwCreateWindow(arg_width, arg_height, arg_rWindowTitle.c_str(), l_pMonitor, nullptr);
    if (m_pWindow != nullptr)
    {
        Logger::GetInstance()->Log("Window: Created " + arg_rWindowTitle, LOG_INFO);
        return true;
    }
    
    Logger::GetInstance()->Log("Window: Failed To Create " + arg_rWindowTitle, LOG_WARN);
    return false;
}

void Window::MakeCurrentContext()
{
    glfwMakeContextCurrent(m_pWindow);
}

void Window::SwapBuffer()
{
    glfwSwapBuffers(m_pWindow);
}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(m_pWindow);
}


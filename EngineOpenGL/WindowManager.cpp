#include "WindowManager.hpp"

WindowManager::WindowManager()
{
    if (glfwInit() != 1)
    {
        Logger::GetInstance()->Log("GLFW Init Failed", LOG_ERROR);
        glfwTerminate();
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    Logger::GetInstance()->Log("GLFW Version: " + std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(revision), LOG_INFO);
}

WindowManager::~WindowManager()
{
    // Loop through the pointer map to empty it
    std::map<unsigned int, Window*>::iterator l_it;
    for (l_it = m_windowMap.begin(); l_it != m_windowMap.end(); l_it++)
    {
        delete l_it->second;
        Logger::GetInstance()->Log("WindowManager: Removed window " + std::to_string(l_it->first), LOG_INFO);
    }
    
    m_windowMap.clear();
    
    glfwTerminate();
}

Window* WindowManager::CreateWindow(unsigned int arg_windowNumber)
{
    Window* l_pWindow = new Window();
    if (l_pWindow != nullptr)
    {
        m_windowMap.insert(std::make_pair(arg_windowNumber, l_pWindow));
        return l_pWindow;
    }
    
    return nullptr;
}

bool WindowManager::RemoveWindow(unsigned int arg_windowNumber)
{
    // Search for the window
    std::map<unsigned int, Window*>::iterator l_it = m_windowMap.find(arg_windowNumber);
    if (l_it != m_windowMap.end())
    {
        delete l_it->second;
        Logger::GetInstance()->Log("WindowManager: Removed window " + std::to_string(arg_windowNumber), LOG_INFO);
        return true;
    }
    
    // Log if the window was not found
    Logger::GetInstance()->Log("WindowManager: Failed to remove window " + std::to_string(arg_windowNumber), LOG_WARN);
    return false;
}

Window* WindowManager::GetWindow(unsigned int arg_windowNumber)
{
    // Search for the window
    std::map<unsigned int, Window*>::iterator l_it = m_windowMap.find(arg_windowNumber);
    if (l_it != m_windowMap.end())
    {
        return l_it->second;
    }
    
    // Log if the window was not found
    Logger::GetInstance()->Log("WindowManager: Failed to get window " + std::to_string(arg_windowNumber), LOG_WARN);
    return nullptr;
}

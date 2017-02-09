#ifndef WindowManager_hpp
#define WindowManager_hpp

#include "Window.hpp"
#include "Logger.hpp"
#include <map>

class WindowManager
{
public:
    WindowManager();
    ~WindowManager();
    
    Window* CreateWindow(unsigned int arg_windowNumber);
    bool RemoveWindow(unsigned int arg_windowNumber);
    Window* GetWindow(unsigned int arg_windowNumber);
    
private:
    std::map<unsigned int, Window*> m_windowMap;
    
};

#endif /* WindowManager_hpp */

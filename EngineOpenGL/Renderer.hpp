#ifndef Renderer_hpp
#define Renderer_hpp

#include "Logger.hpp"
#include "ShaderManager.hpp"
#include <GL/glew.h>
#include <vector>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    ShaderManager* GetShaderManager();
    
private:
    std::vector<GLuint> m_bufferVector;
    
    // ShaderManager
    ShaderManager* m_pShaderManager;
    
};

#endif /* Renderer_hpp */

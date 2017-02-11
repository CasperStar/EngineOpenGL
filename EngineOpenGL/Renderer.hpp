#ifndef Renderer_hpp
#define Renderer_hpp

#include "Logger.hpp"
#include "ShaderManager.hpp"
#include <GL/glew.h>
#include <vector>

enum BufferType
{
    VERTEXBUFFER,
    INDEXBUFFER
};

class Renderer
{
public:
    Renderer();
    ~Renderer();
    
    void CreateBuffer(BufferType arg_bufferType);
    
    ShaderManager* GetShaderManager();
    
private:
    std::vector<GLuint> m_bufferVector;
    
    // ShaderManager
    ShaderManager* m_pShaderManager;
    
};

#endif /* Renderer_hpp */

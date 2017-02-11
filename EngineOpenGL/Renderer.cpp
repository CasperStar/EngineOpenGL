#include "Renderer.hpp"

Renderer::Renderer()
{
    glewExperimental = true;
    if (glewInit() != GLEW_OK)
    {
        Logger::GetInstance()->Log("Renderer: Failed to init GLEW", LOG_ERROR);
    }
    
    // Check OpenGL Version
    std::stringstream stringStream;
    stringStream << "Renderer: OpenGL Version: " << glGetString(GL_VERSION);
    Logger::GetInstance()->Log(stringStream.str(), LOG_INFO);

    
    // Create ShaderManager
    m_pShaderManager = new ShaderManager();

}

Renderer::~Renderer()
{
    // Delete ShaderManager
    delete m_pShaderManager;
}

void Renderer::CreateBuffer(BufferType arg_bufferType)
{
    GLuint l_buffer;
    glGenBuffers(1, &l_buffer);
    
    switch (arg_bufferType) {
        case VERTEXBUFFER:
            glBindBuffer(GL_VERTEX_ARRAY, l_buffer);
            break;
            
        case INDEXBUFFER:
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, l_buffer);
            break;
        default:
            glDeleteBuffers(1, &l_buffer);
            Logger::GetInstance()->Log("Renderer: Failed to create buffer", LOG_WARN);
            return;
    }
    
    m_bufferVector.push_back(l_buffer);
}

ShaderManager* Renderer::GetShaderManager()
{
    return m_pShaderManager;
}


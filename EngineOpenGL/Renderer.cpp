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


ShaderManager* Renderer::GetShaderManager()
{
    return m_pShaderManager;
}


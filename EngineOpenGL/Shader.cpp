#include "Shader.hpp"

Shader::Shader()
{
  
}

Shader::~Shader()
{
    glDeleteShader(m_shaderID);
}

bool Shader::CompileShader(const std::string& arg_rShaderCode, ShaderType arg_shaderType)
{
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    switch (arg_shaderType) {
        case VertexShader:
            m_shaderID = glCreateShader(GL_VERTEX_SHADER);
            break;
        case FragmentShader:
            m_shaderID = glCreateShader(GL_FRAGMENT_SHADER);
            break;
    }
    
    // Sourcecode -> Compile
    const char* l_shaderCode = arg_rShaderCode.c_str();
    glShaderSource(m_shaderID, 1, &l_shaderCode, nullptr);
    glCompileShader(m_shaderID);
    
    // Check if compiled succesfully
    glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(m_shaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        
        std::stringstream stringStream;
        stringStream <<"Shader: Compiling Failed: " << &VertexShaderErrorMessage[0];
        Logger::GetInstance()->Log(stringStream.str(), LOG_WARN);
        
        return false;
    }
    
    Logger::GetInstance()->Log("Shader: Compiling Succesfull", LOG_INFO);
    
    return true;
}

GLuint Shader::GetShader()
{
    return m_shaderID;
}

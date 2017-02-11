#include "ShaderManager.hpp"

ShaderManager::ShaderManager()
{
    
}

ShaderManager::~ShaderManager()
{
    std::map<std::string, Shader*>::iterator l_it;
    for (l_it = m_shaderMap.begin(); l_it != m_shaderMap.end(); l_it++)
    {
        delete l_it->second;
    }
    
    m_shaderMap.clear();
}

std::string ShaderManager::LoadShader(const std::string& arg_rFilePath)
{
    std::string l_shaderCode = "";
    
    std::ifstream l_fileStream(arg_rFilePath, std::ios::in);
    if ( l_fileStream.is_open() )
    {
        std::string l_newLine = "";
        while ( getline(l_fileStream, l_newLine) )
        {
            l_shaderCode += "\n" + l_newLine;
        }
        
        l_fileStream.close();
    }
    else
    {
        Logger::GetInstance()->Log("Shader: Failed to open " + arg_rFilePath, LOG_WARN);
        return NULL;
    }
    
    Logger::GetInstance()->Log("ShaderManager: Succesfully Loaded " + arg_rFilePath, LOG_INFO);
    
    return l_shaderCode;
}

bool ShaderManager::CreateShader(const std::string& arg_rShaderName, const std::string& arg_rFilePath, ShaderType arg_shaderType)
{
    Shader* l_pShader = new Shader();
    
    if (l_pShader->CompileShader(this->LoadShader(arg_rFilePath), arg_shaderType) != true)
    {
        delete l_pShader;
        return false;
    }
    
    m_shaderMap.insert(std::make_pair(arg_rShaderName, l_pShader));
    
    return true;
}

bool ShaderManager::RemoveShader(const std::string& arg_rShaderName)
{
    // Search for right shader
    std::map<std::string, Shader*>::iterator l_it = m_shaderMap.find(arg_rShaderName);
    if (l_it != m_shaderMap.end())
    {
        delete l_it->second;
        m_shaderMap.erase(l_it);
        Logger::GetInstance()->Log("ShaderManager: Removing " + arg_rShaderName, LOG_INFO);
        return true;
    }
    
    Logger::GetInstance()->Log("ShaderManager: Failed to find " + arg_rShaderName, LOG_WARN);
    return false;
}

bool ShaderManager::CompileProgram()
{
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    m_shaderProgram = glCreateProgram();
    
    // Add Shaders to Program
    std::map<std::string, Shader*>::iterator l_it;
    for ( l_it = m_shaderMap.begin(); l_it != m_shaderMap.end(); l_it++ )
    {
        glAttachShader(m_shaderProgram, l_it->second->GetShader());
    }
    
    // Link Program
    glLinkProgram(m_shaderProgram);
    
    
    // Check the program
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &Result);
    glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(m_shaderProgram, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        
        std::stringstream stringStream;
        stringStream <<"ShaderManager: Linking Program Failed: " << &ProgramErrorMessage[0];
        Logger::GetInstance()->Log(stringStream.str(), LOG_WARN);
        
        return false;
    }
    
    
    for ( l_it = m_shaderMap.begin(); l_it != m_shaderMap.end(); l_it++ )
    {
        glDetachShader(m_shaderProgram, l_it->second->GetShader());
    }
    
    Logger::GetInstance()->Log("ShaderManager: Linking Program Succes", LOG_INFO);
    return true;
}

GLuint ShaderManager::GetProgram()
{
    return m_shaderProgram;
}

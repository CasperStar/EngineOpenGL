#ifndef ShaderManager_hpp
#define ShaderManager_hpp

#include <GL/glew.h>
#include <map>
#include "Shader.hpp"

class ShaderManager
{
public:
    ShaderManager();
    ~ShaderManager();
    
    std::string LoadShader(const std::string& arg_rFilePath);
    
    bool CreateShader(const std::string& arg_rShaderName, const std::string& arg_rFilePath, ShaderType arg_shaderType);
    bool RemoveShader(const std::string& arg_rShaderName);
    
    bool CompileProgram();
    GLuint GetProgram();
    
private:
    std::map<std::string, Shader*> m_shaderMap;
    GLuint m_shaderProgram;
    
};

#endif /* ShaderManager_hpp */

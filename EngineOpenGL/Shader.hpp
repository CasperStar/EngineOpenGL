#ifndef Shader_hpp
#define Shader_hpp

#include "Logger.hpp"
#include <fstream>
#include <sstream>
#include <gl/glew.h>
#include <string>
#include <vector>

enum ShaderType
{
    VertexShader,
    FragmentShader
};

class Shader
{
public:
    Shader();
    ~Shader();
    
    bool CompileShader(const std::string& arg_rShaderCode, ShaderType arg_shaderType);
    GLuint GetShader();
    
private:
    GLuint m_shaderID;
    
};

#endif /* Shader_hpp */

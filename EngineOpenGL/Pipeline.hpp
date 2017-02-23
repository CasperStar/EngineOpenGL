#ifndef Pipeline_hpp
#define Pipeline_hpp

#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

struct Vector3
{
    float x, y, z;
    
    Vector3(float x, float y, float z) : x(x), y(y), z(z)
    {
    };
};

class Pipeline
{
public:
    Pipeline();
    ~Pipeline();
    
    glm::mat4  SetupProjection(float arg_fov, float arg_height, float arg_width, float arg_nearClipping, float arg_farClipping);
    glm::mat4  SetupCamera(Vector3 arg_translate, Vector3 arg_lookAt, Vector3 arg_up);
    
    glm::mat4  TranslateModel(Vector3 arg_translate);
    glm::mat4  RotateModel(Vector3 arg_rotate);
    glm::mat4  ScaleModel(Vector3 arg_scale);
    
    glm::mat4 GetModelMatrix();
    glm::mat4 GetMVP();
    
private:
    glm::mat4 m_modelTranslate;
    glm::mat4 m_modelRotate;
    glm::mat4 m_modelScale;
    
    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat4 m_modelMatrix;
    
};



#endif /* Pipeline_hpp */

#include "Pipeline.hpp"

Pipeline::Pipeline()
{
}

Pipeline::~Pipeline()
{
}

glm::mat4 Pipeline::SetupProjection(float arg_fov, float arg_height, float arg_width, float arg_nearClipping, float arg_farClipping)
{
    m_projectionMatrix = glm::perspective(glm::radians(arg_fov), arg_height/arg_width, arg_nearClipping, arg_farClipping);
    return m_projectionMatrix;
}

glm::mat4 Pipeline::SetupCamera(Vector3 arg_translate, Vector3 arg_lookAt, Vector3 arg_up)
{
    m_viewMatrix = glm::lookAt(
                        glm::vec3(arg_translate.x, arg_translate.y, arg_translate.z),  // Location (X,Y,Z)
                        glm::vec3(arg_lookAt.x,    arg_lookAt.y,    arg_lookAt.z),     // Looks at origin (X,Y,Z)
                        glm::vec3(arg_up.x,        arg_up.y,        arg_up.z)          // Define up axis (X,Y,Z)
                               );
    
    return m_viewMatrix;
}

glm::mat4 Pipeline::TranslateModel(Vector3 arg_translate)
{
    m_modelTranslate = glm::translate(glm::vec3(arg_translate.x, arg_translate.y, arg_translate.z));
    return m_modelTranslate;
}

glm::mat4  Pipeline::RotateModel(Vector3 arg_rotate)
{
    m_modelRotate = glm::toMat4(glm::quat(glm::vec3(arg_rotate.x, arg_rotate.y, arg_rotate.z)));
    return m_modelRotate;
}

glm::mat4  Pipeline::ScaleModel(Vector3 arg_scale)
{
    m_modelScale = glm::scale(glm::vec3(arg_scale.x, arg_scale.y, arg_scale.z));
    return m_modelScale;
}

glm::mat4 Pipeline::GetModelMatrix()
{
    return m_modelTranslate * m_modelRotate * m_modelScale;
}

glm::mat4 Pipeline::GetMVP()
{
    return m_projectionMatrix * m_viewMatrix * GetModelMatrix();
}

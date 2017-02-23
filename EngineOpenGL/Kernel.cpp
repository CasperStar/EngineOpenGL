#include "Kernel.hpp"

#include <GL/glew.h> // Temp
#include "ShaderManager.hpp"
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


GLuint gWorldLocation;

Kernel::Kernel()
{
    Logger::GetInstance()->Log("Kernel: Created", LOG_INFO);
    
    // Create WindowManager
    m_pWindowManager = new WindowManager();
}

Kernel::~Kernel()
{
    Logger::GetInstance()->Log("Kernel: Deleting", LOG_INFO);
    
    // Delete WindowManager
    delete m_pWindowManager;
    
    // Delete Renderer
    delete m_pRenderer;
}

void Kernel::RunMainLoop()
{
    Logger::GetInstance()->Log("Kernel: Starting Mainloop", LOG_INFO);

    // Create Window
    Window* l_window1 = m_pWindowManager->CreateWindow(1);
    l_window1->CreateWindow(1024, 768, "Window 1", false);
    l_window1->MakeCurrentContext();
    

    // Create Renderer (Needs a context to be created)
    m_pRenderer = new Renderer();
    
    // Setup Shaders
    ShaderManager* l_pShaderManager = m_pRenderer->GetShaderManager();
    l_pShaderManager->CreateShader("Vert1", "vertexshader.vs", VertexShader);
    l_pShaderManager->CreateShader("Frag1", "fragmentshader.fs", FragmentShader);
    l_pShaderManager->CompileProgram();
    
    GLuint MatrixMVP = glGetUniformLocation(l_pShaderManager->GetProgram(), "MVP");
    
    // Vertex Array Object
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    
    const GLfloat Triangle1[] = {
        -1.0f, -1.0f, 0.0f,
         1.0f, -1.0f, 0.0f,
         0.0f,  1.0f, 0.0f
    };
    
    GLuint Triangle1VBO;
    glGenBuffers(1, &Triangle1VBO);
    glBindBuffer(GL_ARRAY_BUFFER, Triangle1VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle1), Triangle1, GL_STATIC_DRAW);
    
    // Set Backgroundcolor
    glClearColor(0.0f, 0.4f, 0.4f, 0.0f);
    
    // Mainloop
    while (!l_window1->ShouldClose())
    {
        // Pipeline (MVP)
        Pipeline l_pipeline = Pipeline();
        l_pipeline.SetupProjection(90.0f, 1024.0f, 768.0f, 1.0f, 100.0f);
        l_pipeline.SetupCamera(Vector3(0.0f, 0.0f, 3.0f), Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f));
        l_pipeline.ScaleModel(Vector3(1.0f, 1.0f, 1.0f));
        l_pipeline.RotateModel(Vector3(0.0f, 45.0f, 0.0f));
        l_pipeline.TranslateModel(Vector3(0.0f, 0.0f, 0.0f));
        
        glm::mat4 l_matrixMVP = l_pipeline.GetMVP();
        
        // OpenGL Code
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(l_pShaderManager->GetProgram());
        glUniformMatrix4fv(MatrixMVP, 1, GL_FALSE, &l_matrixMVP[0][0]);
        
        glEnableVertexAttribArray(0);
        
        glBindBuffer(GL_ARRAY_BUFFER, Triangle1VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glDisableVertexAttribArray(0);
        
        // GLFW Code
        l_window1->SwapBuffer();
        l_window1->PollEvents();
    }
}

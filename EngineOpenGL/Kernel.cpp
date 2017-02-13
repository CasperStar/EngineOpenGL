#include "Kernel.hpp"

#include <GL/glew.h> // Temp
#include "ShaderManager.hpp"
#include <glm/ext.hpp>

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
    
    
    // Vertex Array Object
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    // Triangle Vertices
    static const GLfloat vertices[] =
        {-1.0f, -1.0f, 0.0f,
          1.0f, -1.0f, 0.0f,
          0.0f,  1.0f, 0.0f};
    
    // Vertex Buffer Object
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    // Set Backgroundcolor
    glClearColor(0.0f, 0.4f, 0.4f, 0.0f);
    
    
    
    // Mainloop
    while (!l_window1->ShouldClose())
    {
        // OpenGL Code
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(l_pShaderManager->GetProgram());
        
        static float Scale = 0.0f;
        Scale += 0.01f;

        
        Matrix4f World;

        World.m[0][0]=cosf(Scale); World.m[0][1]=-sinf(Scale); World.m[0][2]=0.0f; World.m[0][3]=0.0f;
        World.m[1][0]=sinf(Scale); World.m[1][1]=cosf(Scale);  World.m[1][2]=0.0f; World.m[1][3]=0.0f;
        World.m[2][0]=0.0f;        World.m[2][1]=0.0f;         World.m[2][2]=1.0f; World.m[2][3]=0.0f;
        World.m[3][0]=0.0f;        World.m[3][1]=0.0f;         World.m[3][2]=0.0f; World.m[3][3]=1.0f;
        
        glUniformMatrix4fv(gWorldLocation, 1, GL_TRUE, &World.m[0][0]);
        
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glDisableVertexAttribArray(0);
        
        // GLFW Code
        l_window1->SwapBuffer();
        l_window1->PollEvents();
    }
}

#include "texture/texture.h"
#include "utils/EBO.h"
#include "utils/VAO.h"
#include "utils/VBO.h"
#include <stdbool.h>
#include <window/window.h>
#include <shader/shader.h>

// constants
#define HEIGHT 600
#define WIDTH 800

// variables
bool running = true;

// functions
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// main
int main(int argc,const char *argv[])
{
    struct VertexAttr attributes[] = {
        {0, "position"},
        {1, "texture"},
    };
    // create the window
    GLFWwindow* window;
    init_window(&window,HEIGHT , WIDTH,"Collision Test! <3" );

    // create the shader
    struct Shader shader = CreateShader("../vertexshader.glsl", "../fragmentshader.glsl",2,attributes);

    // callbacks
    glfwSetKeyCallback(window,key_callback);

    // vertex pointers
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 5 * sizeof(float),(void*)0);
    glVertexAttribPointer(1,2,GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

    unsigned int VBO = CreateVBO(VBO);
    unsigned int VAO = CreateVAO(VAO);
    unsigned int EBO = CreateEBO(EBO);

    while (running) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5, 0.2, 0.6, 1.0);
        BindShader(shader);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    return 0;
}


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        running = false;
    }
}

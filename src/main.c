#include "utils/EBO.h"
#include "utils/VAO.h"
#include "utils/VBO.h"
#include <stdlib.h>
#include <window/window.h>
#include <shader/shader.h>
#include <utils/types.h>

// constants
#define HEIGHT 600
#define WIDTH 800

// variables
bool running = true;

// functions
static void key_callback(GLFWwindow* window, i64 key, i64 scancode, i64 action, i64 mods);

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
    glfwSetKeyCallback(window , key_callback);

    // vertex pointers
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE, 5 * sizeof(float), NULL);
    glVertexAttribPointer(1,2,GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    u32 VBO = CreateVBO(VBO);
    u32 VAO = CreateVAO(VAO);
    u32 EBO = CreateEBO(EBO);

    while (running) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5, 0.2, 0.6, 1.0);
        BindShader(shader);

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    return 0;
}

static void key_callback(GLFWwindow* window, i64 key, i64 scancode, i64 action, i64 mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        running = false;
    }
}


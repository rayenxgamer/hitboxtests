#include <stdio.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <window/window.h>

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
    GLFWwindow* window;
    init_window(&window,HEIGHT , WIDTH,"Collision Test! <3" );
    glfwSetKeyCallback(window,key_callback);

    while (running) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5, 0.2, 0.6, 1.0);

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

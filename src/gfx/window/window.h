#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glfw/glfw3native.h>
#include <stdbool.h>
#include <stdio.h>

struct window{
    int height;
    int width;
    bool shown;
};

void init_window(GLFWwindow** window,int height,int width, const char* title);
void Shutdown_Window(GLFWwindow** window);
static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

cmake_minimum_required(VERSION 3.30)
project(hitboxtests)

set(CMAKE_C_STANDARD)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(hitboxtests
    src/main.c
    src/glad.c
    src/stbimage.c
    src/gfx/utils/VAO.c
    src/gfx/utils/VBO.c
    src/gfx/utils/EBO.c
    src/gfx/camera/camera.c
    src/gfx/shader/shader.c
    src/gfx/window/window.c
    src/gfx/texture/texture.c
)

target_include_directories(hitboxtests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gfx
)

target_link_directories(hitboxtests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/libglfw3.a)

target_link_libraries(hitboxtests PRIVATE
    glfw
    m
    dl
    pthread
)


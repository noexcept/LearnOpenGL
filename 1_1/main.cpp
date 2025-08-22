//
// Created by noexcept on 2025/8/22.
//

#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

void framebufferSizeCallback(GLFWwindow* pWindow, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *pWindow) {
    if (glfwGetKey(pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, true);
    }
}

int main() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW3" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* pWindow = glfwCreateWindow(640, 480, "LearnOpenGL", nullptr, nullptr);
    if (!pWindow) {
        std::cout << "Failed to create GLFWwindow" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(pWindow, framebufferSizeCallback);

    glfwMakeContextCurrent(pWindow);

    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        glfwTerminate();
        return -1;
    }
    std::cout << "Loaded OpenGL Version: " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;

    while (!glfwWindowShouldClose(pWindow)) {
        processInput(pWindow);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // 设置清空背景色
        glClear(GL_COLOR_BUFFER_BIT); // 使用当前颜色清空颜色缓冲区

        glfwSwapBuffers(pWindow);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include "mge_window.hpp"

// std
#include <stdexcept>
namespace mge
{
    MgeWindow::MgeWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name}
    {
        initWindow();
    }
    MgeWindow::~MgeWindow()
    {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void MgeWindow::initWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    }

void MgeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface){
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface");
    }
}


void MgeWindow::framebufferResizeCallback(GLFWwindow *window, int width, int height) {
    auto mgeWindow = reinterpret_cast<MgeWindow *>(glfwGetWindowUserPointer(window));
    mgeWindow->framebufferResized = true;
    mgeWindow->width = width;
    mgeWindow->height = height;
}
} // namespace mge

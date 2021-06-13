#include "first_app.hpp"

namespace m_lve
{
    void FirstApp::run()
    {
        while (!lveWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
}
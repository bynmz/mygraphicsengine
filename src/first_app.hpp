#pragma once

#include "mge_window.hpp"
#include "mge_game_object.hpp"
#include "mge_device.hpp"
#include "mge_renderer.hpp"

// std
#include <memory>
#include <vector>

namespace mge
{
    class FirstApp
    {
    private:
        void loadGameObjects(); 

        MgeWindow mgeWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        MgeDevice mgeDevice{mgeWindow};
        MgeRenderer mgeRenderer{mgeWindow, mgeDevice};
        
        std::vector<MgeGameObject> gameObjects;

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp &) = delete;
        FirstApp &operator=(const FirstApp &) = delete;

        void run();
    };

} // namespace mge

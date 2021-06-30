#pragma once

#include "lve_camera.hpp"
#include "lve_pipeline.hpp"
#include "lve_game_object.hpp"
#include "lve_device.hpp"

// std
#include <memory>
#include <vector>

namespace m_lve
{
    class SimpleRenderSystem
    {
    private:
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);

        LveDevice& lveDevice;
        
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;

    public:

        SimpleRenderSystem(LveDevice &device, VkRenderPass renderPass);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem &) = delete;
        SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

        void renderGameObjects(
            VkCommandBuffer commandBuffer, 
            std::vector<LveGameObject> &gameObjects,
            const LveCamera &camera);

    };

} // namespace m_lve

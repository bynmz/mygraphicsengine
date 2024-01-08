#pragma once

#include "mge_camera.hpp"
#include "mge_pipeline.hpp"
#include "mge_game_object.hpp"
#include "mge_device.hpp"

// std
#include <memory>
#include <vector>

namespace mge
{
    class SimpleRenderSystem
    {
    private:
        void createPipelineLayout();
        void createPipeline(VkRenderPass renderPass);

        MgeDevice& mgeDevice;
        
        std::unique_ptr<MgePipeline> mgePipeline;
        VkPipelineLayout pipelineLayout;

    public:

        SimpleRenderSystem(MgeDevice &device, VkRenderPass renderPass);
        ~SimpleRenderSystem();

        SimpleRenderSystem(const SimpleRenderSystem &) = delete;
        SimpleRenderSystem &operator=(const SimpleRenderSystem &) = delete;

        void renderGameObjects(
            VkCommandBuffer commandBuffer, 
            std::vector<MgeGameObject> &gameObjects,
            const MgeCamera &camera);

    };

} // namespace mge

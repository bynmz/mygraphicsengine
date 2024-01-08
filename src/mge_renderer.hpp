#pragma once

#include "mge_window.hpp"
#include "mge_device.hpp"
#include "mge_swap_chain.hpp"

// std
#include <cassert>
#include <memory>
#include <vector>

namespace mge
{
    class MgeRenderer
    {
    private:
        void createCommandBuffers();
        void freeCommandBuffers();
        void recreateSwapChain();

        MgeWindow &mgeWindow;
        MgeDevice &mgeDevice;
        std::unique_ptr<MgeSwapChain> mgeSwapChain;
        std::vector<VkCommandBuffer> commandBuffers;

        uint32_t currentImageIndex;
        int currentFrameIndex;
        bool isFrameStarted;

    public:

        MgeRenderer(MgeWindow &window, MgeDevice &device);
        ~MgeRenderer();

        MgeRenderer(const MgeRenderer &) = delete;
        MgeRenderer &operator=(const MgeRenderer &) = delete;

        VkRenderPass getSwapChainRenderPass() const { return mgeSwapChain->getRenderPass(); }
        float getAspectRatio() const { return mgeSwapChain->extentAspectRatio(); }
        bool isFrameInProgress() const { return isFrameStarted; }

        VkCommandBuffer getCurrentCommandBuffer() const { 
            assert(isFrameStarted && "Cannot get command buffer when frame not in progress");
            return commandBuffers[currentFrameIndex]; 
        }

        int getFrameIndex() const {
            assert(isFrameStarted && "Cannot get frame index when frame not in progress");
            return currentFrameIndex;
        }

        VkCommandBuffer beginFrame();
        void endFrame();
        void beginSwapChainRenderPass(VkCommandBuffer commandBuffer);
        void endSwapChainRenderPass(VkCommandBuffer commandBuffer);
    };

} // namespace mge

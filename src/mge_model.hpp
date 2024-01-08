#pragma once 

#include "mge_device.hpp"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace mge {
    class MgeModel {
        public:
            struct Vertex
            {
                glm::vec3 position;
                glm::vec3 color;

                static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
                static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();
            };
            
            MgeModel(MgeDevice &device,const std::vector<Vertex> &vertices);
            ~MgeModel();

            MgeModel(const MgeModel &) = delete;
            MgeModel &operator=(const MgeModel &) = delete;

            void bind(VkCommandBuffer commandBuffer);
            void draw(VkCommandBuffer commandBuffer);

        private:
            void createVertexBuffers(const std::vector<Vertex> &vertices);

            MgeDevice &mgeDevice;
            VkBuffer vertexBuffer;
            VkDeviceMemory vertexBufferMemory;
            uint32_t vertexCount;
    };
}
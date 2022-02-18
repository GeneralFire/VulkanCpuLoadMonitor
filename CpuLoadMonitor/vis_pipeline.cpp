#include "vis_pipeline.hpp"

namespace leVis
{
	VisPipeline::VisPipeline(VisDevice& device,
		const std::string& vertFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& pipelineConfgInfo) : visDevice(device)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath, pipelineConfgInfo);
	}

	std::vector<char> VisPipeline::readFile(const std::string& filePath)
	{
		std::ifstream file( filePath, std::ios::ate | std::ios::binary );

		if (!file.is_open())
		{
			throw_e_runtime_error("file open error");
		}

		size_t fileSize = static_cast<size_t>(file.tellg());

		std::vector<char> buffer(fileSize);
		
		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}

	void VisPipeline::createGraphicsPipeline(
		const std::string& vertFilePath, 
		const std::string& fragFilePath,
		const PipelineConfigInfo& pipelineConfgInfo)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

	}

	void VisPipeline::createShaderModule(
		const std::vector<char>& code, 
		VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(
			visDevice.device(),
			&createInfo,
			nullptr,
			shaderModule) != VK_SUCCESS)
		{
			throw_e_runtime_error("");
		}
	}

	PipelineConfigInfo VisPipeline::defaultPipelineConfigInfo(
		uint32_t width, 
		uint32_t height
	)
	{
		PipelineConfigInfo configInfo{};

		return configInfo;
	}

	VisPipeline::~VisPipeline() {
		vkDestroyShaderModule(visDevice.device(), fragShaderModule, nullptr);
		vkDestroyShaderModule(visDevice.device(), vertShaderModule, nullptr);
		vkDestroyPipeline(visDevice.device(), graphicsPipeline, nullptr);
	}
}
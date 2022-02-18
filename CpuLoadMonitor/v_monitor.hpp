#pragma once

#include "v_window.hpp"
#include "v_device.hpp"
#include "vis_pipeline.hpp"
namespace leVis
{

	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		VisWindow visWindow{ WIDTH, HEIGHT, "Window!"};
		VisDevice visDevice{ visWindow };
		VisPipeline visPipeline{
			visDevice,
			FRAG_SHADER_PATH,
			VERT_SHADER_PATH,
			VisPipeline::defaultPipelineConfigInfo(
				WIDTH,
				HEIGHT)
		};
		
	};
}
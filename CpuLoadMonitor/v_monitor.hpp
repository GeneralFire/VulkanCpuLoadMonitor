#pragma once

#include "v_window.hpp"

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
	};
}
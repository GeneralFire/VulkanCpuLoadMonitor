#include "v_monitor.hpp"

namespace leVis
{
	void FirstApp::run()
	{
		while (!visWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}
}
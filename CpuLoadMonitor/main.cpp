#define GLFW_INCLUDE_VULKAN


#include "v_monitor.hpp"

#include <iostream>
#include <stdexcept>
#include  "GLFW/glfw3.h"

int main() {
	leVis::FirstApp app{};
	try
	{
		app.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	// leVis::FirstApp app2 = app;
	//leVis::VisWindow a = leVis::VisWindow(3, 4, "ss");

	//leVis::VisWindow ab = leVis::VisWindow(3, 4, "2ss");

	//a = ab;

	printf("!!!!!!!");
	return EXIT_SUCCESS;
}
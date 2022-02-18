#include "v_window.hpp"


namespace leVis
{
	VisWindow::VisWindow(int w, int h, std::string windowName) : width(w), height(h), windowName(windowName) 
	{
		initWindow();
	};

	VisWindow::~VisWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VisWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);


		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

		assert(window);
	}

	

}
#pragma once

#include "globals.h"

#include <GLFW/glfw3.h>
#include <string>
#include <assert.h>

namespace leVis 
{
	class VisWindow
	{

	public:
		VisWindow(int w, int h, std::string windowName);
		~VisWindow();

		VisWindow(const VisWindow&) = delete;
		VisWindow &operator=(const VisWindow&) = delete;

		bool shouldClose();

	private:
		void initWindow();
		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;

	};
}
#pragma once

#include "globals.h"


#include <GLFW/glfw3.h>
#include <string>
#include <assert.h>

namespace leVis 
{
	class VisWindow {
	public:
		VisWindow(int w, int h, std::string name);
		~VisWindow();

		VisWindow(const VisWindow&) = delete;
		VisWindow& operator=(const VisWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width), static_cast<uint32_t>(height) }; }
		bool wasWindowResized() { return framebufferResized; }
		void resetWindowResizedFlag() { framebufferResized = false; }
		GLFWwindow* getGLFWwindow() const { return window; }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

	private:
		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		void initWindow();

		int width;
		int height;
		bool framebufferResized = false;

		std::string windowName;
		GLFWwindow* window;
	};
}
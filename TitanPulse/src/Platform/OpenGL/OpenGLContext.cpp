#include <tppch.h>
#include "OpenGLContext.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

TitanPulse::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	TP_CORE_ASSERT(windowHandle, "Window handle is null!");
}

void TitanPulse::OpenGLContext::Init()
{
	TP_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	TP_CORE_ASSERT(status, "Failed to initialize GLAD!");

	TP_CORE_INFO("OpenGL Info:");
	TP_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
	TP_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
	TP_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
}

void TitanPulse::OpenGLContext::SwapBuffers()
{
	TP_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
	glfwSwapBuffers(m_WindowHandle);
}

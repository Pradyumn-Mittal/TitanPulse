#pragma once

#include "TitanPulse/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace TitanPulse {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}
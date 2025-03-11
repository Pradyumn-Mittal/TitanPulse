#include "tppch.h"
#include "Application.h"

#include "TitanPulse/Events/ApplicationEvent.h"
#include "TitanPulse/Log.h"

namespace TitanPulse
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}
#include "tppch.h"
#include "Application.h"

#include "TitanPulse/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TitanPulse
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		TP_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		// Initialize GLFW
		if (!glfwInit())
		{
			TP_CORE_ERROR("Failed to initialize GLFW!");
			return;
		}

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
		glfwTerminate();
	}

	void Application::PushLayer(Layer* layer)
	{
		TP_TRACE("Pushing layer: {0}", layer->GetName()); // Log layer push
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		TP_TRACE("Pushing overlay: {0}", layer->GetName()); // Log overlay push
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		TP_TRACE("Event dispatched: {0}", e.GetName()); // Log the event dispatch

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled())
			{
				TP_TRACE("Event handled by layer: {0}", (*it)->GetName()); // Log the layer handling the event
				break;
			}
		}
	}

	void Application::Run()
	{

		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}

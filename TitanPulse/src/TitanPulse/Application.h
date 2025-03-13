#pragma once

#include "Core.h"

#include "Window.h"
#include "TitanPulse/LayerStack.h"
#include "TitanPulse/Events/Events.h"
#include "TitanPulse/Events/ApplicationEvent.h"


namespace TitanPulse
{
	class TITAN_PULSE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


#pragma once

#include "Core.h"

#include "Window.h"
#include "TitanPulse/LayerStack.h"
#include "TitanPulse/Events/Events.h"
#include "TitanPulse/Events/ApplicationEvent.h"

#include "TitanPulse/ImGui/ImGuiLayer.h"
#include "TitanPulse/Renderer/Shader.h"

#include "TitanPulse/Renderer/Buffer.h"

namespace TitanPulse
{
	class  Application
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
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


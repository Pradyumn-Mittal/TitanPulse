#include <TitanPulse.h>

#include "imgui/imgui.h"

class ExampleLayer : public TitanPulse::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
		if (TitanPulse::Input::IsKeyPressed(TP_KEY_TAB))
			TP_TRACE("Tab key is pressed");
    }

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello world!");
		ImGui::End();
	}

    void OnEvent(TitanPulse::Event& event) override
    {
		if (event.GetEventType() == TitanPulse::EventType::KeyPressed)
		{
			TitanPulse::KeyPressedEvent& e = (TitanPulse::KeyPressedEvent&)event;
			TP_TRACE("Key pressed: {0} ({1})", e.GetKeyCode(), (char)e.GetKeyCode());
		}
    }
};

class Sandbox : public TitanPulse::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox() {
    }
};

TitanPulse::Application* TitanPulse::CreateApplication() {
    return new Sandbox();
}

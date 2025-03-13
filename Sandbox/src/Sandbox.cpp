#include <TitanPulse.h>

class ExampleLayer : public TitanPulse::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        TP_INFO("ExampleLayer::Update");
    }

    void OnEvent(TitanPulse::Event& event) override
    {
        TP_TRACE("{0}", event.ToString());
    }
};

class Sandbox : public TitanPulse::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
        PushLayer(new TitanPulse::ImGuiLayer());
    }
    ~Sandbox() {
    }
};

TitanPulse::Application* TitanPulse::CreateApplication() {
    return new Sandbox();
}

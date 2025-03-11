#include <TitanPulse.h>

class Sandbox : public TitanPulse::Application {
public:
	Sandbox() {
	}
	~Sandbox() {
	}
};

TitanPulse::Application* TitanPulse::CreateApplication() {
	return new Sandbox();
}
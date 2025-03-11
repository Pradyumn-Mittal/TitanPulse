#pragma once

#ifdef TP_PLATFORM_WINDOWS

extern TitanPulse::Application* TitanPulse::CreateApplication();

int main(int argc, char** argv) {

	auto app = TitanPulse::CreateApplication();
	app->Run();
	delete app;
}
#endif // TP_PLATFORM_WINDOWS

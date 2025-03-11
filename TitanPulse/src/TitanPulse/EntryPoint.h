#pragma once

#ifdef TP_PLATFORM_WINDOWS

extern TitanPulse::Application* TitanPulse::CreateApplication();

int main(int argc, char** argv) {

	TitanPulse::Log::Init();
	TP_CORE_WARN("Initialized Log!");
	int a = 5;
	TP_INFO("Hello! Var={0}", a);


	auto app = TitanPulse::CreateApplication();
	app->Run();
	delete app;
}
#endif // TP_PLATFORM_WINDOWS

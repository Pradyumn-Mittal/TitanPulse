#pragma once

#include "Core.h"

namespace TitanPulse
{
	class TITAN_PULSE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


#pragma once 

#include "TitanPulse/Layer.h"
#include "TitanPulse/Events/KeyEvent.h"
#include "TitanPulse/Events/ApplicationEvent.h"
#include <TitanPulse/Events/MouseEvent.h>

namespace TitanPulse
{
	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_time = 0.0f;
	};
}
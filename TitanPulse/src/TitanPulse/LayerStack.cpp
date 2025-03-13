#include "tppch.h"
#include "LayerStack.h"

namespace TitanPulse
{
	LayerStack::LayerStack()
	{
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			TP_TRACE("Deleting layer: {0}", layer->GetName()); // Log layer deletion
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		TP_TRACE("Pushing layer: {0}", layer->GetName()); // Log layer push
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
		m_LayerInsert++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		TP_TRACE("Pushing overlay: {0}", overlay->GetName()); // Log overlay push
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			TP_TRACE("Popping layer: {0}", layer->GetName()); // Log layer pop
			m_Layers.erase(it);
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			TP_TRACE("Popping overlay: {0}", overlay->GetName()); // Log overlay pop
			m_Layers.erase(it);
		}
	}
}

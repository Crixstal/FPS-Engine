#include "component.hpp"

#include <algorithm>
#include <imgui.h>

#include "graph.hpp"

#include "transform.hpp"
#include "collider.hpp"

namespace Engine
{
	Component::Component(GameObject& gameObject, const std::shared_ptr<Component>& childPtr)
		: m_gameObject(gameObject)
	{
		m_gameObject.m_components.push_back(childPtr);
	}

	Component::~Component()
	{
	}

	void Component::setActive(bool value)
	{
		// Call the correct function when state changed
		if (isActive() != value)
			value ? onEnable() : onDisable();

		// Activate or deactivate the component
		Object::setActive(value);
	}

	void Component::drawImGui()
	{
		if (ImGui::Button("Destroy"))
			destroy();
	}

	void Component::onDestroy()
	{
		std::vector<std::shared_ptr<Component>>::iterator it;

		for (it = m_gameObject.m_components.begin(); it != m_gameObject.m_components.end(); it++)
		{
			if (it->get() == this)
				break;
		}

		m_gameObject.m_components.erase(it);
	}

	void Component::destroy()
	{
		Core::Engine::Graph::addToDestroyQueue(this);
	}

	GameObject& Component::getHost()
	{
		return m_gameObject;
	}
}
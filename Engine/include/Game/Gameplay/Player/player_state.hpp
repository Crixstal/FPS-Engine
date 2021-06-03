#pragma once

#include <memory>

#include "entity_state.hpp"

namespace Gameplay
{
	class PlayerState : public EntityState
	{
	public:
		PlayerState(Engine::GameObject& gameObject);

		void update() override;
		void drawImGui() override;

		std::string toString() const override;

		static void parseComponent(Engine::GameObject& gameObject, std::istringstream& iss);

		void onCollisionEnter(const Physics::Collision& collision) override;
		void onCollisionExit(const Physics::Collision& collision) override;
	};
}
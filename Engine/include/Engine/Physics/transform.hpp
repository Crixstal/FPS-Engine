<<<<<<< HEAD
#pragma once

#include "maths.hpp"

#include "component.hpp"

#include "game_object.hpp"

#include "model.hpp"

namespace Physics
{
	class Transform : public Engine::Component
	{
	private:
		std::shared_ptr<Transform> parent = nullptr;
		std::vector<Transform*> children;

	public:
		Transform(Engine::GameObject& gameObject);

		Core::Maths::vec3 m_position = Core::Maths::vec3(0.f, 0.f, 0.f);
		Core::Maths::vec3 m_rotation = Core::Maths::vec3(0.f, 0.f, 0.f);
		Core::Maths::vec3 m_scale = Core::Maths::vec3(1.f, 1.f, 1.f);

		Engine::GameObject& getGOParent();
		Engine::GameObject& getGOChild(int childIndex);
		int getChildrenCount();
		Core::Maths::mat4 getModel() const;
		Core::Maths::mat4 getGlobalModel() const;
		Core::Maths::mat4 getParentModel() const;

<<<<<<< HEAD
=======
		Core::Maths::vec3 getGlobalRotation() const;
		Core::Maths::vec3 getGlobalPosition() const;
		Core::Maths::vec3 getParentRotation() const;
		Core::Maths::vec3 getParentPosition() const;

>>>>>>> 2353d594957db045cb61eb4f8ce63cfcdeca7a02
		Core::Maths::vec3 getForward() const;

		bool hasParent();
		bool hasChild();
		void setParent(std::shared_ptr<Physics::Transform> _parent);
		void setParent(Engine::GameObject& gameObject);
		void setChild(Physics::Transform* child);
		void setChild(Engine::GameObject& gameObject);
		void drawImGui() override;

		std::string toString() const override;

		static void parseComponent(Engine::GameObject& gameObject, std::istringstream& iss, std::string& parentName);
	};
=======
#pragma once

#include "maths.hpp"

#include "component.hpp"

#include "game_object.hpp"

#include "model.hpp"

namespace Physics
{
	class Transform : public Engine::Component
	{
	private:
		std::shared_ptr<Transform> parent = nullptr;
		std::vector<Transform*> children;

	public:
		Transform(Engine::GameObject& gameObject);

		Core::Maths::vec3 m_position	= Core::Maths::vec3(0.f, 0.f, 0.f);
		Core::Maths::vec3 m_rotation	= Core::Maths::vec3(0.f, 0.f, 0.f);
		Core::Maths::vec3 m_scale		= Core::Maths::vec3(1.f, 1.f, 1.f);

		Engine::GameObject& getGOParent();
		Engine::GameObject& getGOChild(int childIndex);
		int getChildrenCount();
		Core::Maths::mat4 getModel() const;
		Core::Maths::mat4 getGlobalModel() const;
		Core::Maths::mat4 getParentModel() const;

		Core::Maths::vec3 getGlobalRotation() const;
		Core::Maths::vec3 getGlobalPosition() const;
		Core::Maths::vec3 getParentRotation() const;
		Core::Maths::vec3 getParentPosition() const;

		Core::Maths::vec3 getForward() const;

		bool hasParent();
		bool hasChild();
		void setParent(std::shared_ptr<Physics::Transform> _parent);
		void setParent(Engine::GameObject& gameObject);
		void setChild(Physics::Transform* child);
		void setChild(Engine::GameObject& gameObject);
		void drawImGui() override;

		std::string toString() const override;

		static void parseComponent(Engine::GameObject& gameObject, std::istringstream& iss, std::string& parentName);
	};
>>>>>>> bbba777bb2ca201e3c4091a981e8afc17bdd1d84
}
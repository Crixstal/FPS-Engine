#include "collider.hpp"

#include "imGui.h"

#include <algorithm>

#include "debug.hpp"

#include "utils.hpp"

namespace Physics
{
	Collider::Collider(Engine::GameObject& gameObject, std::shared_ptr<Collider> ptr)
		: Component(gameObject, ptr)
	{
		m_transform = requireComponent<Transform>();
		m_rigidbody = gameObject.getComponent<Rigidbody>();
	}

	bool Collider::hasRigidbody()
	{
		return m_rigidbody != nullptr;
	}

	bool Collider::isRigidbodyAwake()
	{
		return hasRigidbody() && m_rigidbody->isAwake;
	}

	void Collider::computeCallback(bool hasHit, const Collision& collision)
	{
		auto colliderIt = std::find(m_colliders.begin(), m_colliders.end(), collision.collider);

		bool isInVector = colliderIt != m_colliders.end();


		if (isInVector)
		{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2353d594957db045cb61eb4f8ce63cfcdeca7a02
			//Core::Debug::Log::info("Normal : " + Utils::vecToStringDebug(collision.normal));

=======
>>>>>>> 24cb1c6cc42722d81bb6765deca04f36800e32c9
			if (!hasHit)
			{
				m_colliders.erase(colliderIt);
				getHost().callCollisionExit(collision);
				return;
			}

			getHost().callCollisionStay(collision);
			return;
		}

		if (hasHit)
		{
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2353d594957db045cb61eb4f8ce63cfcdeca7a02
			//Core::Debug::Log::info("Normal : " + Utils::vecToStringDebug(collision.normal));

=======
>>>>>>> 24cb1c6cc42722d81bb6765deca04f36800e32c9
			m_colliders.push_back(collision.collider);
			getHost().callCollisionEnter(collision);
			return;
		}
	}

	void Collider::drawImGui()
	{
	}
}
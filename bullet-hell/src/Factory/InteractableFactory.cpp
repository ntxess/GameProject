#include "InteractableFactory.hpp"

std::unique_ptr<Entity> InteractableFactory::CreateEntity(TYPE type, sf::Texture& texture) const
{
	entt::entity handle = m_currentScene->GetRegistry().create();
	std::unique_ptr<Entity> entity = std::make_unique<Entity>(handle, m_currentScene);

	switch (type)
	{
	case TYPE::PLAYER:
		entity->AddComponent<AnimatedSprite>(texture);
		entity->AddComponent<PlayerInput>();
		entity->AddComponent<Health>(100.f);
		entity->AddComponent<Speed>(500.f);
		entity->AddComponent<Attack>(10.f);
		entity->GetComponent<AnimatedSprite>().AddAnimator(m_data->spriteManager.GetAnimator("SP_Player"));
		break;
	case TYPE::ENEMY:
		entity->AddComponent<AnimatedSprite>(texture);
		entity->AddComponent<Health>(200.f);
		entity->AddComponent<Speed>(10.f);
		entity->AddComponent<Attack>(5.f);
		entity->AddComponent<MovementPattern>(
			m_data->waypointManager.GetWaypoint("straight-down"));
		break;
	case TYPE::FRIENDLY:
		entity->AddComponent<AnimatedSprite>(texture);
		entity->AddComponent<Health>(100.f);
		entity->AddComponent<Speed>(20.f);
		entity->AddComponent<Attack>(10.f);
		break;
	case TYPE::OBJECT:
		entity->AddComponent<Sprite>(texture);
		entity->AddComponent<Health>(100.f);
		break;
	default:
		// TODO:
		break;
	}
	return std::move(entity);
}

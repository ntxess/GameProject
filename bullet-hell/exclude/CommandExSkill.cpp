#include "CommandExSkill.hpp"

CommandExSkill::CommandExSkill()
	: _cooldownTime(sf::seconds(5.f).asSeconds())
{}

CommandExSkill::~CommandExSkill()
{}

float CommandExSkill::GetTime() const
{
	return _timer.getElapsedTime().asSeconds();
}

float CommandExSkill::GetMaxTime() const
{
	return _cooldownTime;
}

void CommandExSkill::Execute(entt::registry& registry, entt::entity entity, std::shared_ptr<GameData>& data)
{
	float currentTime = _timer.getElapsedTime().asSeconds();

	if (currentTime > _cooldownTime)
	{
		std::cout << "Using EX Skill\n";
		auto view = registry.view<EnemyTagComponent>();
		for (auto enemy : view)
		{
			registry.destroy(enemy);
		}
		_timer.restart();
	}
}
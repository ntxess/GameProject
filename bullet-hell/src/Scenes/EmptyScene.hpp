#pragma once
#include "../GameData.hpp"
#include "../Component.hpp"
#include "../Entity.hpp"
#include "../AbstractFactory.hpp"
#include "../Factory/InteractableFactory.hpp"
#include "../Factory/NonInteractableFactory.hpp"
#include "../Managers/SystemManager.hpp"
#include "../Systems/WaypointSystem.hpp"
#include "../Systems/InputSystem.hpp"
#include "../Systems/AnimationSystem.hpp"
#include "../Systems/RenderSystem.hpp"
#include "../Systems/DebugSystem.hpp"


class EmptyScene : public Scene
{
private:
	std::shared_ptr<GameData> m_data;
	std::unordered_map<std::string, std::unique_ptr<Entity>> m_entity;
	entt::registry m_reg;
	SystemManager m_system;

public:
	EmptyScene(std::shared_ptr<GameData>& data);
	~EmptyScene();

	void Init();
	void ProcessEvent(const sf::Event& event);
	void ProcessInput();
	void Update(const float& deltaTime);
	void Render(sf::RenderWindow& rw, const float& deltaTime, const float& interpolation);
	void Pause();
	void Resume();
	entt::registry& GetRegistry();

	void BuildEntities();
	void SetupScene();
	void SetupSystems();
};

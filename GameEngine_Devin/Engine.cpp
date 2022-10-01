#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	while (window->isOpen() == true)
	{
		this->Update();
	}
}

Engine::Engine() = default;


Engine::~Engine()
{
}

void Engine::Update()
{
	sf::Event event;
	while (window->pollEvent(event) == true)
	{
		//Close requested event.
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	world->tick(10.0f);
}

Engine& Engine::GetInstance()
{
	static Engine instance;
	return instance;
}

void Engine::AddSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}

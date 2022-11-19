#include "Engine.h"



void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;

	mainCamera = new MainCamera(sf::Vector2f(
		win->getSize().x / 2,
		win->getSize().y / 2));

	pauseMenu = new PauseMenu(win);

	while (win->isOpen() == true)
	{
		this->Update();
	}
}

Engine::Engine()
{
	bQuit = false;
}


Engine::~Engine() = default;

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

		this->pauseMenu->Update(event, 10.0f, this->window);
	}

	world->tick(10.0f);

	mainCamera->Update(world, 10.0f, window);

	if (States::GetPausedState() == true) {
		this->onGameInactiveState();
	}
}

void Engine::onGameInactiveState()
{
	pauseMenu->Render(this->window, 10.0f, this->mainCamera->cameraView.getCenter());
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

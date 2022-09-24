#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	while (window->isOpen() == true)
	{
		this->Update();
	}
}

Engine::Engine()
{
	bQuit = false;
}

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
}

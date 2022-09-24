#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"

class Engine
{
public: 
	sf::RenderWindow* window;

private:
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);

private:
	Engine();
	~Engine();
	void Update();

};


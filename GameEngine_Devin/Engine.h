#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"
#include "ECS.h"
#include "Component.h"
#include "Systems/RenderingSystem.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Interface/MainCamera.h"

class Engine
{
public: 
	sf::RenderWindow* window = nullptr;
	ECS::World* world = nullptr;
	class MainCamera mainCamera;

private:
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();
	void AddSystem(ECS::EntitySystem* newSys);

private:
	Engine();
	// Required to prevent the reference from being copied, moved, or assigned
	Engine(Engine& copy); // Hide copy constructor
	Engine(Engine&& other); // Hide move constructor
	Engine& operator=(Engine& copy); // Hide assignment operator

	~Engine();
	void Update();

};


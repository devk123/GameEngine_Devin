#include "../GameEngine_Devin/Engine.h"


int main(int argc, char* args[]) {
	// Declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");


	// Create the world and attach entities and systems to
	gameEngine.world = ECS::World::createWorld();

	ECS::Entity* background = nullptr;
	ECS::Entity* stickFigure = nullptr;
	ECS::Entity* tux = nullptr;

	// Add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());
	gameEngine.AddSystem(new AnimationSystem());
	gameEngine.AddSystem(new InputSystem(&window));
	gameEngine.AddSystem(new MovementSystem());
	gameEngine.AddSystem(new PhysicsSystem());

	background = gameEngine.world->create();
	stickFigure = gameEngine.world->create();
	tux = gameEngine.world->create();

	// Assign components to entities after creation
	background->assign<Transform>(0, 0);
	background->assign<Sprite2D>("../Debug/Pics/bg.jpg");
	background->assign<Tag>();
	background->get<Tag>()->addTag("Background");

	stickFigure->assign<Transform>(300, 300);
	stickFigure->assign<Sprite2D>("../Debug/Pics/herosheet.png");
	stickFigure->assign<Animator>(32, 32, 200.0f, 4, 1);
	stickFigure->assign<BoxCollider>();
	stickFigure->assign<Tag>();
	stickFigure->get<Tag>()->addTag("Object");

	tux->assign<Transform>(200, 200, 0.1f, 0.1f);
	tux->assign<Sprite2D>("../Debug/Pics/tux_from_linux.png");
	tux->assign<Animator>(56, 72, 2000.0f, 3, 9);
	tux->assign<InputController>();
	tux->assign<BoxCollider>();
	tux->assign<Tag>();
	tux->get<Animator>()->currentRow = 0;
	tux->get<Tag>()->addTag("Player");

	std::cout << background->getEntityId() << " is the entity id." << std::endl;
	std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
	std::cout << tux->getEntityId() << " is the entity id." << std::endl;

	std::cout << tux->get<Transform>()->xPos << std::endl;
	std::cout << tux->get<Transform>()->yPos << std::endl;


	// Pass window reference to the engine and start
	gameEngine.Start(&window);


	return 0;
}
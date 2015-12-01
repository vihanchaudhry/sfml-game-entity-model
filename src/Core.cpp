#include "Core.h"

Core::Core()
{
	load();
}

void Core::gameLoop()
{
	while (window.isOpen())
	{
		deltaTime = deltaClock.restart().asSeconds();
		handleEvent();
		update();
		draw();
	}
}

void Core::load()
{
	window.create(sf::VideoMode(1280, 720), "Stuff", sf::Style::Default);
	window.setVerticalSyncEnabled(true);
	player.setTexture("char.png");
	player.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

	// BG
	bgTexture.loadFromFile(resourcePath() + "assets/textures/grass_template.jpg");
	bgSprite.setTexture(bgTexture);

	// Create walls
	wall.setTexture("wall.png");
	for (int i = 0; i < 12; i++) // 12 vertical walls along the left side
 	{
		wallRegistry.push_back(wall);
		wallRegistry[i].setPosition(0.f, i * 60.f);
	}
	for (int i = 0; i < 12; i++) // 12 vertical walls along the right side
	{
		wallRegistry.push_back(wall);
		wallRegistry[i + 12].setPosition(1220.f, i * 60.f);
	}
	for (int i = 0; i < 19; i++) // 12 vertical walls along the left side
	{
		wallRegistry.push_back(wall);
		wallRegistry[i + 24].setPosition((i + 1) * 60.f + (1.f * (i + 1)), 0.f);
	}
	for (int i = 0; i < 19; i++) // 12 vertical walls along the left side
	{
		wallRegistry.push_back(wall);
		wallRegistry[i + 43].setPosition((i + 1) * 60.f + (1.f * (i + 1)), 660.f);
	}
}

void Core::handleEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
			if (event.key.code == sf::Keyboard::E)
				player.dropBomb();
		}

	}
}

void Core::update()
{
	// Get player position for collision handling
	sf::Vector2f currPos = player.getPosition();
	
	// Update things
	player.update(deltaTime);
	
	// Wall collision detection and handling
	for (std::vector<Entity>::iterator it = wallRegistry.begin(); it != wallRegistry.end(); ++it)
	{
		if (overlap(player.getSprite(), it->getSprite()))
		{
			player.setPosition(currPos.x, currPos.y);
		}
	}
}

void Core::draw()
{
	window.clear();
	window.draw(bgSprite);
	for (std::vector<Entity>::iterator it = wallRegistry.begin(); it != wallRegistry.end(); ++it)
	{
		window.draw(it->getSprite());
	}
	for (std::vector<Bomb>::iterator it = player.getBombs().begin(); it != player.getBombs().end(); ++it)
	{
		window.draw(it->getSprite());
	}
	window.draw(player.getSprite());
	window.display();
}

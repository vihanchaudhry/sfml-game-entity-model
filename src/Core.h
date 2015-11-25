#pragma once

#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Overlap.h"
#include "Player.h"

class Core
{
private:
	sf::RenderWindow window;
	sf::Clock deltaClock;
	float deltaTime;
	Player player;
	std::vector<Entity> wallRegistry;
	Entity wall;
	sf::Texture bgTexture;
	sf::Sprite bgSprite;
public:
	Core();
	
	// Runs the game
	void gameLoop();

	// Modularization of game loop
	void load();
	void handleEvent();
	void update();
	void draw();
};

#endif
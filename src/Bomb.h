#pragma once

#ifndef BOMB_H
#define BOMB_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "ResourcePath.h"
#include "Entity.h"

class Bomb : public Entity
{
private:
	std::vector<sf::IntRect> spriteRects; // 12 sprites (indices 0 to 11) going right, 
										  // then down [0-2: down, 3-5: right, 6-8: up, 9-11: left]
										  // last one is empty
	sf::Clock animClock;
public:
	// Constructors
	Bomb();
	Bomb(std::string);

	// Accessors
	sf::Clock &getAnimClock() { return animClock; }

	// Mutators
	void setTexture(std::string);

	void update();

	// Animation
	void animate();
};

#endif
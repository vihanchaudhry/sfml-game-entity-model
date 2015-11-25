#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "ResourcePath.h"
#include "Entity.h"

class Player : public Entity
{
private:
	std::vector<sf::IntRect> spriteRects; // 12 sprites (indices 0 to 11) going right, 
										  // then down [0-2: down, 3-5: right, 6-8: up, 9-11: left]
	int prevDirection; // 0: nothing, 1: up, 2: down, 3: left, 4: right
	int currDirection; // 0: nothing, 1: up, 2: down, 3: left, 4: right
	bool isLeftStep;
	sf::Clock animClock;
public:
	// Constructors
	Player();
	Player(std::string);

	// Mutators
	void setTexture(std::string);

	// Movement
	void up(float);
	void down(float);
	void left(float);
	void right(float);
	
	void update(float);

	// Animation
	void animate();
};

#endif
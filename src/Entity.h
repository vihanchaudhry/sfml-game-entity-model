#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "ResourcePath.h"

class Entity
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
public:
	// Constructors
	Entity();
	Entity(std::string);

	// Accessors
	const sf::Vector2f &getPosition() { return sprite.getPosition(); }
	sf::Sprite &getSprite() { return sprite; }
	float getSpeed() { return speed; }

	// Mutators
	void setPosition(float x, float y) { sprite.setPosition(x, y); }
	void setPosition(sf::Vector2f v) { sprite.setPosition(v); }
	void setSpeed(float arg) { speed = arg; }
	void setTexture(std::string);

	// Destructors
};

#endif
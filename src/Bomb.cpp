#include "Bomb.h"

Bomb::Bomb()
{
	// Initialize members
}

Bomb::Bomb(std::string textureFile) : Entity(textureFile)
{
	// Initialize members

	// Populate spritesheet rects vector
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			spriteRects.push_back(sf::IntRect(60 * r, 60 * c, 60, 60));
		}
	}
	sprite.setTextureRect(spriteRects[0]); // first frame
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Bomb::setTexture(std::string textureFile)
{
	// Initialize members

	// Load and set textures
	texture.loadFromFile(resourcePath() + "assets/textures/" + textureFile);
	sprite.setTexture(texture);

	// Populate spritesheet rects vector
	for (int c = 0; c < 3; c++)
	{
		for (int r = 0; r < 4; r++)
		{
			spriteRects.push_back(sf::IntRect(60 * r, 60 * c, 60, 60));
		}
	}
	sprite.setTextureRect(spriteRects[0]); // first frame
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Bomb::animate()
{
	
}

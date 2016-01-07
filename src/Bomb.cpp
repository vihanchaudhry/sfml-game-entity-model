#include "Bomb.h"

Bomb::Bomb()
{
	// Initialize members
	animClock.restart().asSeconds();
}

Bomb::Bomb(std::string textureFile) : Entity(textureFile)
{
	// Initialize members
	animClock.restart().asSeconds();

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

void Bomb::update()
{
	if (animClock.getElapsedTime().asSeconds() >= 1.f && sprite.getTextureRect().left < spriteRects[3].left)
	{
		animate();
		animClock.restart().asSeconds();
	}
	else if (animClock.getElapsedTime().asSeconds() >= 0.03f &&
			(sprite.getTextureRect().top > spriteRects[0].top || sprite.getTextureRect().left >= spriteRects[3].left))
	{
		animate();
		animClock.restart().asSeconds();
	}

	// Explosion
	if (sprite.getTextureRect() == spriteRects[4])
	{
		//explode();
	}
}

void Bomb::explode(Entity bomber)
{
	
}

void Bomb::animate()
{
	for (int i = 0; i < 11; i++)
	{
		if (sprite.getTextureRect() == spriteRects[i])
		{
			sprite.setTextureRect(spriteRects[++i]);
		}
	}
}

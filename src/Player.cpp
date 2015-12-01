#include "Player.h"

Player::Player()
{
	// Initialize members
	isLeftStep = false;
	currDirection = 2;
	animClock.restart().asSeconds();
	numOfBombs = 3;

	// Initialize bomb object
	bomb.setTexture("bomb.png");
}

Player::Player(std::string textureFile) : Entity(textureFile)
{	
	// Initialize members
	isLeftStep = false;
	currDirection = 2;
	animClock.restart().asSeconds();
	numOfBombs = 3;

	// Initialize bomb object
	bomb.setTexture("bomb.png");

	// Populate spritesheet rects vector
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 3; r++)
		{
			spriteRects.push_back(sf::IntRect(44 * r, 36 * c, 36, 36));
		}
	}
	sprite.setTextureRect(spriteRects[1]); // top middle frame (12px b/w each horizontal frame)
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Player::setTexture(std::string textureFile)
{
	// Load and set textures
	texture.loadFromFile(resourcePath() + "assets/textures/" + textureFile);
	sprite.setTexture(texture);

	// Populate spritesheet rects vector
	for (int c = 0; c < 4; c++)
	{
		for (int r = 0; r < 3; r++)
		{
			spriteRects.push_back(sf::IntRect(44 * r, 36 * c, 36, 36));
		}
	}
	sprite.setTextureRect(spriteRects[1]); // top middle frame (12px b/w each horizontal frame)
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.f, sprite.getGlobalBounds().height / 2.f);
}

void Player::up(float deltaTime)
{
	sprite.move(0, -speed * deltaTime);
	currDirection = 1;
}

void Player::down(float deltaTime)
{
	sprite.move(0, speed * deltaTime);
	currDirection = 2;
}

void Player::left(float deltaTime)
{
	sprite.move(-speed * deltaTime, 0);
	currDirection = 3;
}

void Player::right(float deltaTime)
{
	sprite.move(speed * deltaTime, 0);
	currDirection = 4;
}

void Player::update(float deltaTime)
{
	prevDirection = currDirection;
	// Movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		up(deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		down(deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		left(deltaTime);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		right(deltaTime);
	}
	else
	{
		currDirection = 0;
	}
	
	// Change anim every 0.167 seconds
	if (prevDirection != currDirection ||
		prevDirection == currDirection && animClock.getElapsedTime().asSeconds() >= 0.2f)
	{
		animate();
		animClock.restart().asSeconds();
	}
}

void Player::dropBomb()
{
	if (bombs.size() < numOfBombs)
	{
		bombs.push_back(bomb);
		bombs.back().setPosition(sprite.getPosition());
	}
}

void Player::animate()
{
	switch (currDirection)
	{
	case 0:
		if (prevDirection == 1)
		{
			sprite.setTextureRect(spriteRects[7]);
		}
		else if (prevDirection == 2)
		{
			sprite.setTextureRect(spriteRects[1]);
		}
		else if (prevDirection == 3)
		{
			sprite.setTextureRect(spriteRects[10]);
		}
		else if (prevDirection == 4)
		{
			sprite.setTextureRect(spriteRects[4]);
		}
		break;
	case 1:
		if (sprite.getTextureRect() == spriteRects[7])
		{
			if (isLeftStep)
			{
				sprite.setTextureRect(spriteRects[8]);
				isLeftStep = false;
			}
			else
			{
				isLeftStep = true;
				sprite.setTextureRect(spriteRects[6]);
			}
		}	
		else
		{
			sprite.setTextureRect(spriteRects[7]);
		}
		break;
	case 2:
		if (sprite.getTextureRect() == spriteRects[1])
		{
			if (isLeftStep)
			{
				sprite.setTextureRect(spriteRects[2]);
				isLeftStep = false;
			}
			else
			{
				isLeftStep = true;
				sprite.setTextureRect(spriteRects[0]);
			}
		}
		else
		{
			sprite.setTextureRect(spriteRects[1]);
		}
		break;
	case 3:
		if (sprite.getTextureRect() == spriteRects[10])
		{
			if (isLeftStep)
			{
				sprite.setTextureRect(spriteRects[11]);
				isLeftStep = false;
			}
			else
			{
				isLeftStep = true;
				sprite.setTextureRect(spriteRects[9]);
			}
		}
		else
		{
			sprite.setTextureRect(spriteRects[10]);
		}
		break;
	case 4:
		if (sprite.getTextureRect() == spriteRects[4])
		{
			if (isLeftStep)
			{
				sprite.setTextureRect(spriteRects[5]);
				isLeftStep = false;
			}
			else
			{
				isLeftStep = true;
				sprite.setTextureRect(spriteRects[3]);
			}
		}
		else
		{
			sprite.setTextureRect(spriteRects[4]);
		}
		break;
	default:
		sprite.setTextureRect(spriteRects[7]);
		break;
	}
}

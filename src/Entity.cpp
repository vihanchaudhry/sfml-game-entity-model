#include "Entity.h"

Entity::Entity()
{
	speed = 200.f;
}

Entity::Entity(std::string textureFile)
{
	texture.loadFromFile(resourcePath() + "assets/textures/" + textureFile);
	sprite.setTexture(texture);
	speed = 200.f;
}

void Entity::setTexture(std::string textureFile)
{
	texture.loadFromFile(resourcePath() + "assets/textures/" + textureFile);
	sprite.setTexture(texture);
	speed = 200.f;
}

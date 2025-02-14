#include "Friend.h"

void Friend::Initialize()
{

}

void Friend::Load()
{
	sprite.setTexture(texture);
	texture.loadFromFile("Assets/Player/Textures/spritesheet.png");
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.scale(2, 2);
	sprite.setPosition(500, 600);
}

void Friend::Update()
{
}

void Friend::Draw()
{
}

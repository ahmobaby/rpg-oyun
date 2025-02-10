
#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
	texture.loadFromFile("Assets/Player/Textures/spritesheet.png");

		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(1600, 700));

		int XIndex = 0;
		int YIndex = 2;

		sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
		sprite.scale(sf::Vector2f(3, 3));
	
}

void Skeleton::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		sprite.move(0, -0.5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		sprite.move(0, 0.5);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		sprite.move(0.5, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		sprite.move(-0.5, 0);
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}


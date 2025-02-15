#include "Skeleton.h"
#include <iostream>
#include "Math.h"

void Skeleton::Initialize()
{
	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineThickness(1);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	size = sf::Vector2i(64, 64);
}

void Skeleton::Load()
{
	sprite.setTexture(texture);
	texture.loadFromFile("Assets/Player/Textures/spritesheet.png");
	int X�ndex = 0;
	int Y�ndex = 2;
	sprite.setPosition(1700, 800);


	sprite.setTextureRect(sf::IntRect(X�ndex * 64, Y�ndex * 64, 64, 64));
	sprite.scale(2, 2);
	boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
}

void Skeleton::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		sprite.move(0, -1 * skeletonSpeed * deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		sprite.move(0, 1 * skeletonSpeed * deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		sprite.move(1 * skeletonSpeed * deltaTime, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		sprite.move(-1 * skeletonSpeed * deltaTime, 0);

}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
}

#include "Player.h"
#include <iostream>
#include "Math.h"



void Player::Initialize()
{

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineThickness(1);
	boundingRectangle.setOutlineColor(sf::Color::Blue);
	size = sf::Vector2i(64, 64);

}





void Player::Load()
{
	sprite.setTexture(texture);
	texture.loadFromFile("Assets/Player/Textures/spritesheet.png");
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.scale(2, 2);
	boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));


}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
	boundingRectangle.setPosition(sprite.getPosition());



	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 10)));
		int i = bullets.size() - 1;
		bullets[i].setPosition(sprite.getPosition());
	}
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		sprite.move(0, -1 * playerSpeed * deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		sprite.move(0, 1 * playerSpeed * deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		sprite.move(1 * playerSpeed * deltaTime, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		sprite.move(-1 * playerSpeed * deltaTime, 0);




	if (Math::DidRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
	{
		std::cout << "Collisionnnn!! " << std::endl;
	}

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
	for (size_t i = 0; i < bullets.size(); i++)
		window.draw(bullets[i]);
}

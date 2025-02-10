
#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 0.5f;
	sf::Vector2f bulletDirection;


public:
	sf::Sprite sprite;


public:
	void Initialize();
	void Load();
	void Update(Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);
};


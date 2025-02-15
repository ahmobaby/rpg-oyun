#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"


class Player
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape>bullets;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	sf::Vector2f bulletDirection;
	float bulletSpeed = 0.5;
	float playerSpeed = 0.5;
	
	

public:
	sf::Sprite sprite;
	
public:
	void Initialize();
	void Load();
	void Update(float deltaTime,Skeleton& skeleton);
	void Draw(sf::RenderWindow& window);





};
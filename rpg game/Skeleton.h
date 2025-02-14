#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;
	std::vector<sf::RectangleShape>bullets;
	sf::RectangleShape boundingRectangle;
	sf::Vector2i size;
	float skeletonSpeed = 0.5;

public:
	sf::Sprite sprite;
public:
	void Initialize();
	void Load();
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);





};
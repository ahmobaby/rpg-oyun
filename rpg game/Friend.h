#pragma once
#include <SFML/Graphics.hpp>

class Friend
{

public:
	sf::Texture texture;
	sf::Sprite sprite;

	void Initialize();
	void Load();
	void Update();
	void Draw();

};


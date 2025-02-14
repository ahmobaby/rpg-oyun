#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"
#include<iostream>
#include"Friend.h"

int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME", sf::Style::Default);
	window.setFramerateLimit(360);

	Friend bla;
	Player player;
	Skeleton skeleton;
	sf::Clock clock;

	player.Initialize();
	skeleton.Initialize();


	player.Load();
	skeleton.Load();
	bla.Load();




	while (window.isOpen())
	{
		sf::Event event;


		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.Update(deltaTime,skeleton);
		skeleton.Update(deltaTime);
		 
		window.clear(sf::Color::Black);
		player.Draw(window);
		skeleton.Draw(window);
		window.draw(bla.sprite);

		window.display();

	}

	return  0;
}
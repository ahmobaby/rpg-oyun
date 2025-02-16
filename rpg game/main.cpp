#include <SFML/Graphics.hpp>
#include<iostream>

#include "Player.h"
#include "Skeleton.h"
#include"FrameRate.h"

int main()
{

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME", sf::Style::Default);
	window.setFramerateLimit(360);

	sf::Text name1;
	sf::Font font;
	


	


	FrameRate fps;
	Player player;
	Skeleton skeleton;
	sf::Clock clock;

	player.Initialize();
	skeleton.Initialize();
	fps.Initialize();


	player.Load();
	skeleton.Load();
	fps.Load();


	while (window.isOpen())
	{
		sf::Event event;
		
		sf::Time deltaTimeTimer = clock.restart();
		double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
		
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.Update(deltaTime, skeleton);
		skeleton.Update(deltaTime);
		fps.Update(deltaTime);
		

		window.clear(sf::Color::Black);
		player.Draw(window);
		skeleton.Draw(window);
		fps.Draw(window);
		

		window.display();

	}

	return  0;
}
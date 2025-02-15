#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Skeleton.h"
#include<iostream>

#include "Math.h"



int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

	Player player;
	Skeleton skeleton;

	
	

	player.Initialize();
	skeleton.Initialize();
	
	

	
	player.Load();
	skeleton.Load();

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		skeleton.Update();
		player.Update(skeleton);

		window.clear(sf::Color::Black);
		skeleton.Draw(window);
		player.Draw(window);
		
		window.display();
	}

	return 0;
}
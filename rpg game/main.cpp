#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
	sf::CircleShape shape(50);
	sf::RectangleShape shape2(sf::Vector2f(100, 200));
	shape.setPosition(sf::Vector2f(200, 300));
	sf::RectangleShape shape3(sf::Vector2f(150, 5));
	shape2.setPosition(500, 200);
    shape.setOutlineThickness(10);
	shape3.setRotation(60);
	shape3.setPosition(300, 100);
	
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == event.Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		window.draw(shape2);
		window.draw(shape3);
		window.draw(shape);
		shape.setFillColor(sf::Color::Red);
		shape2.setFillColor(sf::Color::Blue);
		shape.setOutlineColor(sf::Color::Yellow);
		shape3.setFillColor(sf::Color::Green);
		window.display();
	}

	return 0;

}


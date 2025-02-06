#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>

sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
	float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f normalizedVector;
	normalizedVector.x = vector.x / m;
	normalizedVector.y = vector.y / m;
	return normalizedVector;
}








int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG GAME");
	std::vector <sf::RectangleShape> bullets;
	float bulletSpeed = 0.5;

	
	
	
	

	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTexture);
	playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png");
	playerSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	playerSprite.scale(2, 2);
	playerSprite.setPosition(1700, 700);

    
	




	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	enemySprite.setTexture(enemyTexture);
	enemyTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png");
	int xýndex = 0;
    int yýndex = 2;
	enemySprite.setTextureRect(sf::IntRect(xýndex * 64, yýndex * 64, 64, 64));
	enemySprite.scale(2, 2);
	enemySprite.setPosition(100, 100);
	
	
//drection = NormalizeVector(direction);
	


	sf::Vector2f direction;


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
				playerSprite.move(0, -0.5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
				playerSprite.move(0, 0.5);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
				playerSprite.move(0.5, 0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
				playerSprite.move(-0.5, 0);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 10)));

				int i = bullets.size() - 1;
				bullets[i].setPosition(playerSprite.getPosition());
				
			

			}

			for (size_t i = 0; i < bullets.size(); i++)
			{
				direction = enemySprite.getPosition() - bullets[i].getPosition();
				direction = NormalizeVector(direction);
				bullets[i].setPosition(bullets[i].getPosition() + direction * bulletSpeed);
			}



        window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(enemySprite);
		for (size_t i = 0; i < bullets.size(); i++)
		{

			window.draw(bullets[i]);
		}

		

		window.display();


	}
	return 0;

}


    


	




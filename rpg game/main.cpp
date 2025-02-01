#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG GAME");
	
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
     
	playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png");
	playerSprite.setTexture(playerTexture);
	int XIndex = 0;
	int YIndex = 0;
	playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
    playerSprite.scale(2, 2);
	playerSprite.setPosition(100, 200);

  
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			if (event.type == event.Closed)
				window.close();
         }
          
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		
			playerSprite.move(0.5, 0);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		playerSprite.move(-0.5, 0);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		playerSprite.move(0, -0.5);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	    playerSprite.move(0, 0.5);
		


		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}

	return 0;

}


#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "GAME",sf::Style::Close);
	sf::RectangleShape wizard(sf::Vector2f(50.0f, 70.0f));
	sf::Texture playerTexture;

	playerTexture.loadFromFile("pls.png");
	wizard.setTexture(&playerTexture);

	sf::Sprite wizardsp;
	wizardsp.setTexture(playerTexture);
	wizardsp.setTextureRect(sf::IntRect(40, 50, 300, 400));
	wizardsp.setScale({ 0.1, 0.1 });
	
	while (window.isOpen())
	{
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			wizardsp.move(.2f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			wizardsp.move(-.2f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			wizardsp.move(0.f, -.2f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			wizardsp.move(0.f, .2f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		sf::Event cat;
		while (window.pollEvent(cat)) 
{
			if (cat.type == cat.Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(wizardsp);
		window.display();
		
		
	}
	return 0;
}
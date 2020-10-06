#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x,screen.y), "GAME",sf::Style::Close);
	sf::RectangleShape wizard(sf::Vector2f(50.0f, 70.0f));
	sf::Texture texturebg;
	sf::Texture playerTexture;

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x,screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f position(screen.x/2, screen.y/2);
	

	texturebg.loadFromFile("starbg.png");
	playerTexture.loadFromFile("pls.png");
	wizard.setTexture(&playerTexture);

	sf::Sprite sptexturebg;
	sptexturebg.setTexture(texturebg);
	sptexturebg.setPosition(0, 0);
	sptexturebg.setScale({ 1.0f,1.0f });


	
	sf::Sprite wizardsp;
	wizardsp.setTexture(playerTexture);
	wizardsp.setTextureRect(sf::IntRect(40, 50, 300, 400));
	wizardsp.setScale({ 0.1, 0.1 });


	
	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed) {
				window.close();
			}
		}
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


		if (wizardsp.getPosition().x+10>screen.x/2)
		{
			position.x = wizardsp.getPosition().x+10;
		}
		else {
			position.x = screen.x/2;
		}
		if (wizardsp.getPosition().y + 10 > screen.y / 2)
		{
			position.y = wizardsp.getPosition().y + 10;
		}
		else {
			position.y = screen.y / 2;
		}

		view.setCenter(position);
		
		window.setView(view);
		window.draw(sptexturebg);
		
		
		
		
		window.draw(wizardsp);
		window.display();
		window.clear();
		
		
	}
	return 0;
}
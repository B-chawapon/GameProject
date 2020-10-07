#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	sf::Vector2i screen(1080, 720);
	sf::RenderWindow window(sf::VideoMode(screen.x, screen.y), "GAME", sf::Style::Close);
	sf::RectangleShape wizard(sf::Vector2f(50.0f, 70.0f));
	sf::Texture texturebg;
	sf::Texture playerTexture;



	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen.x, screen.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	sf::Vector2f viewbg(screen.x / 2, screen.y / 2);


	texturebg.loadFromFile("starbg.png");
	playerTexture.loadFromFile("blackmage.png");
	wizard.setTexture(&playerTexture);

	sf::Sprite sptexturebg;
	sptexturebg.setTexture(texturebg);
	sptexturebg.setPosition(0, 0);
	sptexturebg.setScale({ 1.5f,1.5f });

	int spritetextureSizeX = texturebg.getSize().x;
	int spritetextureSizeY = texturebg.getSize().y;

	int spriteSizeX = playerTexture.getSize().x / 5;
	int spriteSizeY = playerTexture.getSize().y / 6;

	sf::Sprite wizardsp;
	wizardsp.setTexture(playerTexture);
	wizardsp.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
	wizardsp.setScale({ 0.8f, 0.8f });
	wizardsp.setPosition(screen.x, screen.y);

	int temp = 1;
	int animationx = 0;
	int animationy = 0;

	while (window.isOpen())
	{

		
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			wizardsp.move(0.f, -.2f);
			wizardsp.setTextureRect(sf::IntRect(spriteSizeX * animationx, spriteSizeY * animationy, spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			wizardsp.move(0.f, .2f);
			wizardsp.setTextureRect(sf::IntRect(spriteSizeX * animationx, spriteSizeY * (3 + animationy), spriteSizeX, spriteSizeY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			wizardsp.move(.2f, 0.f);
			wizardsp.setTextureRect(sf::IntRect(spriteSizeX * animationx, spriteSizeY * (3 + animationy), spriteSizeX, spriteSizeY));

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			wizardsp.move(-.2f, 0.f);
			wizardsp.setTextureRect(sf::IntRect(spriteSizeX * animationx, spriteSizeY * animationy, spriteSizeX, spriteSizeY));

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			wizardsp.setTextureRect(sf::IntRect(70, 104, 35, 52));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			wizardsp.setTextureRect(sf::IntRect(105, 52, 35, 52));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		animationx++;
		if (animationx >= 5) {
			temp++;
			animationx = 0;
			animationy = 1;
			if (temp == 3)
			{
				animationy = 0;
				temp = 1;
			}

		}


		if (wizardsp.getPosition().x + 10 > screen.x / 2)
		{
			viewbg.x = wizardsp.getPosition().x + 10;
			if (viewbg.x == spritetextureSizeX)
			{
				viewbg.x = 0;
			}
		
		}
		else {
			viewbg.x = screen.x / 2;
		}

		if (wizardsp.getPosition().y + 10 > screen.y / 2)
		{
			viewbg.y = wizardsp.getPosition().y + 10;
		}
		else {
			viewbg.y = screen.y / 2;
		}



		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed) {
				window.close();
			}

		}
		view.setCenter(viewbg);
		window.setView(view);
		window.draw(sptexturebg);
		window.draw(wizardsp);
		window.display();
		window.clear();
		
		
		
	}
	return 0;
}
#include "player.h"

player::player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;

	body.setSize(sf::Vector2f(48.0f, 72.0f));
	body.setOrigin(body.getSize() / 1.0f);
	body.setPosition(0.0f, 0.0f);
	body.setTexture(texture);
}

player::~player()
{
}

void player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= speed * deltaTime;
		row = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += speed * deltaTime;
		row = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
		row = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
		row = 4;
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))

	if (row == 3 && movement.y == 0) row = 3;
	if (row == 0 && movement.y == 0) row = 0;
	if (row == 1 && movement.x == 0) row = 1;
	if (row == 4 && movement.x == 0) row = 4;

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
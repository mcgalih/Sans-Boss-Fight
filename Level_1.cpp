#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Gl
{
	void Gameplay::level_1_Init()
	{
		_heart = new Heart(_data, { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50 });

		left.setSize(sf::Vector2f{ 2.0f,180.0f });
		left.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);
		left.setOrigin(sf::Vector2f{2.0f/2.0f + 125.0f,180.0f/2.0f});
		left.setFillColor(sf::Color::Green);

		right.setSize(sf::Vector2f{ 2.0f,180.0f });
		right.setPosition(SCREEN_WIDTH / 2 + 127, SCREEN_HEIGHT / 2 + 50);
		right.setOrigin(sf::Vector2f{0.0f,180.0f / 2.0f });
		right.setFillColor(sf::Color::Green);

		up.setSize(sf::Vector2f{ 250.0f,2.0f });
		up.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 40);
		up.setOrigin(sf::Vector2f{ 250.0f/2.0f,0.0f });
		up.setFillColor(sf::Color::Green);

		bottom.setSize(sf::Vector2f{ 250.0f,2.0f });
		bottom.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 140);
		bottom.setOrigin(sf::Vector2f{ 250.0f / 2.0f,0.0f });
		bottom.setFillColor(sf::Color::Green);

		box.setSize(sf::Vector2f{ 250.0f,180.0f });
		box.setOrigin(sf::Vector2f{ 250.0f / 2.0f, 180.0f / 2.0f });
		box.setFillColor(sf::Color::Transparent);
		box.setOutlineColor(sf::Color::White);
		box.setOutlineThickness(2.0f);
		box.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);
	}

	void Gameplay::level_1_Update(float dt)
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		else if (_heart->Intersects(right)) _heart->MovePosition({ -1.0f,0.0f });
		else if (_heart->Intersects(up)) _heart->MovePosition({ 0.0f,1.0f });
		else if (_heart->Intersects(bottom)) _heart->MovePosition({ 0.0f,-1.0f });
		else _heart->Controls();
	}

	void Gameplay::level_1_Draw()
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		else if (_heart->Intersects(right)) _heart->MovePosition({ -1.0f,0.0f });
		else if (_heart->Intersects(up)) _heart->MovePosition({ 0.0f,1.0f });
		else if (_heart->Intersects(bottom)) _heart->MovePosition({ 0.0f,-1.0f });
		_data->window.clear();
		_data->window.draw(box);
		_heart->draw();
		_data->window.display();
	}
}
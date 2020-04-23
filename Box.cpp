#include "Objects.hpp"

namespace Gl
{
	box::box(GameDataRef data, Heart *heart)
		:_data(data) , _heart(heart)
	{
		left.setSize(sf::Vector2f{ 2.0f,180.0f });
		left.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 37);
		left.setOrigin(sf::Vector2f{ 2.0f / 2.0f + 125.0f,180.0f / 2.0f });
		left.setFillColor(sf::Color::Green);

		right.setSize(sf::Vector2f{ 2.0f,180.0f });
		right.setPosition(SCREEN_WIDTH / 2 + 127, SCREEN_HEIGHT / 2 + 37);
		right.setOrigin(sf::Vector2f{ 0.0f,180.0f / 2.0f });
		right.setFillColor(sf::Color::Green);

		up.setSize(sf::Vector2f{ 250.0f,2.0f });
		up.setPosition(400.0f, 245.0f);
		up.setOrigin(sf::Vector2f{ 250.0f / 2.0f,0.0f });
		up.setFillColor(sf::Color::Green);

		bottom.setSize(sf::Vector2f{ 250.0f,2.0f });
		bottom.setPosition(400.0f, 428.0f);
		bottom.setOrigin(sf::Vector2f{ 250.0f / 2.0f,0.0f });
		bottom.setFillColor(sf::Color::Green);

		_SquareBox.setSize(sf::Vector2f{ 250.0f,180.0f });
		_SquareBox.setOrigin(sf::Vector2f{ 250.0f / 2.0f, 180.0f / 2.0f });
		_SquareBox.setFillColor(sf::Color::Transparent);
		_SquareBox.setOutlineColor(sf::Color::White);
		_SquareBox.setOutlineThickness(2.0f);
		_SquareBox.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 37);
	}

	void box::SquareBox(sf::Vector2f pos)
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		else if (_heart->Intersects(right)) _heart->MovePosition({ -1.0f,0.0f });
		else if (_heart->Intersects(up)) _heart->MovePosition({ 0.0f,1.0f });
		else if (_heart->Intersects(bottom)) _heart->MovePosition({ 0.0f,-1.0f });
		else _heart->Controls(pos);
	}

	void box::drawSquareBox()
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		else if (_heart->Intersects(right)) _heart->MovePosition({ -1.0f,0.0f });
		else if (_heart->Intersects(up)) _heart->MovePosition({ 0.0f,1.0f });
		else if (_heart->Intersects(bottom)) _heart->MovePosition({ 0.0f,-1.0f });

		_data->window.draw(_SquareBox);
	}


}
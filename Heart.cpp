#include "Objects.hpp"

namespace Gl
{
	Heart::Heart(GameDataRef data)
		:_data(data)
	{
		_heart.setTexture(_data->assets.GetTexture(HEART_SPRITE));
		_heart.setOrigin(17 / 2, 15 / 2);
		boolfirstpos = true;
	}
	bool Heart::Intersects(sf::RectangleShape& shape)
	{
		if (shape.getGlobalBounds().intersects(_heart.getGlobalBounds()))
			return true;
		else return false;
	}
	sf::Vector2f Heart::getPosition() { return pos; }
	void Heart::setColor(sf::Color& color) { _heart.setColor(color); }
	float Heart::getXposition() { return pos.x; };
	float Heart::getYposition() { return pos.y; };
	void Heart::draw() { _data->window.draw(_heart); }

	void Heart::setPosition(sf::Vector2f setPos)
	{
		pos = setPos;
		_heart.setPosition(pos);
	}
	void Heart::Controls(sf::Vector2f firstPosition)
	{
		if (boolfirstpos == true)
		{
			pos = firstPosition;
			_heart.setPosition(pos);
			boolfirstpos = false;
		}
		else
		{
			sf::Vector2f dir = { 0.0f,0.0f };

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				dir.y -= 1.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				dir.y += 1.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				dir.x -= 1.0f;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				dir.x += 1.0f;
			}
			vel = dir * speed;
			pos += vel * dt;
			_heart.setPosition(pos);
		}
	}

	void Heart::MovePosition(sf::Vector2f dir)
	{
		vel = dir * speed;
		pos += vel * dt;
		_heart.setPosition(pos);
	}

}
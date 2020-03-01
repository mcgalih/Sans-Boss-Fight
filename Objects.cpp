#include "Objects.hpp"

namespace Gl
{
	Heart::Heart(GameDataRef data, const sf::Vector2f& pos)
		: pos(pos), _data(data)
	{
		_heart.setTexture(_data->assets.GetTexture(HEART_SPRITE));
		_heart.setOrigin(17 / 2, 15 / 2);
	}

	void Heart::Movement()
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

	void Heart::setColor(sf::Color& color) { _heart.setColor(color); }
	void Heart::setPosition(sf::Vector2f& setPos) { pos = setPos; }
	sf::Vector2f Heart::getPosition() { return pos; };
	sf::FloatRect Heart::getGlobalBounds()
	{
		batas = _heart.getGlobalBounds();
		return batas;
	}
	void Heart::draw() { _data->window.draw(_heart); }
}
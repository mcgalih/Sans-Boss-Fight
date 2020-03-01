#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	class Heart
	{
	public:
		Heart(GameDataRef data ,const sf::Vector2f& pos) : pos(pos), _data(data)
		{
			_heart.setTexture(_data->assets.GetTexture(HEART_SPRITE));
			_heart.setOrigin(17 / 2, 15 / 2);
		}

		void Movement()
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

		void setColor(sf::Color& color) { _heart.setColor(color); }
		void setPosition(sf::Vector2f& setPos) { pos = setPos; }
		sf::Sprite getSprite() const { return _heart; }
		sf::Vector2f getPosition() { return pos; };
		sf::FloatRect getGlobalBounds()
		{
			batas = _heart.getGlobalBounds();
			return batas;
		}
		void draw() { _data->window.draw(_heart); }

	private:
		GameDataRef _data;
		sf::FloatRect batas;
		sf::Sprite _heart;
		sf::Vector2f pos;
		sf::Vector2f vel = { 0.0f,0.0f };
		const float speed = 300.0f;
		const float dt = 1.0f / 60.0f;
	};
}
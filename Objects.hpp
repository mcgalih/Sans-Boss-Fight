#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	class Heart
	{
	public:
		Heart(GameDataRef data, const sf::Vector2f& pos);

		void Controls();
		bool Intersects(sf::RectangleShape& shape);
		void setColor(sf::Color& color);
		void setPosition(sf::Vector2f setPos);
		float getXposition();
		float getYposition();
		void MovePosition(sf::Vector2f dir);
		void draw();

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
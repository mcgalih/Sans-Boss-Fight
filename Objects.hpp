#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <string.h>
#include <iostream>

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
		sf::Vector2f Center();
		float getXposition();
		float getYposition();
		void MovePosition(sf::Vector2f dir);
		void draw();

	private:
		GameDataRef _data;
		sf::Sprite _heart;
		sf::Vector2f pos;
		sf::Vector2f vel = { 0.0f,0.0f };
		const float speed = 300.0f;
		const float dt = 1.0f / 60.0f;
	};

	class Sans
	{
	public:
		Sans(GameDataRef data);
		void animation(float dt);
		void setPosition(sf::Vector2f setPos);
		void draw();
	private:
		GameDataRef _data;
		sf::Vector2f pos;
		sf::Sprite _sans;
		int nFrames = 3;
		sf::IntRect frames[3];
		int iFrame = 0;
		float holdtime = 0.15f;
		float time = 0.0f;
	};

	class dialog
	{
	public:
		dialog(GameDataRef data);
		void setString(std::string text);
		bool displaying();
		void draw();

	private:
		GameDataRef _data;
		sf::Sprite Dialogbox;
		float width = 225.0f;
		float widthmove1, widthmove2, widthmove3;
		//float delay;
		std::string str;
		sf::Text text1, text2, text3;
		sf::ConvexShape typing1, typing2, typing3;
		sf::Sound dialogsfx;
		sf::Time timesfx;
		bool soundstatus, display;
	};
}
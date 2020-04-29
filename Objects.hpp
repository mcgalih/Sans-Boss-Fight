#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include <string>
#include <iostream>
#include <vector>

namespace Gl
{
	class Heart
	{
	public:
		Heart(GameDataRef data);

		void Controls(sf::Vector2f firstpos);
		bool Intersects(sf::RectangleShape& shape);
		void setColor(sf::Color& color);
		void setPosition(sf::Vector2f setPos);
		sf::Vector2f getPosition();
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
		bool boolfirstpos;
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
		void times(int time);
		void setString(int iteration, std::string text);
		void process();
		void draw();
		bool displaying();
		bool i_dialog(int i);

	private:
		GameDataRef _data;
		sf::Sprite Dialogbox;
		float width = 225.0f;
		float widthmove1, widthmove2, widthmove3;
		float delay;
		sf::Text text1, text2, text3;
		sf::ConvexShape typing1, typing2, typing3;
		sf::Sound dialogsfx;
		sf::Time tickSfx;
		bool soundstatus, display;
		std::vector<std::string> speak;
		std::vector<bool> dialog_i;
		int change;
	};

	class box
	{
	public:
		box(GameDataRef data, Heart *heart);

		void SquareBox(sf::Vector2f pos);
		void drawSquareBox();

		void drawRectangleBox();
		void drawAttackBox();

	private:
		Heart* _heart;
		GameDataRef _data;
		sf::RectangleShape left, up, bottom, right;
		sf::RectangleShape _SquareBox, _RectangleBox, _AttackBox;
	};

}
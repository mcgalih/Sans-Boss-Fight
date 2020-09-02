#pragma once
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	class Shake
	{
	public:
		Shake(GameDataRef data);
		void SetDirectionRight();

	private:
		GameDataRef _data;
		bool back;
		float x, y, range;
		sf::Vector2f vel;
		sf::Vector2f CenterPos;
		const float speedmove = 300.0f;
		const float dt = 1.0f / 60.0f;
		sf::View view;
	};
}
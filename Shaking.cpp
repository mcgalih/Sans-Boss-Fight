#include "Shaking.hpp"

namespace Gl
{
	Shake::Shake(GameDataRef data) :_data(data)
	{
		back = false;
		x = SCREEN_WIDTH / 2;
		y = SCREEN_HEIGHT / 2;
		range = x - 10;
		CenterPos = { x,y };
		view.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
		view.setCenter(CenterPos);
	}

	void Shake::SetDirectionRight()
	{
		sf::Vector2f dir = { 0.0f, 0.0f };
		if (back == false)
		{
			dir.x -= 1.0f;
			CenterPos.x += dir.x;
			if (CenterPos.x < range) back = true;
		}
		else
		{
			dir.x += 1.0f;
			CenterPos.x += dir.x;
			if (CenterPos.x > x) CenterPos.x = x;
		}
		vel = dir * speedmove;
		CenterPos += vel * dt;
		view.setCenter(CenterPos);
		_data->window.setView(view);
	}
}
#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Gl
{
	void Gameplay::level_1(float dt)
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		else _heart->Controls();
	}

	void Gameplay::Draw_level_1()
	{
		if (_heart->Intersects(left)) _heart->MovePosition({ 1.0f,0.0f });
		_data->window.clear();
		_data->window.draw(box);
		_heart->draw();
		_data->window.draw(left);
		_data->window.display();
	}
}
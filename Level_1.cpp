#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Gl
{
	void Gameplay::level_1_Init()
	{
		_heart = new Heart(_data);
		_sans = new Sans(_data);
		_dialog = new dialog(_data);
		_box = new box(_data, _heart);

		skuy.setSize(sf::Vector2f{ 120.0f, 25.0f });
		skuy.setFillColor(sf::Color::Green);
		skuy.setOrigin(120.0f / 2.0f, 0.0f);
		skuy.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);

	}

	void Gameplay::level_1_Update(float dt)
	{
		_dialog->setString("012345678901234567890123binomskuy dulu duuuude  hirruuup");
		if (_heart->Intersects(skuy)) health -= 1.0f;
		if (health < 0.0f) health = 0.0f;
		
		_sans->animation(dt);
		
		sf::Vector2f pos = { 400.0f, 424.0f };
		
		if (_dialog->displaying() == true) _heart->setPosition({ 400.0f, 337.0f });
		else if (_dialog->displaying() == false)
		{
			_box->SquareBox(pos);
		}
	}

	void Gameplay::level_1_Draw()
	{
		_data->window.draw(skuy);

		_box->drawSquareBox();
		_heart->draw();
		_sans->draw();
		_dialog->draw();
		
	}
}
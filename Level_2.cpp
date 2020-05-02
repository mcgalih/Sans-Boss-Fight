#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	void Gameplay::level_2_Init()
	{
		sans2 = new Sans(_data);

		skuy.setSize(sf::Vector2f{ 120.0f, 25.0f });
		skuy.setFillColor(sf::Color::Green);
		skuy.setOrigin(120.0f / 2.0f, 0.0f);
		skuy.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);

	}

	void Gameplay::level_2_Update(float dt)
	{
		_dialog->times(3);
		_dialog->setString(1, "this taste...");
		_dialog->setString(2, "is the taste of drugs");
		_dialog->setString(3, "DRUG DEALER");
		_dialog->process();

		if (_heart->Intersects(skuy)) _health->setHP(-1.0f);
		sans2->animation(dt);

		sf::Vector2f pos = { 400.0f, 424.0f };

		if (_dialog->displaying() == true) _heart->setPosition(pos);
		else if (_dialog->displaying() == false)
		{
			_box->SquareBox(pos);
		}
	}

	void Gameplay::level_2_Draw()
	{
		_data->window.draw(skuy);

		_box->drawSquareBox();
		_heart->draw();
		sans2->draw();
		_data->window.draw(fixglitch);
		_dialog->draw();

	}
}
#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	void Gameplay::level_1_Init()
	{
		_sans = new Sans(_data);

		_dialog->times(4);
		_dialog->setString(1, "hahaha");
		_dialog->setString(2, "test 2 ditambah beberapa kalimat");
		_dialog->setString(3, "i giosans giovania have a dream");
		_dialog->setString(4, "to become a gangstar");

		delay = 0.0f;
		stopdelay = false;
		firstStandAnim = false;

		skuy.setSize(sf::Vector2f{ 120.0f, 25.0f });
		skuy.setFillColor(sf::Color::Green);
		skuy.setOrigin(120.0f / 2.0f, 0.0f);
		skuy.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);

	}

	void Gameplay::level_1_Update(float dt)
	{
		if (stopdelay == false)
		{
			delay += 1.0f;
			if (delay == 65.0f) stopdelay = true;
		}
		if (stopdelay == true) _dialog->process();

		if (_dialog->i_dialog(3)) firstStandAnim = true;
		if (firstStandAnim == true)
		{
			time += dt;
			if (time >= holdtime)
			{
				time -= holdtime;
				++iFrame;
				if (iFrame >= 6) holdtime = 0.15f;
				if (iFrame >= nFrames)
				{
					iFrame = 6;
				}
			}
			stand.setTextureRect(frames[iFrame]);
		}
		
		if (_heart->Intersects(skuy)) _health->setHP(-1.0f);
		_sans->animation(dt);
		
		sf::Vector2f pos = { 400.0f, 424.0f };
		
		if (_dialog->displaying() == true) _heart->setPosition(pos);
		else if (_dialog->displaying() == false)
		{
			_box->SquareBox(pos);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				firststate = false;
				change.push_back(true);
				delete _sans;
				_dialog->reset();
			}
		}
	}

	void Gameplay::level_1_Draw()
	{
		_data->window.draw(skuy);
		_box->drawSquareBox();

		if (firstStandAnim == true) _data->window.draw(stand);
		_heart->draw();
		_sans->draw();
		_data->window.draw(fixglitch);
		if (stopdelay == true) _dialog->draw();
		
	}
}
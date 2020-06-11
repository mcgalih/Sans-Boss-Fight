#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	void Gameplay::level_1_Init()
	{
		_dialog->times(5);
		_dialog->setString(1, "Everytime i close my    eyes...");
		_dialog->setString(2, "I wake up feeling so    angry");
		_dialog->setString(3, "Seeing a guy like you...");
		_dialog->setString(4, "[ GOLD EXPERIENCE ]");
		_dialog->setString(5, "M U D A");

		delay = 0.0f;
		stopdelay = false;
		firstStandAnim = false;

	}

	void Gameplay::level_1_Update(float dt)
	{
		if (stopdelay == false)
		{
			delay += 1.0f;
			if (delay == 65.0f) stopdelay = true;
		}
		if (stopdelay == true) _dialog->process();

		// dialog and expressions
		if (_dialog->i_dialog(2) || _dialog->i_dialog(3)) _sans->angry(dt);
		else if (_dialog->i_dialog(5)) {
			if (_dialog->displaying() == true) _sans->rage(dt);
			else _sans->normal(dt);
		} else _sans->normal(dt);

		if (_dialog->i_dialog(4)) firstStandAnim = true;

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
		
		sf::Vector2f pos = { 400.0f, 424.0f };
		
		if (_dialog->displaying() == true) _heart->setPosition(pos);
		else if (_dialog->displaying() == false) {
			_box->SquareBox(pos);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				level += 1;
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
		if (stopdelay == true) _dialog->draw();
		
	}
}
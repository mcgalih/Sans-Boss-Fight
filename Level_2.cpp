#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	void Gameplay::level_2_Update(float dt)
	{
		_dialog->times(2);
		_dialog->setString(1, "this taste...");
		_dialog->setString(2, "is the taste of drugs");
		_dialog->process();

		if (_heart->Intersects(skuy)) _health->setHP(-1.0f);
		_sans->normal(dt);

		sf::Vector2f pos = { 400.0f, 424.0f };

		if (_dialog->displaying() == true) _heart->setPosition(pos);
		else if (_dialog->displaying() == false) {
			_box->SquareBox(pos);
		}
	}

	void Gameplay::level_2_Draw()
	{
		_data->window.draw(skuy);

		_box->drawSquareBox();
		_heart->draw();
		_sans->draw();
		_dialog->draw();

	}
}
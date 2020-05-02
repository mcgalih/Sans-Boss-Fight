#include "Objects.hpp"

namespace Gl
{
	Health::Health(GameDataRef data) :_data(data)
	{
		healthpoint = 120.0f;
		number = healthpoint;
		count = std::to_string(number);

		hp.setFillColor(sf::Color::Yellow);
		hp.setOrigin(120.0f / 2.0f, 0.0f);
		hp.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 138);
		hp.setSize(sf::Vector2f{ healthpoint, 25.0f });

		hpback.setSize(sf::Vector2f{ 120.0f, 25.0f });
		hpback.setFillColor(sf::Color::Red);
		hpback.setOrigin(120.0f / 2.0f, 0.0f);
		hpback.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 138);

		hp_number.setFont(_data->assets.GetFont(HUD_FONT));
		hp_number.setString(count+"/120");
		hp_number.setCharacterSize(20);
		hp_number.setPosition(520.0f, 440.0f);
		hp_number.setFillColor(sf::Color::White);
	}

	float Health::total() { return healthpoint; }

	void Health::setHP(float d_hp)
	{
		healthpoint += d_hp;
		number = healthpoint;

		if (healthpoint < 0.0f) healthpoint = 0.0f;
		hp.setSize(sf::Vector2f{ healthpoint, 25.0f });

		if (number < 0) number = 0;
		count = std::to_string(number);
		hp_number.setString(count + "/120");
	}

	void Health::draw()
	{
		_data->window.draw(hpback);
		_data->window.draw(hp);
		_data->window.draw(hp_number);
	}
}
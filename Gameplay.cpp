#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	Gameplay::Gameplay(GameDataRef data) :_data(data)
	{

	}

	void Gameplay::Init()
	{
		_bgm.openFromFile(BGM_FILE_PATH);
		_bgm.play();
		_heart = new Heart(_data, { 0.0f,0.0f });
	}

	void Gameplay::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void Gameplay::Update(float dt)
	{
		_heart->Movement();
	}

	void Gameplay::Draw(float dt)
	{
		_data->window.clear();
		_heart->draw();
		_data->window.display();
	}

}
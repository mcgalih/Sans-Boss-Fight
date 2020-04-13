#include "Objects.hpp"

namespace Gl
{
	Sans::Sans(GameDataRef data)
		:_data(data)
	{
		pos = { 330,40 };
		_sans.setTexture(_data->assets.GetTexture(SANS_BODY));
		_sans.setScale(0.18, 0.18);
		_sans.setPosition(pos);
		int width = _sans.getLocalBounds().width;
		int height = _sans.getLocalBounds().height;
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { 0 + i * width / nFrames , 0, width / nFrames , height };
		}
	}

	void Sans::animation(float dt)
	{
		time += dt;
		if (time >= holdtime)
		{
			time -= holdtime;
			++iFrame;
			if (iFrame >= nFrames) iFrame = 0;
		}
		_sans.setTextureRect(frames[iFrame]);

	}

	void Sans::setPosition(sf::Vector2f setPos) { pos = setPos; }
	void Sans::draw() { _data->window.draw(_sans); }
}
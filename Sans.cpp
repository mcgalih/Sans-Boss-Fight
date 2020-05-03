#include "Objects.hpp"

namespace Gl
{
	Sans::Sans(GameDataRef data)
		:_data(data)
	{
		pos = { 330,40 };
		_sans.setTexture(_data->assets.GetTexture(SANS_BODY));
		_sans.setPosition(pos);
		int width = _sans.getLocalBounds().width;
		int height = _sans.getLocalBounds().height;
		
		// normal
		for (int i = 0; i < nFrames; i++)
		{
			normal_frames[i] = { 0 + i * width / nFrames , 0, width / nFrames , height / 3 };
		}
		// angry
		for (int i = 0; i < nFrames; i++)
		{
			angry_frames[i] = { 0 + i * width / nFrames , height / 3, width / nFrames , height/3 };
		}
		//rage
		for (int i = 0; i < nFrames; i++)
		{
			rage_frames[i] = { 0 + i * width / nFrames , height * 2/3, width / nFrames , height / 3 };
		}
	}

	void Sans::normal(float dt)
	{
		holdtime = 0.15f;
		time += dt;
		if (time >= holdtime)
		{
			time -= holdtime;
			++iFrame;
			if (iFrame >= nFrames) iFrame = 0;
		}
		_sans.setTextureRect(normal_frames[iFrame]);

	}

	void Sans::angry(float dt)
	{
		holdtime = 0.15f;
		time += dt;
		if (time >= holdtime)
		{
			time -= holdtime;
			++iFrame;
			if (iFrame >= nFrames) iFrame = 0;
		}
		_sans.setTextureRect(angry_frames[iFrame]);
	}

	void Sans::rage(float dt)
	{
		holdtime = 0.1f;
		time += dt;
		if (time >= holdtime)
		{
			time -= holdtime;
			++iFrame;
			if (iFrame >= nFrames) iFrame = 0;
		}
		_sans.setTextureRect(rage_frames[iFrame]);
	}

	void Sans::setPosition(sf::Vector2f setPos) { pos = setPos; }
	void Sans::draw()
	{ 

		_data->window.draw(_sans);
	}
}
#pragma once
#include "UIObject.h"
#include"PlatformPlayer.h"

class CDBarBorder :public UIObject
{
public:
	CDBarBorder(SDL_Rect s, SDL_FRect d, SDL_Renderer* r, SDL_Texture* t) :UIObject(s, d, r, t)
	{
		/*animFrame = 0;
		maxAnimFrame = 3;
		changeTime = 0;
		animFramerate = 0.1;*/
		isDisplay = true;
		UIType = "CDBarBorder";
	}
	virtual void Update() override;
	virtual void Render() override;

private:
	/*int animFrame;
	int maxAnimFrame;
	double animFramerate;
	Uint32 changeTime;*/
};

class CDBarFiller :public UIObject
{
public:
	CDBarFiller(SDL_Rect s, SDL_FRect d, SDL_Renderer* r, SDL_Texture* t, PlatformPlayer* hero) :UIObject(s, d, r, t)
	{
		maxWidth = d.w;
		isDisplay = true;
		this->hero = hero;
		UIType = "SoulBarFiller";
	}
	virtual void Update() override;
	virtual void Render() override;

	PlatformPlayer* hero;
private:
	double HeaPercent;
	double maxWidth;

	//PlatformPlayer* hero;
};
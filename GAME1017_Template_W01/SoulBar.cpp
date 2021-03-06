#include "SoulBar.h"
#include "MathManager.h"
#include "TextureManager.h"

void SoulBarBorder::Update()
{
	if ((this->changeTime + animFramerate * 1000) < SDL_GetTicks())
	{
		this->changeTime = SDL_GetTicks();
		this->animFrame++;
		if (this->animFrame > this->maxAnimFrame)
			this->animFrame = 0;
		this->SetSrcCords(this->GetSrcP()->w * this->animFrame, 0);
	}
}

void SoulBarBorder::Render()
{
	if (isDisplay == true)
	{
		SDL_Rect tempRect = MAMA::ConvertFRect2Rect(m_dst);
		SDL_RenderCopy(m_pRend, TextureManager::GetTexture("SoulBarBorder"), &m_src, &tempRect);
	}
}

void SoulBarFiller::Update()
{
	this->SetDstSize(this->maxWidth*(hero->GetSoul()/hero->m_maxSoul),this->m_dst.h);
	//std::cout << this->maxWidth * (hero->GetSoul() / hero->m_maxSoul) << std::endl;
}

void SoulBarFiller::Render()
{
	if (isDisplay == true)
	{
		SDL_Rect tempRect = MAMA::ConvertFRect2Rect(m_dst);
		SDL_RenderCopy(m_pRend, TextureManager::GetTexture("SoulBarFiller"), &m_src, &tempRect);
	}
}
#pragma once
#ifndef _CBULLET_H_
#define _CBULLET_H_

#include "Main.h"
#include "Sprite.h"

class CBullet
{
public:
	CBullet(const BackBuffer* pBackBuffer);
	CBullet(const BackBuffer* pBackBuffer, const char* szImageFile, COLORREF crTransparentColor);
	virtual ~CBullet();

	void			Update(float dt);
	void			Draw();
	Vec2& Position();
	Vec2& Velocity();
	int				Width() { return m_bSprite->width(); }
	int				Height() { return m_bSprite->height(); }
	float			getB_speed() { return bullet_speed; }

private:
	Sprite* m_bSprite;
	float						bullet_speed;
};

#endif;
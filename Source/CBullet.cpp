
#include "CBullet.h"


CBullet::CBullet(const BackBuffer* pBackBuffer)
{
	m_bSprite = new Sprite("data/bullet.bmp", RGB(0xff, 0x00, 0xff));
	m_bSprite->setBackBuffer(pBackBuffer);
	bullet_speed = 10;
	
}

CBullet::CBullet(const BackBuffer* pBackBuffer, const char* szImageFile, COLORREF crTransparentColor)
{
	m_bSprite = new Sprite(szImageFile, crTransparentColor);
	m_bSprite->setBackBuffer(pBackBuffer);
}
CBullet::~CBullet()
{
	delete m_bSprite;
}

void CBullet::Update(float dt)
{
	m_bSprite->update(dt);
}

void CBullet::Draw()
{
	m_bSprite->draw();
}

Vec2& CBullet::Position()
{
	return m_bSprite->mPosition;
}

Vec2& CBullet::Velocity()
{
	return m_bSprite->mVelocity;
}

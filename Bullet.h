// Bullet.h
// By Anna
// March 7, 2021.
#ifndef BULLET_H
#define BULLET_H

#include "main.h"
#include "Vec2.h"
#include "BackBuffer.h"

class Bullet
{
public:
	Bullet(int imageID, int maskID);
	Bullet(const char* szImageFile, const char* szMaskFile);
	Bullet(const char* szImageFile, COLORREF crTransparentColor);

	virtual ~Bullet();

	int width() { return mImageBM.bmWidth; }
	int height() { return mImageBM.bmHeight; }
	void update(float dt);

	void setBackBuffer(const BackBuffer* pBackBuffer);
	virtual void draw();

public:
	// Keep these public because they need to be
	// modified externally frequently.
	Vec2 mPosition;
	Vec2 mVelocity;

private:
	// Make copy constructor and assignment operator private
	// so client cannot copy Bullets. We do this because
	// this class is not designed to be copied because it
	// is not efficient--copying bitmaps is slow (lots of memory).
	Bullet(const Bullet& rhs);
	Bullet& operator=(const Bullet& rhs);

protected:
	HBITMAP mhImage;
	HBITMAP mhMask;
	BITMAP mImageBM;
	BITMAP mMaskBM;

	HDC mhBulletDC;
	const BackBuffer* mpBackBuffer;

	COLORREF mcTransparentColor;
	void drawTransparent();
	void drawMask();
};

// AnimatedBullet
// by Anna
// March 9, 2021
class AnimatedBullet : public Bullet
{
public:
	//NOTE: The animation is on a single row.
	AnimatedBullet(const char* szImageFile, const char* szMaskFile, const RECT& rcFirstFrame, int iFrameCount);
	virtual ~AnimatedBullet() { }

public:
	void SetFrame(int iIndex);
	int GetFrameCount() { return miFrameCount; }

	virtual void draw();

protected:
	POINT mptFrameStartCrop;// first point of the frame (upper-left corner)
	POINT mptFrameCrop;		// crop point of frame
	int miFrameWidth;		// width
	int miFrameHeight;		// height
	int miFrameCount;		// number of frames
};



#endif // Bullet_H


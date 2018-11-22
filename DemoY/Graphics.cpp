// Graphics.cpp: implementation of the Graphics class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DemoY.h"
#include "Graphics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

void Graphics::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	/*
	void DDALine(int x1, int y1, int x2, int y2)
	{
		double dx,dy,e,x,y;
		dx = x2 -x1;
		dy = y2- y1;
		e = (fabs(dx) > fabs(dy)) ? fabs(dx):fabs(dy);
		dx/=e;
		dy/=e;
		x = x1;
		y = y1;
		for (int i=1;i<=e;i++)
		{
			SetPixel((int)(x+0.5),(int)(y+0.5),color);
			x+=dx;
			y+=dy;
		}
	}
	*/
}

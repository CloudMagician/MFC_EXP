// Graphics.h: interface for the Graphics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHICS_H__39FB3FBD_C99D_4AA4_96AB_AEF4175283C5__INCLUDED_)
#define AFX_GRAPHICS_H__39FB3FBD_C99D_4AA4_96AB_AEF4175283C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Graphics  
{
public:
	void DDALine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	Graphics();
	virtual ~Graphics();

};

#endif // !defined(AFX_GRAPHICS_H__39FB3FBD_C99D_4AA4_96AB_AEF4175283C5__INCLUDED_)

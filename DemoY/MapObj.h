// MapObj.h: interface for the MapObj class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPOBJ_H__14EC475E_424A_4079_B8B3_2A373A88DC6A__INCLUDED_)
#define AFX_MAPOBJ_H__14EC475E_424A_4079_B8B3_2A373A88DC6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

class MapObj : public CObject
{
public:
	CArray<CPoint,CPoint> points;
	int type;
	COLORREF color;
public:
	MapObj();
	virtual ~MapObj();

};

#endif // !defined(AFX_MAPOBJ_H__14EC475E_424A_4079_B8B3_2A373A88DC6A__INCLUDED_)

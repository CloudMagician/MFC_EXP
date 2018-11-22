// DemoYView.h : interface of the CDemoYView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_)
#define AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//注释1部分：只绘制直线段
//注释2部分：绘制直线段及多边形
//注释3部分：重画
//注释4部分：颜色
//注释5部分：平移

//2+
#include <afxtempl.h>

class CDemoYView : public CView
{
protected: // create from serialization only
	CDemoYView();
	DECLARE_DYNCREATE(CDemoYView)

// Attributes
public:
	CDemoYDoc* GetDocument();
	//1
	CPoint m_StartPoint,m_EndPoint;//橡皮线的两个端点
	bool m_LButtonDown;//判断鼠标左键是否按下
	//2+
	CArray<CPoint,CPoint> pointList;//顶点列表
	CArray<CPoint,CPoint> pointCList;//填充顶点列表
	int type;//选择绘制的图元类型
	
	//3+
	CObArray objList;//图元列表
	
	//4+
	int r,g,b;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoYView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void PatternFill(CDC* pDC, int x, int y);
	void EdgeMarkFill(CDC* pDC);
	void DDALine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color);
	//5
	void Move(CPoint* point,int x, int y);
	virtual ~CDemoYView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoYView)
	afx_msg void OnLine();
	afx_msg void OnPolygon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSetwidth();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnIn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DemoYView.cpp
inline CDemoYDoc* CDemoYView::GetDocument()
   { return (CDemoYDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOYVIEW_H__F14AB2C7_B5B0_4B10_ABEB_8D3DE88AAB71__INCLUDED_)

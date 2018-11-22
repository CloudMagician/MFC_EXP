// DemoYView.cpp : implementation of the CDemoYView class
//

#include "stdafx.h"
#include "DemoY.h"

#include "DemoYDoc.h"
#include "DemoYView.h"
#include "math.h"
//2
#include "MapObj.h"

//4
#include "SetColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoYView

IMPLEMENT_DYNCREATE(CDemoYView, CView)

BEGIN_MESSAGE_MAP(CDemoYView, CView)
	//{{AFX_MSG_MAP(CDemoYView)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_POLYGON, OnPolygon)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_SETWIDTH, OnSetwidth)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_IN, OnIn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoYView construction/destruction

CDemoYView::CDemoYView()
{
	// TODO: add construction code here
	//1
	//设置鼠标左键初始没有按下
	m_LButtonDown = false;
	//2+
	//程序初始状态不绘制任何图元
	type = 0;
	
	//4+
	r=0;g=0;b=0;

}

CDemoYView::~CDemoYView()
{
	//3
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		delete obj;
	}
}

BOOL CDemoYView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView drawing

void CDemoYView::OnDraw(CDC* pDC)
{
	CDemoYDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*
	//初始绘图演示
	pDC->MoveTo(10,10);
	pDC->LineTo(100,100);
	pDC->LineTo(200,100);
	*/
	/*
	//获得设备环境对象
	pDC->LineTo(100,100);
	CDC* pDC2 = this->GetDC();
	pDC2->LineTo(100,200);
	CClientDC dc(this);
	dc.LineTo(100,300);
	dc.LineTo(300,300);
	*/
	/*
	//画笔画刷使用
	CPen pen;
	CPen* oldpen;
	pen.CreatePen(PS_SOLID, 2,RGB(0,0,255));
	oldpen = pDC->SelectObject(&pen);
	pDC->MoveTo(100,100);
	pDC->LineTo(100,200);
	pDC->SelectObject(oldpen);
	
	CClientDC dc(this);
	CPen pen2;
	pen2.CreatePen(PS_SOLID,8,RGB(255,0,0));
	CBrush brush;
	CBrush* oldbrush;
	brush.CreateSolidBrush(RGB(0,255,0));
	oldpen = dc.SelectObject(&pen2);
	oldbrush=dc.SelectObject(&brush);
	dc.Rectangle(200,200,400,400);
	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	*/
	/*
	//使用DDALine函数画线
	this->DDALine(pDC,100,100,300,200,RGB(255,0,0));
	*/
	/*
	//3
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		if (obj->type == 1){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2 = obj->points.GetAt(1);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		}
		else if (obj->type == 2){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2;
			for (int j=1;j<obj->points.GetSize();j++){
				p2 = obj->points.GetAt(j);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
				p1 = p2;
			}
			p2 = obj->points.GetAt(0);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		}
	}
	*/
	
	
	//4
	for (int i=0;i<objList.GetSize();i++){
		MapObj* obj = (MapObj*)objList.GetAt(i);
		if (obj->type == 1){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2 = obj->points.GetAt(1);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
		}
		else if (obj->type == 2){
			CPoint p1 = obj->points.GetAt(0);
			CPoint p2;
			for (int j=1;j<obj->points.GetSize();j++){
				p2 = obj->points.GetAt(j);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
				p1 = p2;
			}
			p2 = obj->points.GetAt(0);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView printing

BOOL CDemoYView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoYView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoYView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYView diagnostics

#ifdef _DEBUG
void CDemoYView::AssertValid() const
{
	CView::AssertValid();
}

void CDemoYView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDemoYDoc* CDemoYView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoYDoc)));
	return (CDemoYDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoYView message handlers

void CDemoYView::OnLine() 
{
	// TODO: Add your command handler code here
	//2
	type = 1;	
}

void CDemoYView::OnPolygon() 
{
	// TODO: Add your command handler code here
	//2
	type = 2;
}


void CDemoYView::OnIn() 
{
	// TODO: Add your command handler code here
	type = 3;
}

void CDemoYView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	//1
	this->SetCapture();//捕捉鼠标
	//设置开始点和终止点，此时为同一点
	m_StartPoint = point;
	m_EndPoint = point;
	m_LButtonDown = true;//设置鼠标左键按下
	*/

	//2
	if (type ==1 || type == 2){
		this->SetCapture();//捕捉鼠标
		//设置开始点和终止点，此时为同一点
		m_StartPoint = point;
		m_EndPoint = point;
		m_LButtonDown = true;//设置鼠标左键按下
		pointList.Add(point);
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CDemoYView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	//1
	if (m_LButtonDown){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果就是擦除了该线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		//绘制新的直线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;
	}
	*/
	//2
	if ((m_LButtonDown && type == 1) || (type == 2 && pointList.GetSize() != 0)){
		CDC* pDC = this->GetDC();//构造设备环境对象
		pDC->SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果就是擦除了该线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(0,0,0));
		//绘制新的直线段
		DDALine(pDC,m_StartPoint.x,m_StartPoint.y,point.x,point.y,RGB(0,0,0));
		//保存新的直线段终点
		m_EndPoint = point;
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CDemoYView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	//1
	ReleaseCapture();//释放鼠标
	m_LButtonDown = false;	
	*/
	/*
	//2
	if (type == 1){
		ReleaseCapture();//释放鼠标
		pointList.RemoveAll();
	}
	m_LButtonDown = false;	
	*/

	/*
	//3
	if (type == 1){
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 1;
		obj->points.Add(m_StartPoint);
		obj->points.Add(m_EndPoint);
		objList.Add(obj);
		pointList.RemoveAll();
	}
	m_LButtonDown = false;
	*/

	//4
	if (type == 1){
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 1;
		obj->points.Add(m_StartPoint);
		obj->points.Add(m_EndPoint);
		objList.Add(obj);
		pointList.RemoveAll();
		CDC* dc = this->GetDC();
		DDALine(dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y,RGB(r,g,b));
	}
	m_LButtonDown = false;
	
	CView::OnLButtonUp(nFlags, point);
}

void CDemoYView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	//2
	if (type == 2){
		ReleaseCapture();//释放鼠标
		CDC* dc = this->GetDC();
		CPoint p1 = pointList.GetAt(0);
		CPoint p2 = pointList.GetAt(pointList.GetSize()-1);
		DDALine(dc,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		pointList.RemoveAll();
	}
	*/
	
	/*
	//3
	if (type == 2){
		ReleaseCapture();//释放鼠标
		CDC* dc = this->GetDC();
		CPoint p1 = pointList.GetAt(0);
		CPoint p2 = pointList.GetAt(pointList.GetSize()-1);
		DDALine(dc,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));
		MapObj* obj = new MapObj();
		obj->type = 2;
		for (int i=0;i<pointList.GetSize();i++)
			obj->points.Add(pointList.GetAt(i));
		objList.Add(obj);
		pointList.RemoveAll();
	}
	*/
	
	//4
	if (type == 2){
		ReleaseCapture();//释放鼠标
		MapObj* obj = new MapObj();
		obj->type = 2;
		for (int i=0;i<pointList.GetSize();i++)
		{
			obj->points.Add(pointList.GetAt(i));
			pointCList.Add(pointList.GetAt(i));
		}
		objList.Add(obj);
		pointList.RemoveAll();
		CDC* pDC = this->GetDC();
		CPoint p1 = obj->points.GetAt(0);
		CPoint p2;
		for (int j=1;j<obj->points.GetSize();j++){
			p2 = obj->points.GetAt(j);
			DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
			p1 = p2;
		}
		p2 = obj->points.GetAt(0);
		DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(r,g,b));
	}

	if (type == 3){
		CDC* pDC = this->GetDC();
		EdgeMarkFill(pDC);
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CDemoYView::OnSetwidth() 
{
	// TODO: Add your command handler code here
	//4
	SetColor s;
	s.m_r = r;s.m_g = g;s.m_b = b;
	if (s.DoModal() == IDOK){
		r = s.m_r;g = s.m_g;b = s.m_b;
		this->Invalidate(true);
	}
}

void CDemoYView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	//5
	if (nChar == VK_LEFT){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,-1,0);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_RIGHT){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,1,0);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_UP){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,0,-1);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	if (nChar == VK_DOWN){
		for (int i=0;i<objList.GetSize();i++){
			MapObj* obj = (MapObj*)objList.GetAt(i);
			for (int j=0;j<obj->points.GetSize();j++){
				CPoint p = (CPoint)obj->points.GetAt(j);
				this->Move(&p,0,1);
				obj->points.SetAt(j,p);
			}
		}
		this->Invalidate(true);
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//5
void CDemoYView::Move(CPoint* point, int x, int y)
{
	point->x = point->x + x;
	point->y = point->y + y;
}

void CDemoYView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
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
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x+=dx;
		y+=dy;
	}
}

void CDemoYView::EdgeMarkFill(CDC* pDC)
{
	ReleaseCapture();//释放鼠标
	MapObj* obj = new MapObj();
	obj->type = 3;
	for (int j=0;j<pointCList.GetSize();j++)
	{
		obj->points.Add(pointCList.GetAt(j));
	}
	objList.Add(obj);
	pointCList.RemoveAll();

	CPoint p1 = obj->points.GetAt(0);
	CPoint p2;
	int xmax,xmin,ymax,ymin;
	xmax = p1.x;
	xmin = p1.x;
	ymax = p1.y;
	ymin = p1.y;

	for(int i = 1; i < obj->points.GetSize(); i++) {
		p1 = obj->points.GetAt(i);
		if (p1.x > xmax)
		{
			xmax = p1.x;
		} 
		else if (p1.x < xmin) 
		{
			xmin = p1.x;
		}
		if (p1.y > ymax)
		{
			ymax = p1.y;
		} 
		else if (p1.y < ymin) 
		{
			ymin = p1.y;
		}
	}
	
	bool MASK[2000][2000];
	int x,y,xs,ys,dxs,dys,Ixs;

	for (y = 0; y <= 2000; y++)
		for (x = 0; x <= 2000; x++)
			MASK[y][x] = false;


	for(int j = 0; j < obj->points.GetSize(); j++) 
	{
		p1 = obj->points.GetAt(j);
		if (j != obj->points.GetSize()-1)
		{
		p2 = obj->points.GetAt(j+1);
		}
		else
		{
		p2 = obj->points.GetAt(0);
		}
		xs = p1.x;
		dxs = (p2.x-p1.x)/(p2.y-p1.y);
		dys = abs(p2.y-p1.y)/(p2.y-p1.y);
		for (ys = p1.y;ys < p2.y; ys += dys)
		{
			Ixs = int(xs+0.5);
			MASK[ys][Ixs] = !MASK[ys][Ixs];
			xs = xs + dys*dxs;
		}
	}


		
	bool inside = false;
	bool flag = false;
	bool res = false;
	for(y = ymin; y <= ymax; y++)
	{
		inside = false;
        for(x = xmin; x <= xmax; x++)
        {
			res = MASK[y][x];
            if(res && !flag)
            {
                inside = !inside;
				flag = true;
            }
			else if (!res && flag) {
                flag = false;
            }
            if(inside && !res)
			{
            PatternFill(pDC,x,y);
            }
		}
	}
}

void CDemoYView::PatternFill(CDC *pDC, int x, int y)
{	
	int rec[10][32] = {	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
						0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
						0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
						0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
						0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
						0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
						0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
						0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
						0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	int a = x % 32;
	int b = y % 10;
	if(rec[b][a] == 1) pDC->SetPixel(x, y, RGB(255,0,0));
}

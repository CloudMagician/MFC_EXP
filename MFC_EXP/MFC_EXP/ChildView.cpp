
// ChildView.cpp: CChildView 类的实现
//

#include "stdafx.h"
#include "MFC_EXP.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	TypeEXP = 1;
	boolLButtonDown = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
//	ON_WM_PAINT()
	ON_COMMAND(ID_EXP1, &CChildView::OnExp1)
	ON_COMMAND(ID_EXP2, &CChildView::OnExp2)
	ON_COMMAND(ID_EXP3, &CChildView::OnExp3)
	ON_COMMAND(ID_EXP4, &CChildView::OnExp4)
	ON_COMMAND(ID_EXP5, &CChildView::OnExp5)
	ON_COMMAND(ID_EXP6, &CChildView::OnExp6)
	ON_COMMAND(ID_EXP7, &CChildView::OnExp7)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOUSEWHEEL()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONUP()
ON_WM_SIZE()
ON_WM_LBUTTONDBLCLK()
ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()



// CChildView 消息处理程序

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

//void CChildView::OnPaint() 
//{
//	CPaintDC dc(this); // 用于绘制的设备上下文
//	
//	// TODO: 在此处添加消息处理程序代码
//	
//	// 不要为绘制消息而调用 CWnd::OnPaint()
//}



void CChildView::OnExp1()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 1;
}


void CChildView::OnExp2()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 2;
}


void CChildView::OnExp3()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 3;
}


void CChildView::OnExp4()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 4;
}


void CChildView::OnExp5()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 5;
}


void CChildView::OnExp6()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 6;
}


void CChildView::OnExp7()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 7;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	this->SetCapture();	//捕捉鼠标

	switch (TypeEXP)
	{
	case 1:
	{
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
	}
		break;
	case 2:
	{
		startPoint = point;
		endPoint = point;
		pointList.Add(point);
		boolLButtonDown = true;
	}
		break;
	default:
		break;
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (boolLButtonDown)
	{
		switch (TypeEXP)
		{
		case 1:
		{
			CDC* pDC = this->GetDC();	//构造设备环境对象
			pDC->SetROP2(R2_NOT);		//设置绘图模式为R2_NOT
			pDC->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			pDC->Ellipse(startPoint.x, startPoint.y, point.x, point.y);
			endPoint = point;
		}
			break;
		case 2:
		{
			CDC* pDC = this->GetDC();	//构造设备环境对象
			pDC->SetROP2(R2_NOT);		//设置绘图模式为R2_NOT
			DDALine(pDC, startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			DDALine(pDC, startPoint.x, startPoint.y, point.x, point.y);
			endPoint = point;
		}
			break;
		default:
			break;
		}
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 1:
	{
		ReleaseCapture();	//释放鼠标
		boolLButtonDown = false;
		CDC* pDC = this->GetDC();
		pDC->Ellipse(startPoint.x, startPoint.y, point.x, point.y);
	}
		break;

	default:
		break;
	}

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 2:	//左键双击闭合多边形
	{
		if (boolLButtonDown)
		{
			ReleaseCapture();	//释放鼠标
			boolLButtonDown = false;
			CDC* pDC = this->GetDC();
			CPoint p1 = pointList.GetAt(0);
			CPoint p2;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p2 = pointList.GetAt(i);
				DDALine(pDC, p1.x, p1.y, p2.x, p2.y);
				p1 = p2;
			}
			p2 = pointList.GetAt(0);
			DDALine(pDC, p1.x, p1.y, p2.x, p2.y);
		}
	}
		break;

	default:
		break;
	}

	CWnd::OnLButtonDblClk(nFlags, point);
}


void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 2:	//右键双击填充多边形
	{
		if (!boolLButtonDown && pointList.GetSize()>0)
		{
			CDC* pDC = this->GetDC();
			CPoint p1,p2;
			//取矩阵最小扫描界
			int maxX, minX, maxY, minY;
			p1 = pointList.GetAt(0);
			maxX = p1.x;
			minX = p1.x;
			maxY = p1.y;
			minY = p1.y;
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i);
				if (p1.x > maxX) maxX = p1.x;
				if (p1.x < minX) minX = p1.x;
				if (p1.y > maxY) maxY = p1.y;
				if (p1.y < minY) minY = p1.y;
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY; y < maxY; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX; x < maxX; x++)
				{
					bder = (pDC->GetPixel(x, y) == RGB(0, 0, 0));
					if (bder && flag)
					{
						inside = !inside;
						flag = false;
					}
					else if (!bder && !flag)
					{
						flag = true;
					}
					if (inside && !bder) pDC->SetPixel(x, y, RGB(255, 0, 0));
				}
			}
			pointList.RemoveAll();
		}
	}
		break;

	default:
		break;
	}
	CWnd::OnRButtonDblClk(nFlags, point);
}


// DDA直线画法
void CChildView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2)
{
	// TODO: 在此处添加实现代码.
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e;
	dy /= e;
	x = x1;
	y = y1;
	for (int i = 1; i <= e; i++)
	{
		pDC->SetPixel((int)(x + 0.5), (int)(y + 0.5), RGB(0, 0, 0));
		x += dx;
		y += dy;
	}
}


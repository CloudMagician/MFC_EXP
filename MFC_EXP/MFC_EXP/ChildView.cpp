
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
	boolRButtonDown = false;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_COMMAND(ID_EXP1, &CChildView::OnExp1)
	ON_COMMAND(ID_EXP2, &CChildView::OnExp2)
	ON_COMMAND(ID_EXP3, &CChildView::OnExp3)
	ON_COMMAND(ID_EXP3_1, &CChildView::OnExp31)
	ON_COMMAND(ID_EXP3_2, &CChildView::OnExp32)
	ON_COMMAND(ID_EXP4, &CChildView::OnExp4)
	ON_COMMAND(ID_EXP5, &CChildView::OnExp5)
	ON_COMMAND(ID_EXP5_1, &CChildView::OnExp51)
	ON_COMMAND(ID_EXP5_2, &CChildView::OnExp52)
	ON_COMMAND(ID_EXP5_3, &CChildView::OnExp53)
	ON_COMMAND(ID_EXP5_4, &CChildView::OnExp54)
	ON_COMMAND(ID_EXP6, &CChildView::OnExp6)
	ON_COMMAND(ID_EXP7, &CChildView::OnExp7)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_TIMER()
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


void CChildView::OnExp1()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 1;
	ClearScreen();
}


void CChildView::OnExp2()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 2;
	ClearScreen();
}


void CChildView::OnExp3()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 3;
	ClearScreen();

	perspectiveProjection = false;
	perspectiveX = 350;
	perspectiveY = 250;
	perspectiveZ = 300;
	shifting = 250;
	mStep = 1.5;
	pStep = 1;
	rStep = 0.05;
	axes = 1;

	LBB3D = Point3D(-100, -100, -100);
	LBT3D = Point3D(-100, -100, +100);
	LFB3D = Point3D(-100, +100, -100);
	LFT3D = Point3D(-100, +100, +100);
	RBB3D = Point3D(+100, -100, -100);
	RBT3D = Point3D(+100, -100, +100);
	RFB3D = Point3D(+100, +100, -100);
	RFT3D = Point3D(+100, +100, +100);
}

void CChildView::OnExp31()
{
	// TODO: 在此添加命令处理程序代码
	OnExp3();
	perspectiveProjection = false;

	double L = 0.5;
	double Alpha = 45;
	Alpha *= 3.1415926 / 180;
	double c = cos(Alpha);
	double s = sin(Alpha);

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = L*c;
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = L*s;
	mPM[1][3] = 0;	
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;	
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 0;
	mPM[3][3] = 1;
	From3DTo2D();
	DrawCubic();
}


void CChildView::OnExp32()
{
	// TODO: 在此添加命令处理程序代码
	OnExp3();
	perspectiveProjection = true;

	mPM[0][0] = 1;
	mPM[0][1] = 0;
	mPM[0][2] = perspectiveX / (-perspectiveZ);
	mPM[0][3] = 0;
	mPM[1][0] = 0;
	mPM[1][1] = 1;
	mPM[1][2] = perspectiveY / (-perspectiveZ);
	mPM[1][3] = 0;
	mPM[2][0] = 0;
	mPM[2][1] = 0;
	mPM[2][2] = 0;
	mPM[2][3] = 0;
	mPM[3][0] = 0;
	mPM[3][1] = 0;
	mPM[3][2] = 1/ (-perspectiveZ);
	mPM[3][3] = 1;
	From3DTo2D();
	DrawCubic();
}


void CChildView::OnExp4()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 4;
	ClearScreen();
}


void CChildView::OnExp5()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 5;
	ClearScreen();

	typeEXP5 = 1;
	N = 3;
	K = 4;
	nPoints = 30;
}


void CChildView::OnExp51()
{
	// TODO: 在此添加命令处理程序代码
	OnExp5();
	typeEXP5 = 1;
}


void CChildView::OnExp52()
{
	// TODO: 在此添加命令处理程序代码
	OnExp5();
	typeEXP5 = 2;
}


void CChildView::OnExp53()
{
	// TODO: 在此添加命令处理程序代码
	OnExp5();
	typeEXP5 = 3;
}


void CChildView::OnExp54()
{
	// TODO: 在此添加命令处理程序代码
	OnExp5();
	typeEXP5 = 4;
	ControlPoint = new Point3D[(N + 1)*(N + 1)];	//控制网格初始化

	CDialogEXP5 mdialog;
	if (mdialog.DoModal() == IDOK)
	{
		ControlPoint[0] = Point3D(mdialog.x0, mdialog.y0, mdialog.z0);
		ControlPoint[1] = Point3D(mdialog.x1, mdialog.y1, mdialog.z1);
		ControlPoint[2] = Point3D(mdialog.x2, mdialog.y2, mdialog.z2);
		ControlPoint[3] = Point3D(mdialog.x3, mdialog.y3, mdialog.z3);
		ControlPoint[4] = Point3D(mdialog.x4, mdialog.y4, mdialog.z4);
		ControlPoint[5] = Point3D(mdialog.x5, mdialog.y5, mdialog.z5);
		ControlPoint[6] = Point3D(mdialog.x6, mdialog.y6, mdialog.z6);
		ControlPoint[7] = Point3D(mdialog.x7, mdialog.y7, mdialog.z7);
		ControlPoint[8] = Point3D(mdialog.x8, mdialog.y8, mdialog.z8);
		ControlPoint[9] = Point3D(mdialog.x9, mdialog.y9, mdialog.z9);
		ControlPoint[10] = Point3D(mdialog.x10, mdialog.y10, mdialog.z10);
		ControlPoint[11] = Point3D(mdialog.x11, mdialog.y11, mdialog.z11);
		ControlPoint[12] = Point3D(mdialog.x12, mdialog.y12, mdialog.z12);
		ControlPoint[13] = Point3D(mdialog.x13, mdialog.y13, mdialog.z13);
		ControlPoint[14] = Point3D(mdialog.x14, mdialog.y14, mdialog.z14);
		ControlPoint[15] = Point3D(mdialog.x15, mdialog.y15, mdialog.z15);
		DrawBezier3D();
	}
	else if (mdialog.DoModal() == IDCANCEL)
	{
		return;
	}
}


void CChildView::OnExp6()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 6;
	ClearScreen();

	N = 2;
	nPoints = 30;
	isMove = false;
}


void CChildView::OnExp7()
{
	// TODO: 在此添加命令处理程序代码
	TypeEXP = 7;
	ClearScreen();

	typeEXP7 = 1;
	N = 3;
	K = 4;
	nPoints = 30;
	pointList.RemoveAll();
	pointPrintList.RemoveAll();
}

void CChildView::ClearScreen()
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 3:
	{
		ClearScreen();
		if (nChar == VK_LEFT) {
			LBB3D.x -= mStep;
			LBT3D.x -= mStep;
			LFB3D.x -= mStep;
			LFT3D.x -= mStep;
			RBB3D.x -= mStep;
			RBT3D.x -= mStep;
			RFB3D.x -= mStep;
			RFT3D.x -= mStep;
		}
		if (nChar == VK_RIGHT) {
			LBB3D.x += mStep;
			LBT3D.x += mStep;
			LFB3D.x += mStep;
			LFT3D.x += mStep;
			RBB3D.x += mStep;
			RBT3D.x += mStep;
			RFB3D.x += mStep;
			RFT3D.x += mStep;
		}
		if (nChar == VK_UP) {
			LBB3D.y -= mStep;
			LBT3D.y -= mStep;
			LFB3D.y -= mStep;
			LFT3D.y -= mStep;
			RBB3D.y -= mStep;
			RBT3D.y -= mStep;
			RFB3D.y -= mStep;
			RFT3D.y -= mStep;
		}
		if (nChar == VK_DOWN) {
			LBB3D.y += mStep;
			LBT3D.y += mStep;
			LFB3D.y += mStep;
			LFT3D.y += mStep;
			RBB3D.y += mStep;
			RBT3D.y += mStep;
			RFB3D.y += mStep;
			RFT3D.y += mStep;
		}
		if (nChar == VK_SHIFT) {
			LBB3D.z += mStep;
			LBT3D.z += mStep;
			LFB3D.z += mStep;
			LFT3D.z += mStep;
			RBB3D.z += mStep;
			RBT3D.z += mStep;
			RFB3D.z += mStep;
			RFT3D.z += mStep;
		}
		if (nChar == VK_CONTROL) {
			LBB3D.z -= mStep;
			LBT3D.z -= mStep;
			LFB3D.z -= mStep;
			LFT3D.z -= mStep;
			RBB3D.z -= mStep;
			RBT3D.z -= mStep;
			RFB3D.z -= mStep;
			RFT3D.z -= mStep;
		}
		if (nChar == 'W') {
			double scale = 1.1;
			scale *= pStep;
			ProportionChange(scale);
		}		
		if (nChar == 'S') {
			double scale = 0.9;
			scale *= pStep;
			ProportionChange(scale);
		}
		if (nChar == 'A') {
			RotateChange(-rStep);
		}
		if (nChar == 'D') {
			RotateChange(rStep);
		}
		From3DTo2D();
		DrawCubic();
	}
	break;
	case 7:
	{
		ClearScreen();
		if (nChar == 'Q') {
			typeEXP7 = 1;
			pointList.RemoveAll();
			pointPrintList.RemoveAll();
		}
		if (nChar == 'W') {
			typeEXP7 = 2;
			pointPrintList.RemoveAll();
			Draw3ColorBSpline();
			CPoint tempP = pointList.GetAt(0);
			int xcenter = tempP.x;
			for (int i = 1; i < pointList.GetSize(); i++)
			{
				tempP = pointList.GetAt(i);
				tempP.x = xcenter * 2 - tempP.x;
				pointList.SetAt(i, tempP);
			}
			pointPrintList.RemoveAll();
			Draw3ColorBSpline();
		}
		if (nChar == 'E') {
			typeEXP7 = 3;
			// 变换矩阵
			double L = 0.5;
			double Alpha = 45;
			Alpha *= 3.1415926 / 180;
			double c = cos(Alpha);
			double s = sin(Alpha);
			mPM[0][0] = 1;
			mPM[0][1] = 0;
			mPM[0][2] = L * c;
			mPM[0][3] = 0;
			mPM[1][0] = 0;
			mPM[1][1] = 1;
			mPM[1][2] = L * s;
			mPM[1][3] = 0;
			mPM[2][0] = 0;
			mPM[2][1] = 0;
			mPM[2][2] = 0;
			mPM[2][3] = 0;
			mPM[3][0] = 0;
			mPM[3][1] = 0;
			mPM[3][2] = 0;
			mPM[3][3] = 1;
			// 坐标变换
			Point3D *curve = new Point3D[pointPrintList.GetSize()];
			CPoint tempP = pointList.GetAt(0);
			CClientDC pDC(this);
			CPen *oldpen;
			COLORREF color[3] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255) };
			int xcenter = tempP.x;
			for (int i = 0; i < 36; i++)
			{
				// 计算3D
				Alpha = i * 10 * 3.1415926 / 180;
				for (int j = 0; j < pointPrintList.GetSize(); j++)
				{
					tempP = pointPrintList.GetAt(j);
					curve[j].x = (tempP.x - xcenter) * cos(Alpha) + xcenter;
					curve[j].y = tempP.y;
					curve[j].z = (tempP.x - xcenter) * sin(Alpha);
				}
				// 计算2D
				From3DTo2D(curve, pointPrintList.GetSize());
				// 画图
				pDC.MoveTo(pointPrint3DList.GetAt(0));
				for (int j = 1; j < pointPrint3DList.GetSize(); j++)
				{
					CPen pen;
					pen.CreatePen(PS_SOLID, 2, color[j / (nPoints + 1) % 3]);
					oldpen = pDC.SelectObject(&pen);
					pDC.LineTo(pointPrint3DList.GetAt(j));
					pDC.SelectObject(oldpen);
				}
			}
		}
	}
	break;
	default:
		break;
	}

	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (TypeEXP)
	{
	case 1:
	{
		this->SetCapture();	//捕捉鼠标
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
	}
	break;
	case 2:
	{
		this->SetCapture();	//捕捉鼠标
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
		pointList.Add(point);
	}
	break;
	case 4:
	{
		this->SetCapture();	//捕捉鼠标
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
		pointList.Add(point);
	}
	break;
	case 5:
	{
		if (typeEXP5 != 4)
		{
			this->SetCapture();	//捕捉鼠标
			startPoint = point;
			endPoint = point;
			boolLButtonDown = true;
			pointList.Add(point);
		}
	}
	break;
	case 6:
	{
		this->SetCapture();	//捕捉鼠标
		startPoint = point;
		endPoint = point;
		boolLButtonDown = true;
		pointList.Add(point);
	}
	break;
	case 7:
	{
		switch (typeEXP7)
		{
		case 1:
		{
			this->SetCapture();	//捕捉鼠标
			startPoint = point;
			endPoint = point;
			boolLButtonDown = true;
			if (pointList.GetSize() == 0)
			{
				pointList.Add(point);
				pointList.Add(point);
			}
			pointList.Add(point);
		}
		break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
	CWnd::OnLButtonDown(nFlags, point);
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
	case 5:
	{
		if (pointList.GetSize() == N + 1 && typeEXP5 != 4)
		{
			CClientDC pDC(this);
			CPen pen, *oldpen;
			pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			oldpen = pDC.SelectObject(&pen);
			switch (typeEXP5)
			{
			case 1:
			{
				HermiteToPoints();
			}
			break;
			case 2:
			{
				BezierToPoints();
			}
			break;
			case 3:
			{
				BSplineToPoints();
			}
			break;
			default:
				break;
			}
			pDC.MoveTo(pointPrintList.GetAt(0));
			for (int i = 1; i < pointPrintList.GetSize(); i++)
			{
				pDC.LineTo(pointPrintList.GetAt(i));
			}
			pDC.SelectObject(oldpen);
			pointList.RemoveAll();
			pointPrintList.RemoveAll();
			boolLButtonDown = false;
			ReleaseCapture();	//释放鼠标
		}
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
				DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
				p1 = p2;
			}
			p2 = pointList.GetAt(0);
			DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
		}
	}
	break;
	case 3:	//左键双击选择旋转轴
	{
		CDialogEXP3_1 mdialog;
		if (mdialog.DoModal() == IDOK)
		{
			axes = mdialog.isXYZ;
		}
		else if (mdialog.DoModal() == IDCANCEL)
		{
			return;
		}
	}
	break;
	case 4:	//左键双击闭合多边形
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
				DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(255, 0, 0));
				p1 = p2;
			}
			p2 = pointList.GetAt(0);
			DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(255, 0, 0));
			//裁剪
			CutTop();
			CutLeft();
			CutBottom();
			CutRight();
			p1 = pointList.GetAt(0);
			for (int i = 1; i < pointList.GetSize(); i++) {
				p2 = pointList.GetAt(i);
				DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 255, 0));
				p1 = p2;
			}
			p2 = pointList.GetAt(0);
			DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 255, 0));
			pointList.RemoveAll();
			pointCutList.RemoveAll();
		}
	}
	break;
	case 5:	//左键双击改变控制点
	{
		if (typeEXP5 == 4)
		{
			CDialogEXP5 mdialog;
			if (mdialog.DoModal() == IDOK)
			{
				ControlPoint[0] = Point3D(mdialog.x0, mdialog.y0, mdialog.z0);
				ControlPoint[1] = Point3D(mdialog.x1, mdialog.y1, mdialog.z1);
				ControlPoint[2] = Point3D(mdialog.x2, mdialog.y2, mdialog.z2);
				ControlPoint[3] = Point3D(mdialog.x3, mdialog.y3, mdialog.z3);
				ControlPoint[4] = Point3D(mdialog.x4, mdialog.y4, mdialog.z4);
				ControlPoint[5] = Point3D(mdialog.x5, mdialog.y5, mdialog.z5);
				ControlPoint[6] = Point3D(mdialog.x6, mdialog.y6, mdialog.z6);
				ControlPoint[7] = Point3D(mdialog.x7, mdialog.y7, mdialog.z7);
				ControlPoint[8] = Point3D(mdialog.x8, mdialog.y8, mdialog.z8);
				ControlPoint[9] = Point3D(mdialog.x9, mdialog.y9, mdialog.z9);
				ControlPoint[10] = Point3D(mdialog.x10, mdialog.y10, mdialog.z10);
				ControlPoint[11] = Point3D(mdialog.x11, mdialog.y11, mdialog.z11);
				ControlPoint[12] = Point3D(mdialog.x12, mdialog.y12, mdialog.z12);
				ControlPoint[13] = Point3D(mdialog.x13, mdialog.y13, mdialog.z13);
				ControlPoint[14] = Point3D(mdialog.x14, mdialog.y14, mdialog.z14);
				ControlPoint[15] = Point3D(mdialog.x15, mdialog.y15, mdialog.z15);
				DrawBezier3D();
			}
			else if (mdialog.DoModal() == IDCANCEL)
			{
				return;
			}
		}
	}
	case 6:	//左键双击闭合多边形
	{
		if (boolLButtonDown)
		{
			ReleaseCapture();	//释放鼠标
			boolLButtonDown = false;
			DrawBezier2Ds();
			boolDirection = new bool[pointList.GetSize()];
			for (int i = 0; i < pointList.GetSize(); i++)
			{
				boolDirection[i] = true;
			}
		}
	}
	break;
	case 7:	//左键双击闭合多边形
	{
		if (boolLButtonDown)
		{
			ReleaseCapture();	//释放鼠标
			boolLButtonDown = false;
			pointList.Add(endPoint);
			pointList.Add(endPoint);
			Draw3ColorBSpline();
		}
	}
	break;
	default:
		break;
	}
	CWnd::OnLButtonDblClk(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 4:
	{
		startCutPoint = point;
		endCutPoint = point;
		boolRButtonDown = true;
	}
	default:
		break;
	}
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 4:
	{
		ReleaseCapture();	//释放鼠标
		boolRButtonDown = false;
		CDC* pDC = this->GetDC();
		DrawRect(pDC,startCutPoint,point);
	}
	break;
	default:
		break;
	}
	CWnd::OnRButtonUp(nFlags, point);
}

void CChildView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (TypeEXP)
	{
	case 2:	//右键双击填充多边形
	{
		if (!boolLButtonDown && pointList.GetSize() > 0)
		{
			CDC* pDC = this->GetDC();
			CPoint p1, p2, p3;
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
			//改变极值点
			p1 = pointList.GetAt(pointList.GetSize() - 1);
			p2 = pointList.GetAt(0);
			p3 = pointList.GetAt(1);
			if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
			{
				pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
			}
			for (int i = 1; i < pointList.GetSize(); i++) {
				p1 = pointList.GetAt(i - 1);
				p2 = pointList.GetAt(i);
				if (i != pointList.GetSize() - 1)
				{
					p3 = pointList.GetAt(i + 1);
				}
				else
				{
					p3 = pointList.GetAt(0);
				}
				if ((p1.y - p2.y)*(p2.y - p3.y) < 0)
				{
					pDC->SetPixel(p2.x, p2.y, RGB(255, 255, 255));
				}
			}
			//填充
			bool inside = false;	//是否在多边形中
			bool flag = true;		//是否需要改变
			bool bder = false;		//是否为边界值
			for (int y = minY - 1; y < maxY + 1; y++)
			{
				inside = false;
				flag = false;
				for (int x = minX - 1; x < maxX + 1; x++)
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
					if (inside && !bder) PatternFill(pDC, x, y);
				}
			}
			pointList.RemoveAll();
		}
	}
	break;
	case 3:	//右键双击编辑投影中心
	{
		if (perspectiveProjection)
		{
			CDialogEXP3_2 mdialog;
			INT_PTR nResponse = mdialog.DoModal();
			if (nResponse == IDOK)
			{
				perspectiveX = mdialog.mX;
				perspectiveY = mdialog.mY;
				perspectiveZ = mdialog.mZ;

				mPM[0][0] = 1;
				mPM[0][1] = 0;
				mPM[0][2] = perspectiveX / (-perspectiveZ);
				mPM[0][3] = 0;
				mPM[1][0] = 0;
				mPM[1][1] = 1;
				mPM[1][2] = perspectiveY / (-perspectiveZ);
				mPM[1][3] = 0;
				mPM[2][0] = 0;
				mPM[2][1] = 0;
				mPM[2][2] = 0;
				mPM[2][3] = 0;
				mPM[3][0] = 0;
				mPM[3][1] = 0;
				mPM[3][2] = 1 / (-perspectiveZ);
				mPM[3][3] = 1;
			}
			else if (nResponse == IDCANCEL)
			{
				return;
			}
		}
	}
	break;
	case 6:	//右键双击改变运动状态
	{
		isMove = !isMove;
		if (isMove)
		{
			SetTimer(6, 50, NULL);
		}
		else
		{
			KillTimer(6);
		}
	}
	break;
	default:
		break;
	}
	CWnd::OnRButtonDblClk(nFlags, point);
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (boolLButtonDown || boolRButtonDown)
	{
		CDC* pDC = this->GetDC();	//构造设备环境对象
		pDC->SetROP2(R2_NOT);		//设置绘图模式为R2_NOT

		switch (TypeEXP)
		{
		case 1:
		{
			pDC->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
			pDC->Ellipse(startPoint.x, startPoint.y, point.x, point.y);
			endPoint = point;
		}
		break;
		case 2:
		{
			DDALine(pDC, startPoint.x, startPoint.y, endPoint.x, endPoint.y, RGB(0, 0, 0));
			DDALine(pDC, startPoint.x, startPoint.y, point.x, point.y, RGB(0, 0, 0));
			endPoint = point;
		}
		break;
		case 4:
		{
			if (boolRButtonDown)
			{
				DrawRect(pDC, startCutPoint, endCutPoint);
				DrawRect(pDC, startCutPoint, point);
				endCutPoint = point;
			}
			else
			{
				DDALine(pDC, startPoint.x, startPoint.y, endPoint.x, endPoint.y, RGB(0, 0, 0));
				DDALine(pDC, startPoint.x, startPoint.y, point.x, point.y, RGB(0, 0, 0));
				endPoint = point;
			}
		}
		break;
		case 5:
		{
			pDC->MoveTo(startPoint);
			pDC->LineTo(endPoint);
			pDC->MoveTo(startPoint);
			pDC->LineTo(point);
			endPoint = point;
		}
		break;
		case 6:
		{
			DDALine(pDC, startPoint.x, startPoint.y, endPoint.x, endPoint.y, RGB(0, 0, 0));
			DDALine(pDC, startPoint.x, startPoint.y, point.x, point.y, RGB(0, 0, 0));
			endPoint = point;
		}
		break;
		case 7:
		{
			pDC->MoveTo(startPoint);
			pDC->LineTo(endPoint);
			pDC->MoveTo(startPoint);
			pDC->LineTo(point);
			endPoint = point;
		}
		break;
		default:
			break;
		}
	}

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent)
	{
	case 6:
	{
		ClearScreen();
		CRect rect;
		this->GetClientRect(rect);
		CPoint tempPoint;
		int temp;
		for (int i = 0; i < pointList.GetSize(); i++)
		{
			tempPoint = pointList.GetAt(i);
			if (i % 2 == 0)
			{
				// 偶数点
				if (boolDirection[i])
				{
					temp = tempPoint.y + 3 * i;
				}
				else
				{
					temp = tempPoint.y - 3 * i;
				}
				if (temp < rect.top)
				{
					temp = rect.top - temp;
					boolDirection[i] = !boolDirection[i];
				}
				else if (temp > rect.bottom)
				{
					temp = rect.bottom * 2 - temp;
					boolDirection[i] = !boolDirection[i];
				}
				tempPoint.y = temp;
			}
			else if (i % 2 == 1)
			{
				// 奇数点
				if (boolDirection[i])
				{
					temp = tempPoint.x + 3 * i;
				}
				else
				{
					temp = tempPoint.x - 3 * i;
				}
				if (temp < rect.left)
				{
					temp = rect.left - temp;
					boolDirection[i] = !boolDirection[i];
				}
				else if (temp > rect.right)
				{
					temp = rect.right * 2 - temp;
					boolDirection[i] = !boolDirection[i];
				}
				tempPoint.x = temp;
			}
			pointList.SetAt(i, tempPoint);
		}
		DrawBezier2Ds();
	}
	break;
	default:
		break;
	}
	CWnd::OnTimer(nIDEvent);
}


// DDA直线画法
void CChildView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
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
	pDC->MoveTo(x1, y1);
	for (int i = 1; i <= e; i++)
	{
		pDC->SetPixel((int)(x + 0.5), (int)(y + 0.5), color);
		x += dx;
		y += dy;
	}
}


// 填充学号
void CChildView::PatternFill(CDC *pDC, int x, int y)
{
	// TODO: 在此处添加实现代码.
	int rec[10][32] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,
					0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	int a = x % 64;
	int b = y % 20;
	if (rec[b/2][a/2] == 1) pDC->SetPixel(x, y, RGB(255, 0, 0));
}


// 画矩形
void CChildView::DrawRect(CDC* pDC, CPoint P1, CPoint P3)
{
	// TODO: 在此处添加实现代码.
	DDALine(pDC, P1.x, P1.y, P1.x, P3.y, RGB(0, 0, 0));
	DDALine(pDC, P1.x, P3.y, P3.x, P3.y, RGB(0, 0, 0));
	DDALine(pDC, P3.x, P3.y, P3.x, P1.y, RGB(0, 0, 0));
	DDALine(pDC, P3.x, P1.y, P1.x, P1.y, RGB(0, 0, 0));
}

void CChildView::DrawRect(CPoint P1, CPoint P2, CPoint P3, CPoint P4)
{
	// TODO: 在此处添加实现代码.
	CDC* pDC = this->GetDC();
	pDC->MoveTo(P1);
	pDC->LineTo(P2);
	pDC->LineTo(P3);
	pDC->LineTo(P4);
	pDC->LineTo(P1);
}


// 画立方体
void CChildView::DrawCubic()
{
	// TODO: 在此处添加实现代码.
	DrawRect(LBB2D, LBT2D, LFT2D, LFB2D);
	DrawRect(RBB2D, RBT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LBT2D, RBT2D, RBB2D);
	DrawRect(LFB2D, LFT2D, RFT2D, RFB2D);
	DrawRect(LBB2D, LFB2D, RFB2D, RBB2D);
	DrawRect(LBT2D, LFT2D, RFT2D, RBT2D);
}


// 坐标变换
void CChildView::From3DTo2D()
{
	// TODO: 在此处添加实现代码.
	double r;
	r = LBB3D.x * mPM[3][0] + LBB3D.y * mPM[3][1] + LBB3D.z * mPM[3][2] + mPM[3][3];
	LBB2D.x = long((LBB3D.x * mPM[0][0] + LBB3D.y * mPM[0][1] + LBB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LBB2D.y = long((LBB3D.x * mPM[1][0] + LBB3D.y * mPM[1][1] + LBB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LBT3D.x * mPM[3][0] + LBT3D.y * mPM[3][1] + LBT3D.z * mPM[3][2] + mPM[3][3];
	LBT2D.x = long((LBT3D.x * mPM[0][0] + LBT3D.y * mPM[0][1] + LBT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LBT2D.y = long((LBT3D.x * mPM[1][0] + LBT3D.y * mPM[1][1] + LBT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LFB3D.x * mPM[3][0] + LFB3D.y * mPM[3][1] + LFB3D.z * mPM[3][2] + mPM[3][3];
	LFB2D.x = long((LFB3D.x * mPM[0][0] + LFB3D.y * mPM[0][1] + LFB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LFB2D.y = long((LFB3D.x * mPM[1][0] + LFB3D.y * mPM[1][1] + LFB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = LFT3D.x * mPM[3][0] + LFT3D.y * mPM[3][1] + LFT3D.z * mPM[3][2] + mPM[3][3];
	LFT2D.x = long((LFT3D.x * mPM[0][0] + LFT3D.y * mPM[0][1] + LFT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	LFT2D.y = long((LFT3D.x * mPM[1][0] + LFT3D.y * mPM[1][1] + LFT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RBB3D.x * mPM[3][0] + RBB3D.y * mPM[3][1] + RBB3D.z * mPM[3][2] + mPM[3][3];
	RBB2D.x = long((RBB3D.x * mPM[0][0] + RBB3D.y * mPM[0][1] + RBB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RBB2D.y = long((RBB3D.x * mPM[1][0] + RBB3D.y * mPM[1][1] + RBB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RBT3D.x * mPM[3][0] + RBT3D.y * mPM[3][1] + RBT3D.z * mPM[3][2] + mPM[3][3];
	RBT2D.x = long((RBT3D.x * mPM[0][0] + RBT3D.y * mPM[0][1] + RBT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RBT2D.y = long((RBT3D.x * mPM[1][0] + RBT3D.y * mPM[1][1] + RBT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RFB3D.x * mPM[3][0] + RFB3D.y * mPM[3][1] + RFB3D.z * mPM[3][2] + mPM[3][3];
	RFB2D.x = long((RFB3D.x * mPM[0][0] + RFB3D.y * mPM[0][1] + RFB3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RFB2D.y = long((RFB3D.x * mPM[1][0] + RFB3D.y * mPM[1][1] + RFB3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
	r = RFT3D.x * mPM[3][0] + RFT3D.y * mPM[3][1] + RFT3D.z * mPM[3][2] + mPM[3][3];
	RFT2D.x = long((RFT3D.x * mPM[0][0] + RFT3D.y * mPM[0][1] + RFT3D.z * mPM[0][2] + mPM[0][4]) / r)+shifting;
	RFT2D.y = long((RFT3D.x * mPM[1][0] + RFT3D.y * mPM[1][1] + RFT3D.z * mPM[1][2] + mPM[1][4]) / r)+shifting;
}

// 比例变换
void CChildView::ProportionChange(double scale)
{
	// TODO: 在此处添加实现代码.
	LBB3D.x *= scale;
	LBT3D.x *= scale;
	LFB3D.x *= scale;
	LFT3D.x *= scale;
	RBB3D.x *= scale;
	RBT3D.x *= scale;
	RFB3D.x *= scale;
	RFT3D.x *= scale;

	LBB3D.y *= scale;
	LBT3D.y *= scale;
	LFB3D.y *= scale;
	LFT3D.y *= scale;
	RBB3D.y *= scale;
	RBT3D.y *= scale;
	RFB3D.y *= scale;
	RFT3D.y *= scale;

	LBB3D.z *= scale;
	LBT3D.z *= scale;
	LFB3D.z *= scale;
	LFT3D.z *= scale;
	RBB3D.z *= scale;
	RBT3D.z *= scale;
	RFB3D.z *= scale;
	RFT3D.z *= scale;
}


// 旋转变换
void CChildView::RotateChange(double angle)
{
	// TODO: 在此处添加实现代码.
	double c = cos(angle);
	double s = sin(angle);

	switch (axes)
	{
	case 1: 
	{
		double y = LBB3D.y;
		double z = LBB3D.z;
		LBB3D.y = y * c - z * s; LBB3D.z = y * s + z * c;
		y = LBT3D.y; z = LBT3D.z;
		LBT3D.y = y * c - z * s; LBT3D.z = y * s + z * c;
		y = LFB3D.y; z = LFB3D.z;
		LFB3D.y = y * c - z * s; LFB3D.z = y * s + z * c;
		y = LFT3D.y; z = LFT3D.z;
		LFT3D.y = y * c - z * s; LFT3D.z = y * s + z * c;
		y = RBB3D.y; z = RBB3D.z;
		RBB3D.y = y * c - z * s; RBB3D.z = y * s + z * c;
		y = RBT3D.y; z = RBT3D.z;
		RBT3D.y = y * c - z * s; RBT3D.z = y * s + z * c;
		y = RFB3D.y; z = RFB3D.z;
		RFB3D.y = y * c - z * s; RFB3D.z = y * s + z * c;
		y = RFT3D.y; z = RFT3D.z;
		RFT3D.y = y * c - z * s; RFT3D.z = y * s + z * c;
	}
	break;
	case 2: 
	{
		double z = LBB3D.z;
		double x = LBB3D.x;
		LBB3D.z = z * c - x * s; LBB3D.x = z * s + x * c;
		z = LBT3D.z; x = LBT3D.x;
		LBT3D.z = z * c - x * s; LBT3D.x = z * s + x * c;
		z = LFB3D.z; x = LFB3D.x;
		LFB3D.z = z * c - x * s; LFB3D.x = z * s + x * c;
		z = LFT3D.z; x = LFT3D.x;
		LFT3D.z = z * c - x * s; LFT3D.x = z * s + x * c;
		z = RBB3D.z; x = RBB3D.x;
		RBB3D.z = z * c - x * s; RBB3D.x = z * s + x * c;
		z = RBT3D.z; x = RBT3D.x;
		RBT3D.z = z * c - x * s; RBT3D.x = z * s + x * c;
		z = RFB3D.z; x = RFB3D.x;
		RFB3D.z = z * c - x * s; RFB3D.x = z * s + x * c;
		z = RFT3D.z; x = RFT3D.x;
		RFT3D.z = z * c - x * s; RFT3D.x = z * s + x * c;
	}
	break;
	case 3: 
	{
		double x = LBB3D.x;
		double y = LBB3D.y;
		LBB3D.x = x * c - y * s; LBB3D.y = x * s + y * c;
		x = LBT3D.x; y = LBT3D.y;
		LBT3D.x = x * c - y * s; LBT3D.y = x * s + y * c;
		x = LFB3D.x; y = LFB3D.y;
		LFB3D.x = x * c - y * s; LFB3D.y = x * s + y * c;
		x = LFT3D.x; y = LFT3D.y;
		LFT3D.x = x * c - y * s; LFT3D.y = x * s + y * c;
		x = RBB3D.x; y = RBB3D.y;
		RBB3D.x = x * c - y * s; RBB3D.y = x * s + y * c;
		x = RBT3D.x; y = RBT3D.y;
		RBT3D.x = x * c - y * s; RBT3D.y = x * s + y * c;
		x = RFB3D.x; y = RFB3D.y;
		RFB3D.x = x * c - y * s; RFB3D.y = x * s + y * c;
		x = RFT3D.x; y = RFT3D.y;
		RFT3D.x = x * c - y * s; RFT3D.y = x * s + y * c;
	}
	break;
	default:
		break;
	}
}


void CChildView::CutTop()
{
	// TODO: 在此处添加实现代码.
	CPoint F, P, S, I;
	int c1 = 0;
	int c2 = 0;
	pointCutList.RemoveAll();
	for (int i = 0; i < pointList.GetSize(); i++)
	{
		P = pointList.GetAt(i);
		if (i != 0)
		{
			c2 = (P.y < startCutPoint.y ? -1 : 1);
			if (c1 + c2 == 0) {
				I.y = startCutPoint.y;
				I.x = (P.x - S.x) * (I.y - S.y) / (P.y - S.y) + S.x;
				pointCutList.Add(I);
			}
		}
		else
		{
			F = P;
		}
		S = P;
		if (S.y < startCutPoint.y) 
		{
			c1 = -1;
		}
		else 
		{
			c1 = 1;
			pointCutList.Add(S);
		}
	}
	c2 = (F.y < startCutPoint.y ? -1 : 1);
	if (c1 + c2 == 0) {
		I.y = startCutPoint.y;
		I.x = (F.x - S.x) * (I.y - S.y) / (F.y - S.y) + S.x;
		pointCutList.Add(I);
	}
	pointList.RemoveAll();
	for (int i = 0; i < pointCutList.GetSize(); i++)
	{
		pointList.Add(pointCutList.GetAt(i));
	}
}


void CChildView::CutLeft()
{
	// TODO: 在此处添加实现代码.
	CPoint F, P, S, I;
	int c1 = 0;
	int c2 = 0;
	pointCutList.RemoveAll();
	for (int i = 0; i < pointList.GetSize(); i++)
	{
		P = pointList.GetAt(i);
		if (i != 0)
		{
			c2 = (P.x < startCutPoint.x ? -1 : 1);
			if (c1 + c2 == 0) {
				I.x = startCutPoint.x;
				I.y = (P.y - S.y) * (I.x - S.x) / (P.x - S.x) + S.y;
				pointCutList.Add(I);
			}
		}
		else
		{
			F = P;
		}
		S = P;
		if (S.x < startCutPoint.x)
		{
			c1 = -1;
		}
		else
		{
			c1 = 1;
			pointCutList.Add(S);
		}
	}
	c2 = (F.x < startCutPoint.x ? -1 : 1);
	if (c1 + c2 == 0) {
		I.x = startCutPoint.x;
		I.y = (F.y - S.y) * (I.x - S.x) / (F.x - S.x) + S.y;
		pointCutList.Add(I);
	}
	pointList.RemoveAll();
	for (int i = 0; i < pointCutList.GetSize(); i++)
	{
		pointList.Add(pointCutList.GetAt(i));
	}
}


void CChildView::CutBottom()
{
	// TODO: 在此处添加实现代码.
	CPoint F, P, S, I;
	int c1 = 0;
	int c2 = 0;
	pointCutList.RemoveAll();
	for (int i = 0; i < pointList.GetSize(); i++)
	{
		P = pointList.GetAt(i);
		if (i != 0)
		{
			c2 = (P.y > endCutPoint.y ? -1 : 1);
			if (c1 + c2 == 0) {
				I.y = endCutPoint.y;
				I.x = (P.x - S.x) * (I.y - S.y) / (P.y - S.y) + S.x;
				pointCutList.Add(I);
			}
		}
		else
		{
			F = P;
		}
		S = P;
		if (S.y > endCutPoint.y)
		{
			c1 = -1;
		}
		else
		{
			c1 = 1;
			pointCutList.Add(S);
		}
	}
	c2 = (F.y > endCutPoint.y ? -1 : 1);
	if (c1 + c2 == 0) {
		I.y = endCutPoint.y;
		I.x = (F.x - S.x) * (I.y - S.y) / (F.y - S.y) + S.x;
		pointCutList.Add(I);
	}
	pointList.RemoveAll();
	for (int i = 0; i < pointCutList.GetSize(); i++)
	{
		pointList.Add(pointCutList.GetAt(i));
	}
}


void CChildView::CutRight()
{
	// TODO: 在此处添加实现代码.
	CPoint F, P, S, I;
	int c1 = 0;
	int c2 = 0;
	pointCutList.RemoveAll();
	for (int i = 0; i < pointList.GetSize(); i++)
	{
		P = pointList.GetAt(i);
		if (i != 0)
		{
			c2 = (P.x > endCutPoint.x ? -1 : 1);
			if (c1 + c2 == 0) {
				I.x = endCutPoint.x;
				I.y = (P.y - S.y) * (I.x - S.x) / (P.x - S.x) + S.y;
				pointCutList.Add(I);
			}
		}
		else
		{
			F = P;
		}
		S = P;
		if (S.x > endCutPoint.x)
		{
			c1 = -1;
		}
		else
		{
			c1 = 1;
			pointCutList.Add(S);
		}
	}
	c2 = (F.x > endCutPoint.x ? -1 : 1);
	if (c1 + c2 == 0) {
		I.x = endCutPoint.x;
		I.y = (F.y - S.y) * (I.x - S.x) / (F.x - S.x) + S.y;
		pointCutList.Add(I);
	}
	pointList.RemoveAll();
	for (int i = 0; i < pointCutList.GetSize(); i++)
	{
		pointList.Add(pointCutList.GetAt(i));
	}
}


// 计算hermite曲线上各点坐标值
void CChildView::HermiteToPoints()
{
	// TODO: 在此处添加实现代码.
	double u = 0;
	double delt = 1 / (double)(nPoints);
	CPoint *P = new CPoint[N + 1];
	CPoint *V = new CPoint[N + 1];
	P[0] = pointList.GetAt(0);
	P[1] = pointList.GetAt(2);
	P[2] = pointList.GetAt(1) - pointList.GetAt(0);
	P[3] = pointList.GetAt(3) - pointList.GetAt(2);
	V[0].x = P[0].x * 2 - P[1].x * 2 + P[2].x + P[3].x;
	V[0].y = P[0].y * 2 - P[1].y * 2 + P[2].y + P[3].y;
	V[1].x = P[0].x * (-3) + P[1].x * 3 - P[2].x * 2 - P[3].x;
	V[1].y = P[0].y * (-3) + P[1].y * 3 - P[2].y * 2 - P[3].y;
	V[2] = P[2];
	V[3] = P[0];
	for (int i = 0; i < nPoints + 1; i++)
	{
		pointPrintList.Add(Hermite(V,u));
		u += delt;
	}
	delete[] P;
	delete[] V;
}


// 计算hermite曲线在参数为U的坐标值
CPoint CChildView::Hermite(CPoint V[], double u)
{
	// TODO: 在此处添加实现代码.
	CPoint pts;
	double *U = new double[N+1];
	U[N] = 1;
	pts = V[N];
	for (int i = N-1; i >= 0; i--)
	{
		U[i] = U[i + 1] * u;
		pts.x += long(V[i].x * U[i]);
		pts.y += long(V[i].y * U[i]);
	}
	delete[] U;
	return pts;
}


// 计算bezier曲线上各点坐标值
void CChildView::BezierToPoints()
{
	// TODO: 在此处添加实现代码.
	double u = 0;
	double delt = 1 / (double)(nPoints);
	for (int i = 0; i < nPoints + 1; i++)
	{
		pointPrintList.Add(Bezier(u));
		u += delt;
	}
}


// 采用几何作图法，计算bezier曲线在参数为U的坐标值
CPoint CChildView::Bezier(double u)
{
	// TODO: 在此处添加实现代码.
	CPoint *R = new CPoint[N + 1];
	CPoint *Q = new CPoint[N + 1];
	CPoint P;
	for (int i = 0; i < pointList.GetSize(); i++)
	{
		R[i] = pointList.GetAt(i);
	}
	for (int m = N; m > 0; m--)
	{
		for (int i = 0; i < m; i++)
		{
			Q[i].x = long(R[i].x + (R[i + 1].x - R[i].x)*u);
			Q[i].y = long(R[i].y + (R[i + 1].y - R[i].y)*u);
		}
		for (int i = 0; i < m; i++)
		{
			R[i] = Q[i];
		}
	}
	P = R[0];
	delete[] R;
	delete[] Q;
	return P;
}


// 计算bspline曲线上各点坐标值
void CChildView::BSplineToPoints()
{
	// TODO: 在此处添加实现代码.
	double *knots = new double[N + K + 1];
	double u;
	double delt;
	for (int j = 0; j < pointList.GetSize() - N; j++)
	{
		for (int i = 0; i < N + K + 1; i++)
		{
			knots[i] = i;
		}
		u = knots[K - 1];
		delt = (knots[N + 1] - knots[K - 1]) / (double)(nPoints);
		for (int i = 0; i < nPoints + 1; i++)
		{
			pointPrintList.Add(BSpline(knots, N + K + 1, u, j));
			u += delt;
		}
	}
}


// 计算B样条曲线在参数为U的坐标值
CPoint CChildView::BSpline(double knot[], int num, double u, int t)
{
	// TODO: 在此处添加实现代码.
	CPoint ret = CPoint(0, 0);
	double temp;
	for (int i = 0; i < N + 1; i++)
	{
		temp = Base(i, K, knot, num, u);
		ret.x += long(pointList.GetAt(i + t).x * temp);
		ret.y += long(pointList.GetAt(i + t).y * temp);
	}
	return ret;
}


// 计算B样条基函数
double CChildView::Base(int i, int k, double knot[], int num, double u)
{
	// TODO: 在此处添加实现代码.
	double temp1 = 0;
	double temp2 = 0;
	if (k == 1)
	{
		if (i == (num - 2))
		{
			if ((u >= knot[i]) && (u <= knot[i + 1])) return 1;
			else return 0;
		}
		else
		{
			if ((u >= knot[i]) && (u < knot[i + 1])) return 1;
			else return 0;
		}
	}
	else if (k > 1)
	{
		if (knot[i + k - 1] != knot[i])
		{
			temp1 = Base(i, k - 1, knot, num, u);
			temp1 = (u - knot[i])*temp1 / (knot[i + k - 1] - knot[i]);
		}
		if (knot[i + k] != knot[i + 1])
		{
			temp2 = Base(i + 1, k - 1, knot, num, u);
			temp2 = (knot[i + k] - u) * temp2 / (knot[i + k] - knot[i + 1]);
		}
		return temp1 + temp2;
	}
	return 0;
}


// 计算Bezier曲面上各点的坐标值
void CChildView::BezierToPoints2D(int n, int npoints, Point3D P[], Point3D points[])
{
	// TODO: 在此处添加实现代码.
	double *B = new double[(N + 1) * (N + 1)]
	{
		-1, 3, -3, 1,
		3, -6, 3, 0,
		-3, 3, 0, 0,
		1, 0, 0, 0,
	};
	double *BT = new double[(N + 1) * (N + 1)];
	Point3D *temp = new Point3D[(N + 1) * (N + 1)];
	Point3D *temp1 = new Point3D[(N + 1) * (N + 1)];
	Point3D *temp2 = new Point3D[N + 1];
	double *uvector = new double[N + 1];
	double *wvector = new double[N + 1];
	double u, w, du, dw;
	du = dw = 1 / double(npoints);
	memcpy(BT, B, (N + 1) * (N + 1) * sizeof(double));
	Transpose(BT, N + 1);
	Product(B, P, temp, N + 1, N + 1, N + 1);
	Product(temp, BT, temp1, N + 1, N + 1, N + 1);
	u = 0;
	for (int i = 0; i < npoints + 1; i++, u += du)
	{
		uvector[N] = 1;
		for (int k = N-1; k >= 0; k--)
		{
			uvector[k] = u * uvector[k + 1];
		}
		Product(uvector, temp1, temp2, 1, N + 1, N + 1);
		w = 0;
		for (int j = 0; j < npoints + 1; j++, w += dw)
		{
			wvector[N] = 1;
			for (int l = N - 1; l >= 0; l--)
			{
				wvector[l] = w * wvector[l + 1];
			}
			Product(temp2, wvector, &points[i*(npoints+1)+j], 1, N + 1, 1);
		}
	}
}


// 矩阵乘积运算
template <typename T1, typename T2, typename T3> void 
CChildView::Product(T1 a[], T2 b[], T3 c[], int ah, int s, int bw)
{
	// TODO: 在此处添加实现代码.
	for (int i = 0; i < ah; i++)
	{
		for (int j = 0; j < bw; j++)
		{
			c[i * bw + j] = 0;
			for (int k = 0; k < s; k++)
			{
				c[i * bw + j] += a[i * s + k] * b[k * bw + j];
			}
		}
	}
}


// 矩阵转置运算
template <typename T> void CChildView::Transpose(T a[], int n)
{
	// TODO: 在此处添加实现代码.
	T temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = a[i * n + j];
			a[i * n + j] = a[j * n + i];
			a[j * n + i] = temp;
		}
	}
}


// 世界坐标->观察坐标->屏幕坐标
CPoint CChildView::WorldToView(Point3D pt, Point3D VLoca, double Vz)
{
	// TODO: 在此处添加实现代码.
	double s = 8;
	CPoint qt;
	double aa, bb, cc, xw, yw, zw, xe, ye, ze, uu, vv;
	xw = pt.x; yw = pt.y; zw = pt.z;
	aa = VLoca.x; bb = VLoca.y; cc = VLoca.z;
	uu = sqrt(aa * aa + bb * bb + cc * cc);
	vv = sqrt(aa * aa + bb * bb);
	if (!uu)
	{
		xe = xw; ye = yw; ze = zw;
	}
	else if (!vv)
	{
		xe = xw; ye = yw; ze = zw + cc;
	}
	else
	{
		xe = aa * yw / vv - bb * xw / vv;
		ye = vv * zw / uu - aa * cc * xw / (uu * vv) - bb * cc * yw / (uu * vv);
		ze = - aa * xw / uu - bb * yw / uu - cc * zw / uu + uu;
	}
	qt.x = long(dtxs(s * xe * Vz / ze));
	qt.y = long(dtys(s * ye * Vz / ze));
	return qt;
}


// X轴上观察坐标->屏幕坐标
long CChildView::dtxs(double x)
{
	// TODO: 在此处添加实现代码.
	CRect rect;
	GetClientRect(&rect);
	return (long(rect.right / 2 + x));
}


// Y轴上观察坐标->屏幕坐标
long CChildView::dtys(double y)
{
	// TODO: 在此处添加实现代码.
	CRect rect;
	GetClientRect(&rect);
	return (long(rect.bottom / 2 - y));
}


// 画曲面
void CChildView::DrawBezier3D()
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	Point3D v = Point3D(400,400,400); //给定观察点
	double vz = 200; //给定投影平面到原点的距离
	//逼近曲面的网格点坐标
	Point3D *MeshPoint = new Point3D[(nPoints + 1) * (nPoints + 1)];
	//曲面网格点在屏幕上的坐标
	CPoint *PlaneMeshPoint = new CPoint[(nPoints + 1) * (nPoints + 1)];
	//控制网格点在屏幕上的坐标
	CPoint *PlaneCtrlPoint = new CPoint[(nPoints + 1) * (nPoints + 1)];

	BezierToPoints2D(N,nPoints,ControlPoint,MeshPoint);
	
	CPen pen, *oldpen;
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	oldpen = dc.SelectObject(&pen);

	for (int i = 0; i < (N + 1) * (N + 1); i++)
	{
		PlaneCtrlPoint[i] = WorldToView(ControlPoint[i], v, vz);
	}
	for (int i = 0; i < N + 1; i++)
	{
		dc.Polyline(&PlaneCtrlPoint[i * (N + 1)], N + 1);
	}
	Transpose(PlaneCtrlPoint, N + 1);
	for (int i = 0; i < N + 1; i++)
	{
		dc.Polyline(&PlaneCtrlPoint[i * (N + 1)], N + 1);
	}
	Transpose(PlaneCtrlPoint, N + 1);
	dc.SelectObject(oldpen);
	for (int i = 0; i < (nPoints + 1) * (nPoints + 1); i++)
	{
		PlaneMeshPoint[i] = WorldToView(MeshPoint[i], v, vz);
	}
	for (int i = 0; i < nPoints + 1; i++)
	{
		dc.Polyline(&PlaneMeshPoint[i * (nPoints + 1)], nPoints + 1);
	}
	Transpose(PlaneMeshPoint, nPoints + 1);
	for (int i = 0; i < nPoints + 1; i++)
	{
		dc.Polyline(&PlaneMeshPoint[i * (nPoints + 1)], nPoints + 1);
	}
	Transpose(PlaneMeshPoint, nPoints + 1);
}


// 多段2次Bezier曲线
void CChildView::Bezier2Ds(CPoint A, CPoint B, CPoint C)
{
	// TODO: 在此处添加实现代码.
	CPoint *R = new CPoint[N + 1];
	CPoint *Q = new CPoint[N + 1];
	CPoint P;
	double u = 0;
	double delt = 1 / (double)(nPoints);
	for (int i = 0; i < nPoints + 1; i++)
	{
		R[0] = A;
		R[1] = B;
		R[2] = C;
		for (int m = N; m > 0; m--)
		{
			for (int i = 0; i < m; i++)
			{
				Q[i].x = long(R[i].x + (R[i + 1].x - R[i].x)*u);
				Q[i].y = long(R[i].y + (R[i + 1].y - R[i].y)*u);
			}
			for (int i = 0; i < m; i++)
			{
				R[i] = Q[i];
			}
		}
		P = R[0];
		pointPrintList.Add(P);
		u += delt;
	}
	delete[] R;
	delete[] Q;
}


// 画内切曲线
void CChildView::DrawBezier2Ds()
{
	// TODO: 在此处添加实现代码.
	CDC* pDC = this->GetDC();
	CPoint p1 = pointList.GetAt(0);
	CPoint p2 = pointList.GetAt(1);
	CPoint p3;
	CPoint p4 = CPoint((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
	CPoint p5;
	for (int i = 1; i < pointList.GetSize() - 1; i++) {
		p2 = pointList.GetAt(i);
		p3 = pointList.GetAt(i + 1);
		p5 = CPoint((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
		DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
		Bezier2Ds(p4, p2, p5);
		p1 = p2;
		p4 = p5;
	}
	p2 = pointList.GetAt(pointList.GetSize() - 1);
	p3 = pointList.GetAt(0);
	p5 = CPoint((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
	DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
	Bezier2Ds(p4, p2, p5);
	p1 = p2;
	p4 = p5;
	p2 = pointList.GetAt(0);
	p3 = pointList.GetAt(1);
	p5 = CPoint((p2.x + p3.x) / 2, (p2.y + p3.y) / 2);
	DDALine(pDC, p1.x, p1.y, p2.x, p2.y, RGB(0, 0, 0));
	Bezier2Ds(p4, p2, p5);
	// 画曲线
	CPen pen, *oldpen;
	pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	oldpen = pDC->SelectObject(&pen);
	pDC->MoveTo(pointPrintList.GetAt(0));
	for (int i = 1; i < pointPrintList.GetSize(); i++)
	{
		pDC->LineTo(pointPrintList.GetAt(i));
	}
	pDC->SelectObject(oldpen);
	pointPrintList.RemoveAll();
}

// 画出三色B样条曲线
void CChildView::Draw3ColorBSpline()
{
	// TODO: 在此处添加实现代码.
	CClientDC pDC(this);
	CPen *oldpen;
	COLORREF color[3] = { RGB(255,0,0), RGB(0,255,0), RGB(0,0,255) };
	BSplineToPoints();
	pDC.MoveTo(pointPrintList.GetAt(0));
	for (int i = 1; i < pointPrintList.GetSize(); i++)
	{
		CPen pen;
		pen.CreatePen(PS_SOLID, 3, color[i / (nPoints + 1) % 3]);
		oldpen = pDC.SelectObject(&pen);
		pDC.LineTo(pointPrintList.GetAt(i));
		pDC.SelectObject(oldpen);
	}
}


// 坐标变换
void CChildView::From3DTo2D(Point3D* c, int n)
{
	// TODO: 在此处添加实现代码.
	double r;
	CPoint tempP;
	pointPrint3DList.RemoveAll();
	for (int i = 0; i < n; i++)
	{
		r = c[i].x * mPM[3][0] + c[i].y * mPM[3][1] + c[i].z * mPM[3][2] + mPM[3][3];
		tempP.x = long((c[i].x * mPM[0][0] + c[i].y * mPM[0][1] + c[i].z * mPM[0][2] + mPM[0][4]) / r);
		tempP.y = long((c[i].x * mPM[1][0] + c[i].y * mPM[1][1] + c[i].z * mPM[1][2] + mPM[1][4]) / r);
		pointPrint3DList.Add(tempP);
	}
}

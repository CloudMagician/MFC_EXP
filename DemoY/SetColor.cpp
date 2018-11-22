// SetColor.cpp : implementation file
//

#include "stdafx.h"
#include "DemoY.h"
#include "SetColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SetColor dialog


SetColor::SetColor(CWnd* pParent /*=NULL*/)
	: CDialog(SetColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(SetColor)
	m_g = 0;
	m_b = 0;
	m_r = 0;
	//}}AFX_DATA_INIT
}


void SetColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SetColor)
	DDX_Text(pDX, IDC_G, m_g);
	DDX_Text(pDX, IDC_B, m_b);
	DDX_Text(pDX, IDC_R, m_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SetColor, CDialog)
	//{{AFX_MSG_MAP(SetColor)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SetColor message handlers

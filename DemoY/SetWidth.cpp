// SetWidth.cpp : implementation file
//

#include "stdafx.h"
#include "DemoY.h"
#include "SetWidth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SetWidth dialog


SetWidth::SetWidth(CWnd* pParent /*=NULL*/)
	: CDialog(SetWidth::IDD, pParent)
{
	//{{AFX_DATA_INIT(SetWidth)
	m_width = 0;
	//}}AFX_DATA_INIT
}


void SetWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SetWidth)
	DDX_Text(pDX, IDC_EDIT1, m_width);
	DDV_MinMaxInt(pDX, m_width, 1, 8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SetWidth, CDialog)
	//{{AFX_MSG_MAP(SetWidth)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SetWidth message handlers

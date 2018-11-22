// DemoYDoc.cpp : implementation of the CDemoYDoc class
//

#include "stdafx.h"
#include "DemoY.h"

#include "DemoYDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoYDoc

IMPLEMENT_DYNCREATE(CDemoYDoc, CDocument)

BEGIN_MESSAGE_MAP(CDemoYDoc, CDocument)
	//{{AFX_MSG_MAP(CDemoYDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoYDoc construction/destruction

CDemoYDoc::CDemoYDoc()
{
	// TODO: add one-time construction code here

}

CDemoYDoc::~CDemoYDoc()
{
}

BOOL CDemoYDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDemoYDoc serialization

void CDemoYDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDemoYDoc diagnostics

#ifdef _DEBUG
void CDemoYDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDemoYDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoYDoc commands

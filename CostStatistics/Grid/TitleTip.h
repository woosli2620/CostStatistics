
#if !defined(AFX_TITLETIP_H__C7165DA1_187F_11D1_992F_895E185F9C72__INCLUDED_)
#define AFX_TITLETIP_H__C7165DA1_187F_11D1_992F_895E185F9C72__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define TITLETIP_CLASSNAME _T("ZTitleTip")

/////////////////////////////////////////////////////////////////////////////
// CTitleTip window

class CTitleTip : public CWnd
{
// Construction
public:
	CTitleTip();
	virtual ~CTitleTip();
	virtual BOOL Create( CWnd *pParentWnd);

// Attributes
public:
    void SetParentWnd(CWnd* pParentWnd)  { m_pParentWnd = pParentWnd; }
    CWnd* GetParentWnd()                 { return m_pParentWnd;       }

// Operations
public:
	void Show(CRect rectTitle, LPCTSTR lpszTitleText, 
              int xoffset = 0, LPRECT lpHoverRect = NULL, 
              const LOGFONT* lpLogFont = NULL,
              COLORREF crTextClr = CLR_DEFAULT, COLORREF crBackClr = CLR_DEFAULT, LPCTSTR lpszOldTitleText = NULL);
    void Hide();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTitleTip)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL
private:
	void  DrawMyText(CString str, CRect& rc,CDC *pDC,bool bOnlyCalu);
// Implementation
protected:
	CWnd  *m_pParentWnd;
	CRect  m_rectTitle;
    CRect  m_rectHover;
    DWORD  m_dwLastLButtonDown;
    DWORD  m_dwDblClickMsecs;
    BOOL   m_bCreated;

	// Generated message map functions
protected:
	//{{AFX_MSG(CTitleTip)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TITLETIP_H__C7165DA1_187F_11D1_992F_895E185F9C72__INCLUDED_)
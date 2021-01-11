#if !defined(AFX_WHITE_H__44C1D136_4875_415C_A81E_B2B5CAB5832D__INCLUDED_)
#define AFX_WHITE_H__44C1D136_4875_415C_A81E_B2B5CAB5832D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WHITE.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWHITE dialog

class CWHITE : public CDialog
{
// Construction
public:
	CWHITE(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWHITE)
	enum { IDD = IDD_DIALOG_WHITE };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWHITE)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWHITE)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonDelete2();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHITE_H__44C1D136_4875_415C_A81E_B2B5CAB5832D__INCLUDED_)

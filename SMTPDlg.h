// SMTPDlg.h : header file
//
#include "POP3.h"
#if !defined(AFX_SMTPDLG_H__4A3A0BE6_0227_4B33_BDB4_FE528F7D38E5__INCLUDED_)
#define AFX_SMTPDLG_H__4A3A0BE6_0227_4B33_BDB4_FE528F7D38E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSMTPDlg dialog
extern CString strMail;
extern CStringArray black_list;
extern CStringArray white_list;
extern CString USER;

class CSMTPDlg : public CDialog
{
// Construction
public:
	CSMTPDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSMTPDlg)
	enum { IDD = IDD_SMTP_DIALOG };
	CListCtrl	m_listmail;
	BOOL	m_html;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSMTPDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSMTPDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnCheck1();
	afx_msg void OnAddfile();
	afx_msg void OnDelete();
	afx_msg void OnGetemail();
	afx_msg void OnLogin();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBlack();
	afx_msg void OnWhite();
	afx_msg void OnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	vector<string> files;
	CComboBox* pCombo;
	POP3 pop3;				// pop¶ÔÏñ
	
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SMTPDLG_H__4A3A0BE6_0227_4B33_BDB4_FE528F7D38E5__INCLUDED_)

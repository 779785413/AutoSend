
// AUTOSENDDlg.h: 头文件
//
#include "CMy_ICON.h"
#pragma once


// CAUTOSENDDlg 对话框
class CAUTOSENDDlg : public CDialogEx
{
// 构造
public:
	CAUTOSENDDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AUTOSEND_DIALOG };
#endif
	CMy_ICON my_icon;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual void OnOK();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedButton3();
	CString FileSelect;
	HWND CatchHWnd;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnEnChangeEdit1();
};

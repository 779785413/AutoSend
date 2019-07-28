#include "pch.h"
#include "CMy_ICON.h"
#include <WinUser.h>
#include "AUTOSENDDlg.h"
#include "AUTOSEND.h"
BEGIN_MESSAGE_MAP(CMy_ICON, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


void CMy_ICON::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();

	//IDC_CURSOR1是靶心光标   IDI_ICON1是无靶心图标   IDI_ICON2 是有靶心图标  
	HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE (IDC_CURSOR1));

	::SetCursor(hc);

	HICON hicon1 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2));  this->SetIcon(hicon1);
	CStatic::OnLButtonDown(nFlags, point);
}


void CMy_ICON::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();

	HICON hicon2 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));  this->SetIcon(hicon2);
	CStatic::OnLButtonUp(nFlags, point);
}

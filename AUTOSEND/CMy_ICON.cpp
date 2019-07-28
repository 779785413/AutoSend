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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();

	//IDC_CURSOR1�ǰ��Ĺ��   IDI_ICON1���ް���ͼ��   IDI_ICON2 ���а���ͼ��  
	HCURSOR hc = LoadCursor(AfxGetApp()->m_hInstance, MAKEINTRESOURCE (IDC_CURSOR1));

	::SetCursor(hc);

	HICON hicon1 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON2));  this->SetIcon(hicon1);
	CStatic::OnLButtonDown(nFlags, point);
}


void CMy_ICON::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ReleaseCapture();

	HICON hicon2 = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON1));  this->SetIcon(hicon2);
	CStatic::OnLButtonUp(nFlags, point);
}

#include "pch.h"
#include "ControlsTest.h"
#include "ColorStaticDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(ColorStaticDlg, CDialogEx)

ColorStaticDlg::ColorStaticDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ColorStaticDlg::~ColorStaticDlg()
{
}

void ColorStaticDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_COLOR, m_StcColor);
}

BOOL ColorStaticDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	this->m_StcColor.SetForeColor(RGB(255, 0, 0));
	this->m_StcColor.SetBackColor(RGB(255, 255, 0));
	this->m_StcColor.SetFormat(DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	this->m_StcColor.SetFontEx(this->GetFont());
	this->m_StcColor.SetWindowText(_T("ColorStatic コントロール"));

	return TRUE;
}

BEGIN_MESSAGE_MAP(ColorStaticDlg, CDialogEx)
END_MESSAGE_MAP()

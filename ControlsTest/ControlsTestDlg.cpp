#include "pch.h"
#include "framework.h"
#include "ControlsTest.h"
#include "ControlsTestDlg.h"
#include "afxdialogex.h"
#include "ColorStaticDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CControlsTestDlg::CControlsTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTROLSTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlsTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CControlsTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}

BEGIN_MESSAGE_MAP(CControlsTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CControlsTestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

void CControlsTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CControlsTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CControlsTestDlg::OnBnClickedButton1()
{
	ColorStaticDlg dlg;
	dlg.DoModal();
}

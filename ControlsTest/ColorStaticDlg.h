#pragma once
#include "ColorStatic.h"

class ColorStaticDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ColorStaticDlg)

public:
	ColorStaticDlg(CWnd* pParent = nullptr);
	virtual ~ColorStaticDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

	ColorStatic m_StcColor;
};

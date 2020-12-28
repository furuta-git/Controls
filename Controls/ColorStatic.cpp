#include "ColorStatic.h"

// コンストラクタ
ColorStatic::ColorStatic()
	: m_foreColor(RGB(0, 0, 0))
	, m_backColor(::GetSysColor(COLOR_BTNFACE))
	, m_uiFormat(DT_LEFT | DT_SINGLELINE | DT_TOP)
{
}

// デストラクタ
ColorStatic::~ColorStatic()
{
}

// MFC標準PreSubclassWindow
void ColorStatic::PreSubclassWindow()
{

	__super::PreSubclassWindow();
}

// MFC標準PreTranslateMessage
BOOL ColorStatic::PreTranslateMessage(MSG* pMsg)
{

	return __super::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(ColorStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// MFC標準OnPaint
void ColorStatic::OnPaint()
{
	CPaintDC dc(this);

	if (this->GetSafeHwnd())
	{
		// デバイスコンテキスト取得
		CDC* pDC = this->GetDC();
		// 矩形
		CRect rc;
		// 矩形取得
		this->GetClientRect(rc);
		// 描画処理実施
		this->DrawExecute(pDC, rc);
	}
}

// 文字色設定
void ColorStatic::SetForeColor(COLORREF color)
{
	this->m_foreColor = color;
	this->Invalidate(FALSE);
}

// 文字色取得
COLORREF ColorStatic::GetForeColor()
{
	return this->m_foreColor;
}

// 背景色設定
void ColorStatic::SetBackColor(COLORREF color)
{
	this->m_backColor = color;
	this->Invalidate(FALSE);
}

// 背景色取得
COLORREF ColorStatic::GetBackColor()
{
	return this->m_backColor;
}

// フォーマット設定
void ColorStatic::SetFormat(UINT format)
{
	this->m_uiFormat = format;
	this->Invalidate(FALSE);
}

// フォーマット取得
UINT ColorStatic::GetFormat()
{
	return this->m_uiFormat;
}

// フォント設定
void ColorStatic::SetFontEx(CFont* pFont)
{
	if (pFont != nullptr)
	{
		pFont->GetLogFont(&this->m_logfont);
	}
}

// 描画処理
void ColorStatic::DrawObject(CDC* pDC, CRect& rc)
{
	CString text = (LPTSTR)nullptr;
	CFont* pFont = new CFont();

	this->GetWindowText(text);
	pFont->CreateFontIndirect(&this->m_logfont);

	this->DrawRect(pDC, rc, this->m_backColor);
	this->DrawString(pDC, rc, text, this->m_foreColor, this->m_uiFormat, pFont);

	pFont->DeleteObject();
	delete pFont;
}

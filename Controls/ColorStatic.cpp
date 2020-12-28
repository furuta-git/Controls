#include "ColorStatic.h"

// �R���X�g���N�^
ColorStatic::ColorStatic()
	: m_foreColor(RGB(0, 0, 0))
	, m_backColor(::GetSysColor(COLOR_BTNFACE))
	, m_uiFormat(DT_LEFT | DT_SINGLELINE | DT_TOP)
{
}

// �f�X�g���N�^
ColorStatic::~ColorStatic()
{
}

// MFC�W��PreSubclassWindow
void ColorStatic::PreSubclassWindow()
{

	__super::PreSubclassWindow();
}

// MFC�W��PreTranslateMessage
BOOL ColorStatic::PreTranslateMessage(MSG* pMsg)
{

	return __super::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(ColorStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// MFC�W��OnPaint
void ColorStatic::OnPaint()
{
	CPaintDC dc(this);

	if (this->GetSafeHwnd())
	{
		// �f�o�C�X�R���e�L�X�g�擾
		CDC* pDC = this->GetDC();
		// ��`
		CRect rc;
		// ��`�擾
		this->GetClientRect(rc);
		// �`�揈�����{
		this->DrawExecute(pDC, rc);
	}
}

// �����F�ݒ�
void ColorStatic::SetForeColor(COLORREF color)
{
	this->m_foreColor = color;
	this->Invalidate(FALSE);
}

// �����F�擾
COLORREF ColorStatic::GetForeColor()
{
	return this->m_foreColor;
}

// �w�i�F�ݒ�
void ColorStatic::SetBackColor(COLORREF color)
{
	this->m_backColor = color;
	this->Invalidate(FALSE);
}

// �w�i�F�擾
COLORREF ColorStatic::GetBackColor()
{
	return this->m_backColor;
}

// �t�H�[�}�b�g�ݒ�
void ColorStatic::SetFormat(UINT format)
{
	this->m_uiFormat = format;
	this->Invalidate(FALSE);
}

// �t�H�[�}�b�g�擾
UINT ColorStatic::GetFormat()
{
	return this->m_uiFormat;
}

// �t�H���g�ݒ�
void ColorStatic::SetFontEx(CFont* pFont)
{
	if (pFont != nullptr)
	{
		pFont->GetLogFont(&this->m_logfont);
	}
}

// �`�揈��
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

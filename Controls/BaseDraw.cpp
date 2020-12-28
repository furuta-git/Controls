#include "BaseDraw.h"

// �`�揈��(OnPaint���ŌĂяo��)
void BaseDraw::DrawExecute(CDC* pDC, CRect& rc)
{
	// ���z�f�o�C�X�R���e�L�X�g
	CDC memDC;
	// ���z�f�o�C�X�R���e�L�X�g�p�r�b�g�}�b�v
	CBitmap memBmp;

	// ���z�f�o�C�X�R���e�L�X�g����
	memDC.CreateCompatibleDC(pDC);
	// ���z�f�o�C�X�R���e�L�X�g�p�r�b�g�}�b�v����
	memBmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	// ���z�f�o�C�X�R���e�L�X�g�Ƀr�b�g�}�b�v���蓖��
	memDC.SelectObject(&memBmp);

	// �`�揈�����{
	this->DrawObject(&memDC, rc);

	// ���f�o�C�X�R���e�L�X�g�ɉ��z�f�o�C�X�R���e�L�X�g���蓖��
	pDC->BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	// �I�u�W�F�N�g�j��
	memDC.DeleteDC();
	memBmp.DeleteObject();
}

// �`�揈��(�h����N���X�Ŏ����j
void BaseDraw::DrawObject(CDC* pDC, CRect& rc)
{
	UNREFERENCED_PARAMETER(pDC);
	UNREFERENCED_PARAMETER(rc);
}

// ���`��
void BaseDraw::DrawLine(CDC* pDC, CPoint p1, CPoint p2, int width, COLORREF color)
{
	CPen pen(PS_SOLID, width, color);
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

// ��`�`��(�g���L�A�h�ׂ��L)
void BaseDraw::DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	CBrush brs(fillColor);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush* pOldBrs = pDC->SelectObject(&brs);
	pDC->Rectangle(rc);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();
}

// ��`�`��(�g���L�A�h�ׂ���)
void BaseDraw::DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	HGDIOBJ brs = ::GetStockObject(NULL_BRUSH);
	CPen* pOldBrs = pDC->SelectObject(&pen);
	HGDIOBJ hOldBrs = pDC->SelectObject(brs);
	pDC->Rectangle(rc);
	pDC->SelectObject(pOldBrs);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
}

// ��`�`��(�g�����A�h�ׂ��L)
void BaseDraw::DrawRect(CDC* pDC, CRect rc, COLORREF fillColor)
{
	pDC->FillSolidRect(rc, fillColor);
}

// �p�ۋ�`�`��(�g���L�A�h�ׂ��L)
void BaseDraw::DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor, COLORREF fillColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	CBrush brs(fillColor);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush* pOldBrs = pDC->SelectObject(&brs);
	pDC->RoundRect(rc, r);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();
}

// �p�ۋ�`�`��(�g���L�A�h�ׂ���)
void BaseDraw::DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	HGDIOBJ brs = ::GetStockObject(NULL_BRUSH);
	CPen* pOldBrs = pDC->SelectObject(&pen);
	HGDIOBJ hOldBrs = pDC->SelectObject(brs);
	pDC->RoundRect(rc, r);
	pDC->SelectObject(pOldBrs);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
}

// �p�ۋ�`�`��(�g�����A�h�ׂ���)
void BaseDraw::DrawRoundRect(CDC* pDC, CRect rc, CPoint r, COLORREF fillColor)
{
	CPen pen(PS_SOLID, 0, fillColor);
	HGDIOBJ brs = ::GetStockObject(NULL_BRUSH);
	CPen* pOldBrs = pDC->SelectObject(&pen);
	HGDIOBJ hOldBrs = pDC->SelectObject(brs);
	pDC->RoundRect(rc, r);
	pDC->SelectObject(pOldBrs);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
}

// �~�`��(�g���L�A�h�ׂ��L)
void BaseDraw::DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	CBrush brs(fillColor);
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush* pOldBrs = pDC->SelectObject(&brs);
	pDC->Ellipse(rc);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrs);
	pen.DeleteObject();
	brs.DeleteObject();
}

// �~�`��(�g���L�A�h�ׂ���)
void BaseDraw::DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor)
{
	CPen pen(PS_SOLID, borderWidth, borderColor);
	HGDIOBJ brs = ::GetStockObject(NULL_BRUSH);
	CPen* pOldBrs = pDC->SelectObject(&pen);
	HGDIOBJ hOldBrs = pDC->SelectObject(brs);
	pDC->Ellipse(rc);
	pDC->SelectObject(pOldBrs);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
}

// �~�`��(�g�����A�h�ׂ��L)
void BaseDraw::DrawEllipse(CDC* pDC, CRect rc, COLORREF fillColor)
{
	CPen pen(PS_SOLID, 0, fillColor);
	HGDIOBJ brs = ::GetStockObject(NULL_BRUSH);
	CPen* pOldBrs = pDC->SelectObject(&pen);
	HGDIOBJ hOldBrs = pDC->SelectObject(brs);
	pDC->Ellipse(rc);
	pDC->SelectObject(pOldBrs);
	pDC->SelectObject(hOldBrs);
	pen.DeleteObject();
}

// �e�L�X�g�`��
void BaseDraw::DrawString(CDC* pDC, CRect rc, CString text, COLORREF color, UINT format, CFont* pFont)
{
	int iOldBkMode = pDC->SetBkMode(TRANSPARENT);
	COLORREF cOldColor = pDC->SetTextColor(color);
	CFont* pOldFont = pDC->SelectObject(pFont);
	pDC->DrawText(text, rc, format);
	pDC->SetBkMode(iOldBkMode);
	pDC->SetTextColor(cOldColor);
	pDC->SelectObject(pOldFont);
}

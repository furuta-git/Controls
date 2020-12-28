#pragma once
#include <afxwin.h>

// �`����N���X
class BaseDraw
{
protected:
	// �`�揈��(OnPaint���ŌĂяo��)
	void DrawExecute(CDC* pDC, CRect& rc);
	// �`�揈��(�h����N���X�Ŏ����j
	virtual void DrawObject(CDC* pDC, CRect& rc);

	// ���`��
	void DrawLine(CDC* pDC, CPoint p1, CPoint p2, int width, COLORREF color);

	// ��`�`��(�g���L�A�h�ׂ��L)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// ��`�`��(�g���L�A�h�ׂ���)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// ��`�`��(�g�����A�h�ׂ��L)
	void DrawRect(CDC* pDC, CRect rc, COLORREF fillColor);

	// �p�ۋ�`�`��(�g���L�A�h�ׂ��L)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// �p�ۋ�`�`��(�g���L�A�h�ׂ���)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor);
	// �p�ۋ�`�`��(�g�����A�h�ׂ���)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, COLORREF fillColor);

	// �~�`��(�g���L�A�h�ׂ��L)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// �~�`��(�g���L�A�h�ׂ���)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// �~�`��(�g�����A�h�ׂ��L)
	void DrawEllipse(CDC* pDC, CRect rc, COLORREF fillColor);

	// �e�L�X�g�`��
	void DrawString(CDC* pDC, CRect rc, CString text, COLORREF color, UINT format, CFont* pFont);
};


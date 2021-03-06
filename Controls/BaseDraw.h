#pragma once
#include <afxwin.h>

// `ζξκNX
class BaseDraw
{
protected:
	// `ζ(OnPaintΰΕΔΡo΅)
	void DrawExecute(CDC* pDC, CRect& rc);
	// `ζ(hΆζNXΕΐj
	virtual void DrawObject(CDC* pDC, CRect& rc);

	// ό`ζ
	void DrawLine(CDC* pDC, CPoint p1, CPoint p2, int width, COLORREF color);

	// ι``ζ(gόLAhΧ΅L)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// ι``ζ(gόLAhΧ΅³)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// ι``ζ(gό³AhΧ΅L)
	void DrawRect(CDC* pDC, CRect rc, COLORREF fillColor);

	// pΫι``ζ(gόLAhΧ΅L)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// pΫι``ζ(gόLAhΧ΅³)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor);
	// pΫι``ζ(gό³AhΧ΅³)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, COLORREF fillColor);

	// ~`ζ(gόLAhΧ΅L)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// ~`ζ(gόLAhΧ΅³)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// ~`ζ(gό³AhΧ΅L)
	void DrawEllipse(CDC* pDC, CRect rc, COLORREF fillColor);

	// eLXg`ζ
	void DrawString(CDC* pDC, CRect rc, CString text, COLORREF color, UINT format, CFont* pFont);
};


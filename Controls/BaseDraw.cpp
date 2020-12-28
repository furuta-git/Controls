#include "BaseDraw.h"

// 描画処理(OnPaint内で呼び出し)
void BaseDraw::DrawExecute(CDC* pDC, CRect& rc)
{
	// 仮想デバイスコンテキスト
	CDC memDC;
	// 仮想デバイスコンテキスト用ビットマップ
	CBitmap memBmp;

	// 仮想デバイスコンテキスト生成
	memDC.CreateCompatibleDC(pDC);
	// 仮想デバイスコンテキスト用ビットマップ生成
	memBmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	// 仮想デバイスコンテキストにビットマップ割り当て
	memDC.SelectObject(&memBmp);

	// 描画処理実施
	this->DrawObject(&memDC, rc);

	// 実デバイスコンテキストに仮想デバイスコンテキスト割り当て
	pDC->BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	// オブジェクト破棄
	memDC.DeleteDC();
	memBmp.DeleteObject();
}

// 描画処理(派生先クラスで実装）
void BaseDraw::DrawObject(CDC* pDC, CRect& rc)
{
	UNREFERENCED_PARAMETER(pDC);
	UNREFERENCED_PARAMETER(rc);
}

// 線描画
void BaseDraw::DrawLine(CDC* pDC, CPoint p1, CPoint p2, int width, COLORREF color)
{
	CPen pen(PS_SOLID, width, color);
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(p1);
	pDC->LineTo(p2);
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

// 矩形描画(枠線有、塗潰し有)
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

// 矩形描画(枠線有、塗潰し無)
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

// 矩形描画(枠線無、塗潰し有)
void BaseDraw::DrawRect(CDC* pDC, CRect rc, COLORREF fillColor)
{
	pDC->FillSolidRect(rc, fillColor);
}

// 角丸矩形描画(枠線有、塗潰し有)
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

// 角丸矩形描画(枠線有、塗潰し無)
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

// 角丸矩形描画(枠線無、塗潰し無)
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

// 円描画(枠線有、塗潰し有)
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

// 円描画(枠線有、塗潰し無)
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

// 円描画(枠線無、塗潰し有)
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

// テキスト描画
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

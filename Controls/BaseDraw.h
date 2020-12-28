#pragma once
#include <afxwin.h>

// 描画基底クラス
class BaseDraw
{
protected:
	// 描画処理(OnPaint内で呼び出し)
	void DrawExecute(CDC* pDC, CRect& rc);
	// 描画処理(派生先クラスで実装）
	virtual void DrawObject(CDC* pDC, CRect& rc);

	// 線描画
	void DrawLine(CDC* pDC, CPoint p1, CPoint p2, int width, COLORREF color);

	// 矩形描画(枠線有、塗潰し有)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// 矩形描画(枠線有、塗潰し無)
	void DrawRect(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// 矩形描画(枠線無、塗潰し有)
	void DrawRect(CDC* pDC, CRect rc, COLORREF fillColor);

	// 角丸矩形描画(枠線有、塗潰し有)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// 角丸矩形描画(枠線有、塗潰し無)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, int borderWidth, COLORREF borderColor);
	// 角丸矩形描画(枠線無、塗潰し無)
	void DrawRoundRect(CDC* pDC, CRect rc, CPoint r, COLORREF fillColor);

	// 円描画(枠線有、塗潰し有)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor, COLORREF fillColor);
	// 円描画(枠線有、塗潰し無)
	void DrawEllipse(CDC* pDC, CRect rc, int borderWidth, COLORREF borderColor);
	// 円描画(枠線無、塗潰し有)
	void DrawEllipse(CDC* pDC, CRect rc, COLORREF fillColor);

	// テキスト描画
	void DrawString(CDC* pDC, CRect rc, CString text, COLORREF color, UINT format, CFont* pFont);
};


#pragma once
#include <afxwin.h>
#include "BaseDraw.h"

// カラースタティッククラス
class ColorStatic : public CStatic, protected BaseDraw
{
public:
	// コンストラクタ
	ColorStatic();
	// デストラクタ
	~ColorStatic();

protected:
	// MFC標準PreSubclassWindow
	virtual void PreSubclassWindow();
	// MFC標準PreTranslateMessage
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
	// MFC標準OnPaint
	afx_msg void OnPaint();

public:
	// 文字色設定
	void SetForeColor(COLORREF color);
	// 文字色取得
	COLORREF GetForeColor();
	// 背景色設定
	void SetBackColor(COLORREF color);
	// 背景色取得
	COLORREF GetBackColor();
	// フォーマット設定
	void SetFormat(UINT format);
	// フォーマット取得
	UINT GetFormat();
	// フォント設定
	void SetFontEx(CFont* pFont);

protected:
	// 描画処理
	virtual void DrawObject(CDC* pDC, CRect& rc);

protected:
	// 文字色
	COLORREF m_foreColor;
	// 背景色
	COLORREF m_backColor;
	// フォーマット
	UINT m_uiFormat;
	// フォント情報
	LOGFONT m_logfont;
};


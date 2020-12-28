#pragma once
#include <afxwin.h>
#include "BaseDraw.h"

// �J���[�X�^�e�B�b�N�N���X
class ColorStatic : public CStatic, protected BaseDraw
{
public:
	// �R���X�g���N�^
	ColorStatic();
	// �f�X�g���N�^
	~ColorStatic();

protected:
	// MFC�W��PreSubclassWindow
	virtual void PreSubclassWindow();
	// MFC�W��PreTranslateMessage
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
	// MFC�W��OnPaint
	afx_msg void OnPaint();

public:
	// �����F�ݒ�
	void SetForeColor(COLORREF color);
	// �����F�擾
	COLORREF GetForeColor();
	// �w�i�F�ݒ�
	void SetBackColor(COLORREF color);
	// �w�i�F�擾
	COLORREF GetBackColor();
	// �t�H�[�}�b�g�ݒ�
	void SetFormat(UINT format);
	// �t�H�[�}�b�g�擾
	UINT GetFormat();
	// �t�H���g�ݒ�
	void SetFontEx(CFont* pFont);

protected:
	// �`�揈��
	virtual void DrawObject(CDC* pDC, CRect& rc);

protected:
	// �����F
	COLORREF m_foreColor;
	// �w�i�F
	COLORREF m_backColor;
	// �t�H�[�}�b�g
	UINT m_uiFormat;
	// �t�H���g���
	LOGFONT m_logfont;
};


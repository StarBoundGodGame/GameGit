#pragma once

#define MAX_INPUT_BTN 8
#define MAX_INPUT_KEY 256

class CInput
{
public:
	enum EINPUT_STATE
	{
		EINPUT_NONE = 0,
		EINPUT_DOWN = 1,
		EINPUT_UP	= 2,
		EINPUT_PRESS = 3,
		EINPUT_DBCLC = 4,
	};
public:
	HWND m_hWnd = NULL;

	BYTE m_KeyOld[MAX_INPUT_KEY];
	BYTE m_KeyCur[MAX_INPUT_KEY];
	BYTE m_KeyMap[MAX_INPUT_KEY];

	BYTE m_BtnOld[MAX_INPUT_BTN];
	BYTE m_BtnCur[MAX_INPUT_BTN];
	BYTE m_BtnMap[MAX_INPUT_BTN];

	D3DXVECTOR3 m_vcCur;
	D3DXVECTOR3 m_vcOld;
	D3DXVECTOR3 m_vcEps;

	DWORD	m_dTimeDC;
	DWORD	m_dBtnBgn[MAX_INPUT_BTN];
	INT		m_dBtnCnt[MAX_INPUT_BTN];

public:
	CInput();
	~CInput();

	void  Create(HWND hWnd);
	void  Update();

};


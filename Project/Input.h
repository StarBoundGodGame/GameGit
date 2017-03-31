#pragma once

#define MAX_INPUT_BTN 8
#define MAX_INPUT_KEY 256

class CInput
{
public:
	enum EInput_State
	{
		EINPUT_NONE = 0,
		EINPUT_DOWN = 1,
		EINPUT_UP = 2,
		EINPUT_PRESS = 3,
		EINPUT_DBCLC = 4,
	};
public:
	HWND m_hWnd = NULL;

	BYTE m_KeyCur[MAX_INPUT_KEY];
	BYTE m_KeyOld[MAX_INPUT_KEY];
	BYTE m_KeyMap[MAX_INPUT_KEY];

	BYTE m_BtnCur[MAX_INPUT_BTN];
	BYTE m_BtnOld[MAX_INPUT_BTN];
	BYTE m_BtnMap[MAX_INPUT_BTN];

	D3DXVECTOR2 m_vcCur;
	D3DXVECTOR2 m_vcOld;
	D3DXVECTOR2 m_vcEps;

	DWORD m_dTimeDC;
	INT m_dBtnCnt[MAX_INPUT_BTN];
	DWORD m_dBtnBgn[MAX_INPUT_BTN];
public:
	CInput();
	~CInput();

	void Create(HWND hWnd);
	void Update();

	int		KeyState(INT nKey);
	bool	KeyDown(INT nKey);
	bool	KeyUp(INT nKey);
	bool	KeyPress(INT nKey);

	int		BtnState(INT nKey);
	bool	BtnDown(INT nKey);
	bool	BtnUp(INT nKey);
	bool	BtnPress(INT nKey);

	D3DXVECTOR2 GetMousePos();
	D3DXVECTOR2 GetMouseEps();
};


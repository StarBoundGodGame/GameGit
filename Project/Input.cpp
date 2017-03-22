#include "StdAfx.h"


CInput::CInput()
{
}


CInput::~CInput()
{
}

void CInput::Create(HWND hWnd)
{
	m_hWnd = hWnd;

	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	SetKeyboardState(m_KeyCur);

	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	m_vcCur = D3DXVECTOR3(0, 0, 0);
	m_vcOld = D3DXVECTOR3(0, 0, 0);
	m_vcEps = D3DXVECTOR3(0, 0, 0);


	m_dTimeDC = GetDoubleClickTime();

	m_dBtnBgn[0] = timeGetTime();

	for (int i = 1; i < MAX_INPUT_BTN; ++i)
	{
		m_dBtnBgn[i] = m_dBtnBgn[0];
	}
	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));
}

void CInput::Update()
{
	memcpy(m_KeyOld, m_KeyCur, sizeof(m_KeyOld));
	memcpy(m_BtnOld, m_BtnCur, sizeof(m_BtnOld));

	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	GetKeyboardState(m_KeyCur);

	for (int i = 0; i < MAX_INPUT_KEY; ++i)
	{
		int vKey = m_KeyCur[i] & 0x80;
		m_KeyCur[i] = (vKey) ? 1 : 0;

		INT nCur = m_KeyCur[i];
		INT nOld = m_KeyOld[i];

		if (nCur == 1 && nOld == 0)		 m_KeyMap[i] = EINPUT_DOWN;
		else if (nCur == 0 && nOld == 1) m_KeyMap[i] = EINPUT_UP;
		else if (nCur == 1 && nOld == 1) m_KeyMap[i] = EINPUT_PRESS;
		else							 m_KeyMap[i] = EINPUT_NONE;
	}

	m_BtnCur[0] = m_KeyCur[VK_LBUTTON];
	m_BtnCur[1] = m_KeyCur[VK_RBUTTON];
	m_BtnCur[2] = m_KeyCur[VK_MBUTTON];

	for (int i = 0; i < MAX_INPUT_BTN; ++i)
	{
		INT nCur = m_BtnCur[i];
		INT nOld = m_BtnOld[i];

		if (nCur == 1 && nOld == 0)		 m_BtnMap[i] = EINPUT_DOWN;
		else if (nCur == 0 && nOld == 1) m_BtnMap[i] = EINPUT_UP;
		else if (nCur == 1 && nOld == 1) m_BtnMap[i] = EINPUT_PRESS;
		else							 m_BtnMap[i] = EINPUT_NONE;
	}

	POINT pt;
	GetCursorPos(&pt);
	ClientToScreen(m_hWnd, &pt);

	m_vcOld = m_vcCur;
	
	m_vcCur.x = FLOAT(pt.x);
	m_vcCur.y = FLOAT(pt.y);

	m_vcEps = m_vcCur - m_vcOld;

	DWORD dBtnCur = timeGetTime();

	for (int i = 0; i < MAX_INPUT_BTN; ++i)
	{
		if (m_BtnMap[i] == EINPUT_DOWN)
		{
			if (m_dBtnCnt[i] == 1)
			{
				if (dBtnCur - m_dBtnBgn[i] >= m_dTimeDC)
					m_dBtnCnt[i] = 0;
			}

			++m_dBtnCnt[i];

			if (m_dBtnCnt[i] == 1)
				m_dBtnBgn[i] = dBtnCur;
		}

		if (m_BtnMap[i] == EINPUT_UP)
		{
			if (m_dBtnCnt[i] == 1)
			{
				if (dBtnCur - m_dBtnBgn[i] >= m_dTimeDC)
					m_dBtnCnt[i] = 0;
			}

			else if (m_dBtnCnt[i] == 2)
			{
				if (dBtnCur - m_dBtnBgn[i] <= m_dTimeDC)
					m_BtnMap[i] = EINPUT_DBCLC;
				m_dBtnCnt[i] = 0;
			}
		}
	}
}
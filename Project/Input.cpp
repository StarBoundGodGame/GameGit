#include "_StdAfx.h"


CInput::CInput()
{
	m_hWnd = NULL;
	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	SetKeyboardState(m_BtnCur);

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	m_vcCur = D3DXVECTOR2(0.0f, 0.0f);
	m_vcOld = D3DXVECTOR2(0.0f, 0.0f);
	m_vcEps = D3DXVECTOR2(0.0f, 0.0f);

	m_dTimeDC = GetDoubleClickTime();
	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));

	m_dBtnBgn[0] = timeGetTime();
	for (int i = 1; i < MAX_INPUT_BTN; ++i)
		m_dBtnBgn[i] = m_dBtnBgn[0];

}


CInput::~CInput()
{
}

void CInput::Create(HWND hWnd)
{
	m_hWnd = hWnd;

	memset(m_KeyCur, 0, sizeof(m_KeyCur));
	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	SetKeyboardState(m_BtnCur);

	memset(m_BtnCur, 0, sizeof(m_BtnCur));
	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	m_vcCur = D3DXVECTOR2(0.0f, 0.0f);
	m_vcOld = D3DXVECTOR2(0.0f, 0.0f);
	m_vcEps = D3DXVECTOR2(0.0f, 0.0f);

	m_dTimeDC = GetDoubleClickTime();
	memset(m_dBtnCnt, 0, sizeof(m_dBtnCnt));

	m_dBtnBgn[0] = timeGetTime();
	for (int i = 1; i < MAX_INPUT_BTN; ++i)
		m_dBtnBgn[i] = m_dBtnBgn[0];
}

void CInput::Update()
{
	memcpy(m_KeyOld, m_KeyCur, sizeof(m_KeyOld));
	memcpy(m_BtnOld, m_BtnCur, sizeof(m_BtnOld));
	
	memset(m_KeyOld, 0, sizeof(m_KeyOld));
	memset(m_KeyMap, 0, sizeof(m_KeyMap));

	memset(m_BtnOld, 0, sizeof(m_BtnOld));
	memset(m_BtnMap, 0, sizeof(m_BtnMap));

	GetKeyboardState(m_BtnCur);

	for (int i = 0; i < MAX_INPUT_KEY; ++i)
	{
		BYTE vKey = m_KeyCur[i] & 0x80;
		m_KeyCur[i] = (vKey) ? 1 : 0;

		INT nOld = m_KeyOld[i];
		INT nCur = m_KeyCur[i];
		
		if (nOld == 0 && nCur == 1) m_KeyMap[i] == EINPUT_DOWN;
		if (nOld == 1 && nCur == 0) m_KeyMap[i] == EINPUT_UP;
		if (nOld == 1 && nCur == 1) m_KeyMap[i] == EINPUT_PRESS;
		else						m_KeyMap[i] = EINPUT_NONE;
	}

	m_BtnCur[0] = m_KeyCur[VK_LBUTTON];
	m_BtnCur[1] = m_KeyCur[VK_RBUTTON];
	m_BtnCur[2] = m_KeyCur[VK_MBUTTON];

	for (int i = 0; i < MAX_INPUT_BTN; ++i)
	{
		INT nOld = m_BtnOld[i];
		INT nCur = m_BtnCur[i];

		if (nOld == 0 && nCur == 1) m_BtnMap[i] == EINPUT_DOWN;
		if (nOld == 1 && nCur == 0) m_BtnMap[i] == EINPUT_UP;
		if (nOld == 1 && nCur == 1) m_BtnMap[i] == EINPUT_PRESS;
		else						m_BtnMap[i] = EINPUT_NONE;
	}

	POINT pt;
	::GetCursorPos(&pt);
	::ClientToScreen(m_hWnd, &pt);

	m_vcCur.x = FLOAT(pt.x);
	m_vcCur.y = FLOAT(pt.y);
	
	m_vcEps = m_vcCur - m_vcOld;

	m_vcOld = m_vcCur;

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
				m_dBtnBgn[i] == dBtnCur;
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
					m_BtnMap[i] == EINPUT_DBCLC;
				m_dBtnCnt[i] = 0;
			}
		}
	}
}

int	CInput::KeyState(INT nKey)
{
	return m_KeyMap[nKey];
}
bool CInput::KeyDown(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_DOWN;
}
bool CInput::KeyUp(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_UP;
}
bool CInput::KeyPress(INT nKey)
{
	return m_KeyMap[nKey] == EINPUT_PRESS;
}

int	CInput::BtnState(INT nKey)
{
	return m_BtnMap[nKey];
}
bool CInput::BtnDown(INT nKey)
{
	return m_BtnMap[nKey] == EINPUT_DOWN;
}
bool CInput::BtnUp(INT nKey)
{
	return m_BtnMap[nKey] == EINPUT_UP;
}
bool CInput::BtnPress(INT nKey)
{
	return m_BtnMap[nKey] == EINPUT_PRESS;
}

D3DXVECTOR2 CInput::GetMousePos()
{
	return m_vcCur;
}
D3DXVECTOR2 CInput::GetMouseEps()
{
	return m_vcEps;
}
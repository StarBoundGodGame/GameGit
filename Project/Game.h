#pragma once
class CGame : public CD3DApp
{
public:
	CGame();
	~CGame();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual VOID Destroy();

	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
extern CGame* g_pApp;


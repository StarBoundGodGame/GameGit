#pragma once
class CGame : public CD3DApp
{
public:

public:
	CGame();
	~CGame();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual VOID Destroy();
};
extern CGame* g_pApp;
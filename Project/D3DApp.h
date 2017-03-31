#pragma once
class CD3DApp
{
public:
	HWND				m_hWnd = NULL;
	HINSTANCE			m_hInst = NULL;

	LPDIRECT3D9         m_pD3D = NULL;
	LPDIRECT3DDEVICE9   m_pd3dDevice = NULL;
	LPD3DXSPRITE		m_pd3dSprite = NULL;

	DWORD				m_dScnX = 1600;
	DWORD				m_dScnY = 900;

	BOOL				m_Windowed = TRUE;

	FLOAT				m_fFps = 0.0f;
	FLOAT				m_fDeltaTime = 0.0f;
public:
	CD3DApp();
	virtual ~CD3DApp();

	HRESULT		Create(HINSTANCE hInst);
	INT			Run();
	INT			Render3D();
	VOID		CleanUp();

	virtual INT Init(){ return 0; }
	virtual INT Update(){ return 0; }
	virtual INT Render(){ return 0; }
	virtual VOID Destroy(){}

	static  LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	virtual LRESULT		   MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void  UpdateFrame();
	float GetDeltaTime();
};


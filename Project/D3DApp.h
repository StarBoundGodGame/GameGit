#pragma once
class CD3DApp
{
public:
	bool				m_Windowed = FALSE;
	DWORD				m_dScnX = 1280;
	DWORD				m_dScnY = 960;

	HWND				m_hWnd = NULL;
	HINSTANCE			m_hInst = NULL;

	LPDIRECT3D9         m_pD3D = NULL;
	LPD3DXSPRITE		m_pd3DSprite = NULL;
	LPDIRECT3DDEVICE9   m_pd3dDevice = NULL;

	FLOAT				m_fFps = 0.0f;
	FLOAT				m_fDeltaTime = 0.0f;
public:
	CD3DApp();
	~CD3DApp();

	HRESULT Create(HINSTANCE hInst);
	INT		Run();
	INT		Render3D();
	VOID	CleanUp();

	virtual INT  Init()   { return 0; }
	virtual INT  Update() { return 0; }
	virtual INT  Render() { return 0; }
	virtual VOID Destroy(){           }

	virtual LRESULT MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static  LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	void UpdateFrame();
	float GetDeltaTime();
};


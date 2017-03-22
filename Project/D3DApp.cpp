#include "StdAfx.h"

static CD3DApp* g_pD3DApp = NULL;

CD3DApp::CD3DApp()
{
}


CD3DApp::~CD3DApp()
{
}

HRESULT CD3DApp::Create(HINSTANCE hInst)
{
	m_hInst = hInst;
	g_pD3DApp = this;

	UNREFERENCED_PARAMETER(hInst);

	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"2D Shooting Game", NULL
	};
	RegisterClassEx(&wc);

	m_hWnd = CreateWindow("2D Shooting Game", "2D Shooting Game Title",
		WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST | WS_POPUP, 0, 0, m_dScnX, m_dScnY,
		NULL, NULL, wc.hInstance, NULL);

	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = m_Windowed;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = m_dScnX;
	d3dpp.BackBufferHeight = m_dScnY;

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pd3dDevice, &m_pd3DSprite)))
		return E_FAIL;

	if (FAILED(Init()))
		return E_FAIL;

	return S_OK;
}

INT CD3DApp::Run()
{
	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);

	MSG msg;
	memset(&msg, 0, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, m_hWnd, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (FAILED(Render3D()))
				break;
		}
	}

	UnregisterClass("2D Shooting Game", m_hInst);
	return 0;
}

INT CD3DApp::Render3D()
{
	if (NULL == m_pd3dDevice)
		return -1;

	if (FAILED(Update()))
		return -1;


	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{		
		if (FAILED(Render()))
			return -1;

		m_pd3dDevice->EndScene();
	}

	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	UpdateFrame();

	return 0;
}

VOID CD3DApp::CleanUp()
{
	SAFE_RELEASE(m_pd3dDevice);
	SAFE_RELEASE(m_pd3DSprite);
	SAFE_RELEASE(m_pD3D);
}

LRESULT CD3DApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return g_pD3DApp->MsgProc(hWnd, msg, wParam, lParam);
}

LRESULT CD3DApp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		CleanUp();
		PostQuitMessage(0);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CD3DApp::UpdateFrame()
{
	static int iCnt = 0;
	static DWORD dB = timeGetTime();
		   DWORD dE = timeGetTime();

	++iCnt;

	if (iCnt > 30)
	{
		m_fFps = FLOAT(dE - dB);
		m_fDeltaTime = m_fFps / 1000.0f;
		m_fFps = iCnt * 1000 / m_fFps;

		iCnt = 0;
		dB = dE;
	}
}

float CD3DApp::GetDeltaTime()
{
	return m_fDeltaTime;
}
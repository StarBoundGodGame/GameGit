#include "_StdAfx.h"

static CD3DApp* g_pD3DApp = NULL;

CD3DApp::CD3DApp()
{
	g_pD3DApp = this;
}


CD3DApp::~CD3DApp()
{
}


HRESULT	CD3DApp::Create(HINSTANCE hInst)
{
	m_hInst = hInst;

	UNREFERENCED_PARAMETER(hInst);

	// Register the window class
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	RegisterClassEx(&wc);

	// Create the application's window
	m_hWnd = CreateWindow("D3D Tutorial", "2D Shooting Game",
		WS_POPUP | WS_EX_TOPMOST , 0, 0, m_dScnX, m_dScnY,
		NULL, NULL, wc.hInstance, NULL);

	// Create the D3D object, which is needed to create the D3DDevice.
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Set up the structure used to create the D3DDevice. Most parameters are
	// zeroed out. We set Windowed to TRUE, since we want to do D3D in a
	// window, and then set the SwapEffect to "discard", which is the most
	// efficient method of presenting the back buffer to the display.  And 
	// we request a back buffer format that matches the current desktop display 
	// format.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = m_Windowed;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;

	if (!m_Windowed)
	{
		d3dpp.BackBufferWidth = m_dScnX;
		d3dpp.BackBufferHeight = m_dScnY;
	}

	// Create the Direct3D device. Here we are using the default adapter (most
	// systems only have one, unless they have multiple graphics hardware cards
	// installed) and requesting the HAL (which is saying we want the hardware
	// device rather than a software one). Software vertex processing is 
	// specified since we know it will work on all cards. On cards that support 
	// hardware vertex processing, though, we would see a big performance gain 
	// by specifying hardware vertex processing.
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite)))
		return E_FAIL;

	// Device state would normally be set here

	if (FAILED(Init()))
		return E_FAIL;

	return S_OK;

}
INT	CD3DApp::Run()
{
	// Show the window
	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);

	// Enter the message loop
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

	UnregisterClass("D3D Tutorial", m_hInst);
	return 0;
}
INT	CD3DApp::Render3D()
{
	if (NULL == m_pd3dDevice)
		return -1;

	if (FAILED(Update()))
		return -1;

	// Clear the backbuffer to a blue color
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{
		// Rendering of scene objects can happen here

		if (FAILED(Render()))
			return -1;

		// End the scene
		m_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	return 0;
}
VOID CD3DApp::CleanUp()
{
	SAFE_RELEASE(m_pd3dDevice);
	SAFE_RELEASE(m_pd3dSprite);
	SAFE_RELEASE(m_pD3D);
}

LRESULT WINAPI CD3DApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return g_pD3DApp->MsgProc(hWnd, msg, wParam, lParam);
}

LRESULT CD3DApp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Destroy();
		CleanUp();
		PostQuitMessage(0);
		return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
		}
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CD3DApp::UpdateFrame()
{
	static INT iCnt = 0;

	static DWORD dB = timeGetTime();
	DWORD dE = timeGetTime();

	++iCnt;

	if (iCnt > 30)
	{
		m_fFps = FLOAT(dE - dB);
		m_fDeltaTime = m_fFps / 1000.0f;
		m_fFps = iCnt * 1000.0f / m_fFps;

		iCnt = 0;
		dB = timeGetTime();
	}
}

float CD3DApp::GetDeltaTime()
{
	return m_fDeltaTime;
}
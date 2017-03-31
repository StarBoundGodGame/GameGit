#include "_StdAfx.h"

CGame* g_pApp = NULL;
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
	CGame d3dApp;
	g_pApp = &d3dApp;

	if (FAILED(g_pApp->Create(hInst)))
		return -1;

    return g_pApp->Run();
}
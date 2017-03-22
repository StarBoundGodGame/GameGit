#include "StdAfx.h"

CGame* g_pApp = NULL;
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
	CGame d3dapp;
	g_pApp = &d3dapp;

	if (FAILED(g_pApp->Create(hInst)))
		return -1;

	return g_pApp->Run();
}
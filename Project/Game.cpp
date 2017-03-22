#include "StdAfx.h"


CGame::CGame()
{
}


CGame::~CGame()
{
}

INT CGame::Init()
{
	return 0;
}

INT CGame::Update()
{
	return 0;
}

INT CGame::Render()
{
	return 0;
}

VOID CGame::Destroy()
{

}

LRESULT CGame::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CD3DApp::MsgProc(hWnd, msg, wParam, lParam);
}
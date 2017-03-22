#include "StdAfx.h"
#include "Texture.h"


CTexture::CTexture()
{
	memset(&m_Img, 0, sizeof(m_Img));
}


CTexture::~CTexture()
{
	Destroy();
}

VOID CTexture::Destroy()
{
	SAFE_RELEASE(m_pTx);
}

INT CTexture::Create(char* sFile)
{
	DWORD dColorKey = 0xFFFFFFFF;
	if (FAILED(D3DXCreateTextureFromFileEx(g_pApp->m_pd3dDevice, sFile, D3DX_DEFAULT, D3DX_DEFAULT, 1, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, dColorKey, &m_Img, NULL, &m_pTx)))
	{
		cout << "Texture Load Failed !" << endl;
		return -1;
	}

	m_Rect = GetImageRect();

	return 0;
}

void CTexture::SetRect(RECT rect)
{
	m_Rect = rect;
}

void CTexture::SetRect(int left, int top, int right, int bottom)
{
	m_Rect.left = left;
	m_Rect.right = right;
	m_Rect.top = top;
	m_Rect.bottom = bottom;
}

RECT CTexture::GetRect()
{
	return m_Rect;
}

INT CTexture::GetImageWidth()
{
	return m_Img.Width;
}

INT CTexture::GetImageHeight()
{
	return m_Img.Height;
}

RECT CTexture::GetImageRect()
{
	RECT rt;
	
	rt.left = 0; rt.top = 0;
	rt.right = m_Img.Width; rt.bottom = m_Img.Height;

	return rt;
}

LPDIRECT3DTEXTURE9 CTexture::GetTexture()
{
	return m_pTx;
}
#include "_StdAfx.h"


CTexture::CTexture()
{
}


CTexture::~CTexture()
{
	Destroy();
}

INT CTexture::Create(char* sFile)
{
	if (FAILED(D3DXCreateTextureFromFileEx(g_pApp->m_pd3dDevice, sFile, D3DX_DEFAULT, D3DX_DEFAULT,
		1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, &m_Img, NULL, &m_pTx)))
	{
		MessageBox(NULL, "Texture Create Failed!", NULL, NULL);
		return -1;
	}

	m_Rect = GetImageRect();
	return 0;
}

VOID CTexture::Destroy()
{
	SAFE_RELEASE(m_pTx);
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
	rt.right = GetImageWidth(); rt.bottom = GetImageHeight();

	return rt;
}
void CTexture::SetTexture(LPDIRECT3DTEXTURE9 pTx, D3DXIMAGE_INFO info)
{
	m_pTx = pTx;
	m_Img = info;
	m_Rect = GetImageRect();
}
LPDIRECT3DTEXTURE9 CTexture::GetTexture()
{
	return m_pTx;
}

D3DXIMAGE_INFO CTexture::GetImageInfo()
{
	return m_Img;
}
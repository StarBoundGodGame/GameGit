#pragma once
class CTexture
{
protected:
	RECT				m_Rect;
	D3DXIMAGE_INFO		m_Img;
	LPDIRECT3DTEXTURE9	m_pTx;
public:
	CTexture();
	virtual ~CTexture();

	virtual INT Create(char* sFile);
	virtual VOID Destroy();

	RECT GetRect();

	INT GetImageWidth();
	INT GetImageHeight();
	RECT GetImageRect();

	void SetTexture(LPDIRECT3DTEXTURE9 pTx, D3DXIMAGE_INFO info);
	LPDIRECT3DTEXTURE9 GetTexture();

	D3DXIMAGE_INFO GetImageInfo();
};


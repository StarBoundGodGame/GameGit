#pragma once
class CTexture
{
protected:
	RECT			   m_Rect;
	D3DXIMAGE_INFO	   m_Img;
	LPDIRECT3DTEXTURE9 m_pTx = NULL;
public:
	CTexture();
	virtual ~CTexture();

	virtual INT Create(char* sFile);
	virtual VOID Destroy();

	void SetRect(RECT rect);
	void SetRect(int left, int top, int right, int bottom);
	RECT GetRect();

	INT  GetImageWidth();
	INT  GetImageHeight();
	RECT GetImageRect();

	LPDIRECT3DTEXTURE9 GetTexture();
};


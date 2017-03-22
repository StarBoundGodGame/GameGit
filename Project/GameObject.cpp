#include "StdAfx.h"


GameObject::GameObject()
{
	_Enable = true;
	_Rotation = 0.0f;

	_Color = D3DXCOLOR(0, 0, 0, 0);
	_Pos = D3DXVECTOR2(0, 0);
	_Pivot = D3DXVECTOR2(0, 0);
	_Scale = D3DXVECTOR2(0, 0);
}


GameObject::~GameObject()
{
	Destroy();
}

void GameObject::Draw()
{
	if (!_Enable)
		return;

	D3DXMATRIX mtW;
	D3DXMatrixIdentity(&mtW);

	D3DXMATRIX mtP;
	D3DXMatrixTranslation(&mtP, -GetImageWidth() *_Pivot.x, -GetImageHeight() * _Pivot.y, 0.0f);

	D3DXMATRIX mtR;
	D3DXMatrixRotationZ(&mtR, _Rotation);

	D3DXMATRIX mtS;
	D3DXMatrixScaling(&mtS, _Scale.x, _Scale.y, 0.0f);

	D3DXMATRIX mtT;
	D3DXMatrixTranslation(&mtT, _Pos.x, _Pos.y, 0.0f);

	mtW = mtT * (mtR * mtS) * mtT;

	g_pApp->m_pd3DSprite->Begin(D3DXSPRITE_ALPHABLEND);

	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_ADD);
	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG0, D3DTA_TEXTURE);
	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_DIFFUSE);

	g_pApp->m_pd3DSprite->SetTransform(&mtW);

	g_pApp->m_pd3DSprite->Draw(m_pTx, &m_Rect, 0, 0, _Color);

	D3DXMatrixIdentity(&mtW);
	g_pApp->m_pd3DSprite->SetTransform(&mtW);

	g_pApp->m_pd3DSprite->End();
}

INT GameObject::Init()
{
	_Enable = true;
	_Rotation = 0.0f;

	_Color = D3DXCOLOR(0, 0, 0, 0);
	_Pos = D3DXVECTOR2(0, 0);
	_Pivot = D3DXVECTOR2(0, 0);
	_Scale = D3DXVECTOR2(0, 0);

	return 0;
}

INT GameObject::Update()
{
	return 0;
}

INT GameObject::Render()
{
	Draw();
	return 0;
}

void GameObject::SetEnable(bool enable)
{
	_Enable = enable;
}
bool GameObject::GetEnable()
{
	return _Enable;
}

void GameObject::SetRotation(float rotation)
{
	_Rotation = rotation;
}
float GameObject::GetRotation()
{
	return _Rotation;
}

void GameObject::SetColor(float r, float g, float b, float a)
{
	_Color = D3DXCOLOR(r, g, b, a);
}
void GameObject::SetColor(D3DXCOLOR color)
{
	_Color = color;
}
D3DXCOLOR GameObject::GetColor()
{
	return _Color;
}

D3DXVECTOR2 GameObject::GetPos()
{
	return _Pos;
}
void GameObject::SetPos(float x, float y)
{
	_Pos = D3DXVECTOR2(x, y);
}
void GameObject::SetPos(D3DXVECTOR2 pos)
{
	_Pos = pos;
}

float GameObject::GetPosX()
{
	return _Pos.x;
}
float GameObject::GetPosY()
{
	return _Pos.y;
}
void GameObject::SetPosX(float x)
{
	_Pos.x = x;
}
void GameObject::SetPosY(float y)
{
	_Pos.y = y;
}

D3DXVECTOR2 GameObject::GetPivot()
{
	return _Pivot;
}
void GameObject::SetPivot(float x, float y)
{
	_Pivot = D3DXVECTOR2(x, y);
}
void GameObject::SetPivot(D3DXVECTOR2 pivot)
{
	_Pivot = pivot;
}

D3DXVECTOR2 GameObject::GetScale()
{
	return _Scale;
}
void GameObject::SetScale(float x, float y)
{
	_Scale = D3DXVECTOR2(x, y);
}
void GameObject::SetScale(D3DXVECTOR2 scale)
{
	_Scale = scale;
}
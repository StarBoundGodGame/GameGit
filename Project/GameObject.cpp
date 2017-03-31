#include "_StdAfx.h"


GameObject::GameObject()
{
	_Enable = TRUE;
	_AlphaEnable = FALSE;
	_Tag = "";
	_Rotation = 0.0f;

	_Pos = D3DXVECTOR2(0.0f, 0.0f);
	_Pivot = D3DXVECTOR2(0.0f, 0.0f);
	_Scale = D3DXVECTOR2(1.0f, 1.0f);
	_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
}


GameObject::~GameObject()
{
}

INT GameObject::Init()
{
	_Enable = TRUE;
	_AlphaEnable = FALSE;
	_Tag = "";
	_Rotation = 0.0f;

	_Pos = D3DXVECTOR2(0.0f, 0.0f);
	_Pivot = D3DXVECTOR2(0.0f, 0.0f);
	_Scale = D3DXVECTOR2(1.0f, 1.0f);
	_Color = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
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

void GameObject::Draw()
{
	if (!_Enable)
		return;

	D3DXMATRIX mtW;
	D3DXMatrixIdentity(&mtW);

	D3DXMATRIX mtP;
	D3DXMatrixTranslation(&mtP, -GetImageWidth() * _Pivot.x, -GetImageHeight() * _Pivot.y, 0.0f);

	D3DXMATRIX mtS;
	D3DXMatrixScaling(&mtS, _Scale.x, _Scale.y, 0.0f);

	D3DXMATRIX mtR;
	D3DXMatrixRotationZ(&mtR, _Rotation);

	D3DXMATRIX mtT;
	D3DXMatrixTranslation(&mtT, _Pos.x, _Pos.y, 0.0f);

	mtW = mtP * (mtR * mtS) * mtT;

	g_pApp->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

	if (!_AlphaEnable)
	{
		g_pApp->m_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		g_pApp->m_pd3dDevice->SetRenderState(D3DRS_ALPHAREF, 0xff);
		g_pApp->m_pd3dDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATEREQUAL);
	}

	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_ADD);
	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pApp->m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	g_pApp->m_pd3dSprite->SetTransform(&mtW);
	g_pApp->m_pd3dSprite->Draw(m_pTx, &m_Rect, 0, 0, _Color);

	D3DXMatrixIdentity(&mtW);
	g_pApp->m_pd3dSprite->SetTransform(&mtW);

	g_pApp->m_pd3dSprite->End();
}

bool GameObject::GetEnable()
{
	return _Enable;
}
void GameObject::SetEnable(bool enable)
{
	_Enable = enable;
}

bool GameObject::GetAlphaEnable()
{
	return _AlphaEnable;
}

void GameObject::SetAlphaEnable(bool enable)
{
	_AlphaEnable = enable;
}

char* GameObject::GetTag()
{
	return _Tag;
}

void GameObject::SetTag(char* tag)
{
	_Tag = tag;
}

float GameObject::GetRotation()
{
	return _Rotation;
}
void GameObject::SetRotation(float rotation)
{
	_Rotation = rotation;
}

D3DXVECTOR2 GameObject::GetPos()
{
	return _Pos;
}
void GameObject::SetPos(D3DXVECTOR2 pos)
{
	_Pos = pos;
}
void GameObject::SetPos(float x, float y)
{
	_Pos.x = x;
	_Pos.y = y;
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
void GameObject::SetPivot(D3DXVECTOR2 pivot)
{
	_Pivot = pivot;
}
void GameObject::SetPivot(float x, float y)
{
	_Pivot.x = x;
	_Pivot.y = y;
}

D3DXVECTOR2 GameObject::GetScale()
{
	return _Scale;
}
void GameObject::SetScale(D3DXVECTOR2 scale)
{
	_Scale = scale;
}
void GameObject::SetScale(float x, float y)
{
	_Scale.x = x;
	_Scale.y = y;
}
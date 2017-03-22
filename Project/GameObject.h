#pragma once
class GameObject : public IGameObject, public CTexture
{
private:
	bool		_Enable;
	float		_Rotation;

	D3DXCOLOR   _Color;
	D3DXVECTOR2 _Pos;
	D3DXVECTOR2 _Pivot;
	D3DXVECTOR2 _Scale;
public:
	GameObject();
	virtual ~GameObject();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();

	void Draw();

	void SetEnable(bool enable);
	bool GetEnable();

	void  SetRotation(float rotation);
	float GetRotation();

	void	  SetColor(float r, float g, float b, float a);
	void	  SetColor(D3DXCOLOR color);
	D3DXCOLOR GetColor();

	D3DXVECTOR2 GetPos();
	void		SetPos(float x, float y);
	void		SetPos(D3DXVECTOR2 pos);

	float		GetPosX();
	float		GetPosY();
	void		SetPosX(float x);
	void		SetPosY(float y);

	D3DXVECTOR2 GetPivot();
	void		SetPivot(float x, float y);
	void		SetPivot(D3DXVECTOR2 pivot);

	D3DXVECTOR2 GetScale();
	void		SetScale(float x, float y);
	void		SetScale(D3DXVECTOR2 scale);
};


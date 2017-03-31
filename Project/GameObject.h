#pragma once
class GameObject : public IGameObject, public CTexture
{
private:
	bool		_Enable;
	bool		_AlphaEnable;
	char*		_Tag;
	float		_Rotation;

	D3DXVECTOR2 _Pos;
	D3DXVECTOR2 _Pivot;
	D3DXVECTOR2 _Scale;
	D3DXCOLOR	_Color;
public:
	GameObject();
	virtual ~GameObject();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();

	void Draw();

	bool GetEnable();
	void SetEnable(bool enable);

	bool GetAlphaEnable();
	void SetAlphaEnable(bool enable);

	char* GetTag();
	void SetTag(char* tag);

	float GetRotation();
	void SetRotation(float rotation);

	D3DXVECTOR2 GetPos();
	void SetPos(D3DXVECTOR2 pos);
	void SetPos(float x, float y);

	float GetPosX();
	float GetPosY();
	void SetPosX(float x);
	void SetPosY(float y);

	D3DXVECTOR2 GetPivot();
	void SetPivot(D3DXVECTOR2 pivot);
	void SetPivot(float x, float y);

	D3DXVECTOR2 GetScale();
	void SetScale(D3DXVECTOR2 scale);
	void SetScale(float x, float y);
};


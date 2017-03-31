#pragma once
class AnimationObject : public GameObject
{
private:
	INT		m_CurFrame;
	INT		m_MaxFrame;

	FLOAT	m_AnimSpeed;
	CTexture* m_pAnimation;

	bool	m_isStop;
	bool	m_isLoop;

	DWORD	m_dBeginTime;
public:
	AnimationObject();
	virtual ~AnimationObject();

	virtual INT Update();
	virtual VOID Destroy();

	INT LoadAnimation(char* sFile, int maxFrame, float animSpeed);
	VOID UpdateFrame();
};


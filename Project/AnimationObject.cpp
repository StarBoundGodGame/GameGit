#include "_StdAfx.h"


AnimationObject::AnimationObject()
{
	m_CurFrame = 0;
	m_MaxFrame = 0;

	m_AnimSpeed = 0.3f;
	m_pAnimation = NULL;

	m_isStop = FALSE;
	m_isLoop = TRUE;
}


AnimationObject::~AnimationObject()
{
}

INT AnimationObject::Update()
{
	UpdateFrame();
	return 0;
}

VOID AnimationObject::Destroy()
{
	SAFE_DELETE_ARRAY(m_pAnimation);
}
INT AnimationObject::LoadAnimation(char* sFile, int maxFrame, float animSpeed)
{
	m_pAnimation = new CTexture[maxFrame];

	char buffer[128];
	for (int i = 1; i <= maxFrame; ++i)
	{
		sprintf_s(buffer, "%s (%d).png", sFile, i);
		if (FAILED(m_pAnimation[i - 1].Create(buffer)))
		{
			MessageBox(NULL, "Animation Load Failed", NULL, NULL);
			return -1;
		}
	}

	m_MaxFrame = maxFrame;
	m_AnimSpeed = animSpeed;
	return 0;
}

VOID AnimationObject::UpdateFrame()
{
	if (!m_isStop)
	{
		DWORD dCurTime = timeGetTime();
		if (dCurTime - m_dBeginTime >= m_AnimSpeed * 1000)
		{
			SetTexture(m_pAnimation[m_CurFrame].GetTexture(), m_pAnimation[m_CurFrame].GetImageInfo());
			++m_CurFrame;
			if (m_CurFrame >= m_MaxFrame)
			{
				if (m_isLoop)
					m_CurFrame = 0;
				else
					m_isStop = TRUE;

			}
			m_dBeginTime = timeGetTime();
		}
	}
}
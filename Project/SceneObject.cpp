#include "_StdAfx.h"

CSceneObject* CSceneObject::m_NowOpend = NULL;
CSceneObject* CSceneObject::m_PrevOpend = NULL;

CSceneObject::CSceneObject()
{
}


CSceneObject::~CSceneObject()
{
}

void CSceneObject::Open()
{
	if (m_NowOpend)
		m_NowOpend->Close();

	if (m_PrevOpend)
		m_PrevOpend->Close();

	m_NowOpend = this;
}

void CSceneObject::PopUpOpen()
{
	if (m_NowOpend)
		m_PrevOpend = m_NowOpend;

	m_NowOpend = this;
}

void CSceneObject::Prev_Open()
{
	if (m_PrevOpend)
		m_NowOpend->Close();

	m_NowOpend = m_PrevOpend;
	m_PrevOpend = NULL;
}

INT CSceneObject::Init()
{
	return 0;
}

INT CSceneObject::Update()
{
	return 0;
}

INT CSceneObject::Render()
{
	return 0;
}
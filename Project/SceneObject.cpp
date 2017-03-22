#include "StdAfx.h"

CSceneObject* CSceneObject::m_NowOpend = NULL;
CSceneObject* CSceneObject::m_PrevOpen = NULL;

CSceneObject::CSceneObject()
{
}


CSceneObject::~CSceneObject()
{
}

void CSceneObject::Open()
{
	if (m_NowOpend != NULL)
		m_NowOpend->Close();

	if (m_PrevOpen != NULL)
		m_PrevOpen->Close();

	m_NowOpend = this;
	m_PrevOpen = NULL;
}


void CSceneObject::Prev_Open()
{
	if (m_NowOpend != NULL)
		m_NowOpend->Close();
	m_NowOpend = m_PrevOpen;
	m_PrevOpen = NULL;
}

void CSceneObject::PopUpOpen()
{
	if (m_NowOpend != NULL)
		m_PrevOpen = m_NowOpend;
	m_NowOpend = this;
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
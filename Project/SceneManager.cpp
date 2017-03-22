#include "StdAfx.h"

int CSceneManager::NowSceneNum = 0;
std::map <int, CSceneObject*> CSceneManager::m_SceneMap;
CSceneManager* CSceneManager::instance;

CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

void CSceneManager::AddScene(int num, CSceneObject* pScene)
{
	if (pScene != NULL)
		m_SceneMap.insert(std::map <int, CSceneObject*>::value_type(num, pScene));
}

void CSceneManager::RemoveAll()
{
	std::map<int, CSceneObject*>::iterator it = m_SceneMap.begin();

	for (; it != m_SceneMap.end();)
	{
		SAFE_DELETE(it->second);
		m_SceneMap.erase(it++);
	}
	m_SceneMap.clear();
}

CSceneObject* CSceneManager::GetNowOpendScene()
{
	std::map<int, CSceneObject*>::iterator it = m_SceneMap.find(NowSceneNum);
	
	if (it != m_SceneMap.end())
		return it->second;
	else
		return NULL;
}

CSceneObject* CSceneManager::GetScene(int num)
{
	std::map<int, CSceneObject*>::iterator it = m_SceneMap.find(num);

	if (it != m_SceneMap.end())
	{
		NowSceneNum = num;
		return it->second;
	}
	else
		return NULL;
}

CSceneManager* CSceneManager::GetInstance()
{
	if (instance == NULL)
		instance = new CSceneManager;
	return instance;
}
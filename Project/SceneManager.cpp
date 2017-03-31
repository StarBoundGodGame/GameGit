#include "_StdAfx.h"

int CSceneManager::NowSceneNum = 0;
CSceneManager* CSceneManager::_instance = NULL;
std::map<int, CSceneObject*>  CSceneManager::m_SceneMap;

CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

void CSceneManager::AddScene(int num, CSceneObject* scene)
{
	m_SceneMap.insert(std::map<int, CSceneObject*>::value_type(num, scene));
}

void CSceneManager::RemoveAll()
{
	auto it = m_SceneMap.begin();

	while (it != m_SceneMap.end())
	{
		SAFE_DELETE(it->second);
		m_SceneMap.erase(it++);
	}
	m_SceneMap.clear();
}

CSceneObject* CSceneManager::NowOpendScene()
{
	auto it = m_SceneMap.find(NowSceneNum);

	if (it != m_SceneMap.end())
		return it->second;
	else
		return NULL;
}

CSceneObject* CSceneManager::GetScene(int num)
{
	auto it = m_SceneMap.find(num);

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
	if (_instance == NULL)
		_instance = new CSceneManager;
	return _instance;
}
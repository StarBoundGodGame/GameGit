#pragma once
#include <map>
class CSceneManager
{
private:
	static std::map <int, CSceneObject*> m_SceneMap;
	static int NowSceneNum;
	static CSceneManager* instance;
	CSceneManager();
public:
	~CSceneManager();

	void AddScene(int num, CSceneObject* pScene);
	void RemoveAll();

	CSceneObject* GetNowOpendScene();
	CSceneObject* GetScene(int num);

	static CSceneManager* GetInstance();
};


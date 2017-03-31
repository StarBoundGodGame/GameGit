#pragma once
#include <map>
class CSceneManager
{
private:
	static int NowSceneNum;
	static CSceneManager* _instance;
	static std::map<int, CSceneObject*> m_SceneMap;
public:
	CSceneManager();
	~CSceneManager();

	void AddScene(int num, CSceneObject* scene);
	void RemoveAll();

	CSceneObject* NowOpendScene();
	CSceneObject* GetScene(int num);

	static CSceneManager* GetInstance();
};


#pragma once
class SceneIntro : public CSceneObject
{
public:

public:
	SceneIntro();
	~SceneIntro();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual VOID Close();
};


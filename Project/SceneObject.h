#pragma once
class CSceneObject
{
private:
	static CSceneObject* m_NowOpend;
	static CSceneObject* m_PrevOpend;
public:
	CSceneObject();
	~CSceneObject();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual VOID Close() = 0;

	void Open();
	void PopUpOpen();
	void Prev_Open();
};


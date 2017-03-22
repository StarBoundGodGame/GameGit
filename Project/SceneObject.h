#pragma once
class CSceneObject
{
public:
	static CSceneObject* m_NowOpend;
	static CSceneObject* m_PrevOpen;
public:
	CSceneObject();
	virtual ~CSceneObject();

	virtual void Open();
	virtual void Prev_Open();
	virtual void PopUpOpen();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual VOID Close() = 0;
};


#pragma once
class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	virtual INT Init() = 0;
	virtual INT Update() = 0;
	virtual INT Render() = 0;
};


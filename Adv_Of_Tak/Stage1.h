#pragma once
#include "Scene.h"
class Stage1 : public Scene
{
public:
	Stage1();
	Stage1(stack<Scene*>* stage1);
	virtual ~Stage1();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};


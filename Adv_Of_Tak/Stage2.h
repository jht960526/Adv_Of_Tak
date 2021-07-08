#pragma once
#include "Scene.h"
class Stage2 : public Scene
{
public:
	Stage2();
	Stage2(stack<Scene*>* stage2);
	virtual ~Stage2();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};


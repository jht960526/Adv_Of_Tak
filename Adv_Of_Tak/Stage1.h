#pragma once
#include "Scene.h"
class Stage1 : public Scene
{
public:
	Stage1();
	Stage1(stack<Scene*>* scense, RenderWindow* window);
	virtual ~Stage1();

private:
	virtual void Init();

public:
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};


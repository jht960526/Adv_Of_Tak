#pragma once
#include "Scene.h"
class Title : public Scene
{
public:
	Title();
	Title(stack<Scene*>* scenes, RenderWindow* window);
	~Title();

private:
	virtual void Init();
	Texture* texture = nullptr;

public:

	virtual void Destroy();

	virtual void Input(Event* e);

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
};


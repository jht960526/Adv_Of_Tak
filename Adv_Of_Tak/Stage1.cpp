#include "framework.h"
#include "Stage1.h"
#include "MainCharacter.h"

Stage1::Stage1()
{
	Init();
}

Stage1::Stage1(stack<Scene*>* scense) : Scene(scense)
{
	Init();
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	vObjects.push_back(new MainCharacter);
}

void Stage1::Update(const float& deltaTime)
{
	Scene:Update(deltaTime);
}

void Stage1::Render(RenderWindow* window)
{
	Scene::Render(window);
}

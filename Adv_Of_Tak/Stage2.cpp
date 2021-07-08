#include "framework.h"
#include "Stage2.h"
#include "MainCharacter.h"
#include "ProfObject1.h"

Stage2::Stage2()
{
	Init();
}

Stage2::Stage2(stack<Scene*>* stage2)
{
	Init();
}

Stage2::~Stage2()
{
}

void Stage2::Init()
{
	vObjects.push_back(new MainCharacter);
	vObjects.push_back(new ProfObject1);
}

void Stage2::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void Stage2::Render(RenderWindow* window)
{
	Scene::Render(window);
}

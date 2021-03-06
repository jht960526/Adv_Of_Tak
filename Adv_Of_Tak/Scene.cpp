#include "framework.h"
#include "Scene.h"
#include "Object.h"
#include "ProfObject1.h"
#include "MainCharacter.h"
Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window)
{
	Init();
}

Scene::~Scene()
{
}

void Scene::Init()
{
	
}

bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Update(const float& deltaTime)
{
	for(auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for(auto& obj : vObjects)
	{
		window->draw(*obj);
	}

	for(auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}

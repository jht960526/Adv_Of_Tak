#include "framework.h"
#include "Title.h"
#include "BackGroundObject.h"

Title::Title()
{
	Init();
}

Title::Title(stack<Scene*>* scenes, RenderWindow* window) : Scene(scenes,window)
{
	Init();
}

Title::~Title()
{
}

void Title::Init()
{
	vObjects.push_back(new BackGroundObject("Textures/MainBackGround/Adventure_Of_Tak_Main.PNG"));
	cout << "title create" << endl;
}

void Title::Destroy()
{
}

void Title::Input(Event* e)
{
}

void Title::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void Title::Render(RenderWindow* window)
{
	Scene::Render(window);
}

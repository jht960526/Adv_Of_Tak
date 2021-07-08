#include "framework.h"
#include "MainCharacter.h"

MainCharacter::MainCharacter()
{
	Init();
}

MainCharacter::~MainCharacter()
{
}

void MainCharacter::Init()
{
	Texture* tx = nullptr;

	char filePath[50];
	for(int i = 2; i < 7; ++i)
	{
		sprintf(filePath, "Textures/Naruto/naruto_idle_00%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	setPosition(Vector2f(100.f,300.f));
	cout << "생성 나루토" << endl;
}

void MainCharacter::Destroy()
{
	AnimationObject::Destroy();
}

void MainCharacter::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}

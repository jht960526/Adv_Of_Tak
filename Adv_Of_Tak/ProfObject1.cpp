#include "framework.h"
#include "ProfObject1.h"

ProfObject1::ProfObject1()
{
	Init();
}

ProfObject1::~ProfObject1()
{
}

void ProfObject1::Init()
{
	Texture* tx = nullptr;

	char filePath[50];

	for(int i = 1; i < 6; ++i)
	{
		sprintf(filePath,"Textures/Naruto/kakashi_idle%d.png",i);

		tx = new Texture;
	    tx->loadFromFile(filePath);
	    this->vAnimation.push_back(tx);
	}
	
	setPosition(Vector2f(100.f,100.f));
}

void ProfObject1::Destroy()
{
	AnimationObject::Destroy();
}

void ProfObject1::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}

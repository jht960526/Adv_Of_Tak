#include "framework.h"
#include "ProfObject2.h"

ProfObject2::ProfObject2()
{
	Init();
}

ProfObject2::~ProfObject2()
{
}

void ProfObject2::Init()
{
	Texture* tx = nullptr;

	char filePath[50];

	for(int i = 1; i < 7; ++i)
	{
		sprintf(filePath,"Textures/Naruto/ougar_idle_0%d.png",i);

		tx = new Texture;
	    tx->loadFromFile(filePath);
	    this->vAnimation.push_back(tx);
	}
	
	setPosition(Vector2f(100.f,100.f));
}

void ProfObject2::Destroy()
{
}

void ProfObject2::Update(const float& deltaTime)
{
}

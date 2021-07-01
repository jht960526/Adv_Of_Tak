#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

AnimationObject::~AnimationObject()
{
}

void AnimationObject::Init()
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
}

void AnimationObject::Destroy()
{
}

void AnimationObject::Update(const float& deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime > 0.05f)
	{
		setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
		++keyFrame;
		elapsedTime = 0.f;
	}
}

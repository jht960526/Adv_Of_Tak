#pragma once
#include "AnimationObject.h"
class MainCharacter : public AnimationObject
{
public:
	MainCharacter();
	virtual ~MainCharacter();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};


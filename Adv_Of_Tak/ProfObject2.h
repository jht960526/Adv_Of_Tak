#pragma once
#include "AnimationObject.h"
class ProfObject2 : public AnimationObject
{
public:

	ProfObject2();
	virtual ~ProfObject2();

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};


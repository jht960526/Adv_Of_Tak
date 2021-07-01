#pragma once

#include "AnimationObject.h"

class ProfObject1 : public AnimationObject
{
public:

	ProfObject1();
	virtual ~ProfObject1();


private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);
};


#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	RUN,
	DASH,
	JUMP,
	DOUBLEJUMP,
	SKILL
};
class MainCharacter : public AnimationObject
{
public:
	MainCharacter();
	virtual ~MainCharacter();

private:

	vector<Texture*> runAnimation;
	vector<Texture*> dashAnimation;
	vector<Texture*> jumpAnimation;
	vector<Texture*> doubleAnimation;
	vector<Texture*> skillAnimation;
	vector<Texture*> idleAnimation;

	int state = IDLE;

	map<int, vector<Texture*>> stateAnimation;
	float frameTime = 0.2f;
	unsigned int keyFrame = 0;
	float speed = 10.f;

	int mainCharacterState = IDLE;

private:

	virtual void Init();

public:

	virtual void Destroy();

	virtual void Update(const float& deltaTime);

	void Jump();
	void MoveUpdate(const float& deltaTime);
	void SetState(const int& state);
	int GetState();

};


#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	LEFTIDLE,
	RIGHTIDLE,
	RUN,
	LEFTRUN,
	RIGHTRUN,
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
	vector<Texture*> leftIdleAnimation;
	vector<Texture*> rightIdleAnimation;
	vector<Texture*> leftRunAnimation;
	vector<Texture*> rightRunAnimation;

	int state = IDLE;

	map<int, vector<Texture*>*> stateAnimation;
	float frameTime = 0.1f;
	unsigned int keyFrame = 0;
	float speed = 15.f;

	int oldState = IDLE;
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


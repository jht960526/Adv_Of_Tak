#pragma once
#include "Object.h"


class SkillObject :  public Object
{
public:
	SkillObject() = delete;
	SkillObject(const string& texttureFilePath);
	SkillObject(const SkillObject&) = delete;
	SkillObject& operator=(const SkillObject&) = delete;
	virtual ~SkillObject() = default;

private:

	Vector2f dir{0.f, 0.f};
	float speed = 0.f;


	virtual void Init();

public:

	virtual void Destroy();

	void SetDirection(const Vector2f& dir);
	void SetSpeed(const float& speed);

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);

	virtual void Render(RenderTarget* target);
};


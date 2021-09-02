#include "framework.h"
#include "SkillObject.h"

SkillObject::SkillObject(const string& texttureFilePath) : Object(texttureFilePath)
{

}

void SkillObject::Init()
{

}

void SkillObject::Destroy()
{
	Object::Destroy();
}

void SkillObject::SetDirection(const Vector2f& dir)
{
	this->dir = dir;
}

void SkillObject::SetSpeed(const float& speed)
{
	this->speed = speed;
}

void SkillObject::Update(const float& deltaTime)
{
	Object::Update(deltaTime);
	move(dir * speed * deltaTime);
}

void SkillObject::Update(const Vector2f& mousePosition)
{

}

void SkillObject::Render(RenderTarget* target)
{
	Object::Render(target);
}

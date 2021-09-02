#include "framework.h"
#include "MainCharacter.h"
#include "SkillObject.h"


MainCharacter::MainCharacter()
{
	Init();
}

MainCharacter::~MainCharacter()
{
}

void MainCharacter::Init()
{
	Texture* tx = nullptr;
	//naSun = new SkillObject("");

	char filePath[100];

	for(int i = 1; i < 5; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_idle_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->idleAnimation.push_back(tx);
	}

	for(int i = 1; i < 5; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_idle_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->rightIdleAnimation.push_back(tx);
	}

	for(int i = 1; i < 5; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_reidle_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->leftIdleAnimation.push_back(tx);
	}

	for(int i = 2; i < 7; ++i)
	{
		sprintf(filePath, "Textures/Naruto/naruto_idle_00%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->rightRunAnimation.push_back(tx);
	}

	for(int i = 1; i < 7; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_rerun_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->leftRunAnimation.push_back(tx);
	}

	for(int i = 1; i < 7; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_jump_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->jumpAnimation.push_back(tx);
	}
	
	// run
	stateAnimation[RUN] = &runAnimation;
	stateAnimation[LEFTRUN] = &leftRunAnimation;
	stateAnimation[RIGHTRUN] = &rightRunAnimation;

	//stateAnimation[DASH] = &runAnimation;

	// jump
	stateAnimation[JUMP] = &jumpAnimation;
	stateAnimation[DOUBLEJUMP] = &doubleAnimation;
	
	// skill
	stateAnimation[SKILL] = &skillAnimation;

	// idle
	stateAnimation[IDLE] = &idleAnimation;
	stateAnimation[LEFTIDLE] = &leftIdleAnimation;
	stateAnimation[RIGHTIDLE] = &rightIdleAnimation;

	setScale(1.8f,1.8f);
	setPosition(Vector2f(100.f,300.f));
	cout << "생성 나루토``" << endl;


}

void MainCharacter::Destroy()
{
	AnimationObject::Destroy();
}

void MainCharacter::Update(const float& deltaTime)
{
	//AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;
	MoveUpdate(deltaTime);

	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		mainCharacterState = JUMP;
		Jump();
		cout << "jump" << endl;
	}

	/*else if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		mainCharacterState = RUN;
		move({0.f,1.f});
	}*/

	else if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		mainCharacterState = RIGHTRUN;
		position += {1.f,0.f};
	}

	else if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		mainCharacterState = LEFTRUN;
		position -= {1.f,0.f};
	}

	else if(Keyboard::isKeyPressed(Keyboard::Z))
	{

	}

	//if(shootTimer < 3)
	//	shootTimer++;

	//else if(Keyboard::isKeyPressed(Keyboard::X) && shootTimer >= 3)
	//{
	//	shootTimer = 0;
	//	//projectiles.setposition(playerCenter);
	//}

	else
	{
		mainCharacterState = IDLE;
	}
	
	if(elapsedTime >= frameTime)
	{
		for(auto& animation : stateAnimation)
		{
			if(animation.first == mainCharacterState)
			{
				setTexture(*animation.second->data()[keyFrame % animation.second->size()]);
				
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}

void MainCharacter::Jump()
{
	//if(--jumpCount > 0)
	//{
		velocity.y = -5.f;

	//}
}

void MainCharacter::MoveUpdate(const float& deltaTime)
{
	if(position.y < 500.f )
	{
		velocity.y += gravity * speed * deltaTime;
	}
	else if(position.y > 500)
	{
		position.y = 500;
	}
	
	velocity += acceleration * speed * deltaTime;

	position += velocity;

	setPosition(position);

}

void MainCharacter::SetState(const int& state)
{
}

int MainCharacter::GetState()
{
	return 0;
}

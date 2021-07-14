#include "framework.h"
#include "MainCharacter.h"

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
	
	char filePath[100];

	for(int i = 1; i < 5; ++i)
	{
		sprintf(filePath, "Textures/Naruto/narutomoving/naruto_idle_0%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->idleAnimation.push_back(tx);
	}

	for(int i = 2; i < 7; ++i)
	{
		sprintf(filePath, "Textures/Naruto/naruto_idle_00%d.png",i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runAnimation.push_back(tx);
		//this->vAnimation.push_back(tx);
	}
	
	stateAnimation[RUN] = &runAnimation;
	//stateAnimation[DASH] = runAnimation;
	stateAnimation[JUMP] = &jumpAnimation;
	stateAnimation[DOUBLEJUMP] = &doubleAnimation;
	stateAnimation[SKILL] = &skillAnimation;
	
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
	AnimationObject::Update(deltaTime);

	static float elapsedTime = 0.f;
	elapsedTime += deltaTime;

	if(Keyboard::isKeyPressed(Keyboard::Up))
	{
		mainCharacterState = RUN;
		move({0.f,-1.f});
	}

	else if(Keyboard::isKeyPressed(Keyboard::Down))
	{
		mainCharacterState = RUN;
		move({0.f,1.f});
	}

	else if(Keyboard::isKeyPressed(Keyboard::Right))
	{
		mainCharacterState = RUN;
		move({1.f,0.f});
	}

	else if(Keyboard::isKeyPressed(Keyboard::Left))
	{
		mainCharacterState = RUN;
		move({-1.f,0.f});
	}
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
				oldState = animation.first;
			}
			else if(mainCharacterState == IDLE)
			{
				setTexture(*stateAnimation[oldState]->data()[1]);
			}
		}
		++keyFrame;
		elapsedTime = 0.f;
	}
}

void MainCharacter::Jump()
{
}

void MainCharacter::MoveUpdate(const float& deltaTime)
{
}

void MainCharacter::SetState(const int& state)
{
}

int MainCharacter::GetState()
{
	return 0;
}

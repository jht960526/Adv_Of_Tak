#include "framework.h"
#include "Engine.h"
#include "Stage1.h"
#include "MainCharacter.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	// 현재 window 변수는 포인터로 존재한다.

	this->window = new RenderWindow(VideoMode(500,500),"Window");
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Textures/미네랄2.jpg");
	window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

	this->scenes.push(new Scene);

}

void Engine::Destroy()
{
	// 윈도우가 nullptr이 아니라면
	if(window)
	{
		delete window;
	}
}

void Engine::Input()
{
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}

		case Event::KeyPressed:
		{
			switch (evt.key.code)
			{
			case Keyboard::A:
			{
				this->scenes.push(new Stage1);
				cout << "Stage1 !!\n";
				break;
			}
			case Keyboard::Q:
			{
				scenes.top()->EndScene();
				break;
			}
			
			default:
				break;
			}
		}
		default:
			break;
		}
	}

	// KeyBoardInput
	if(Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window->close();
	}

	// Mouse Input
	if(Mouse::isButtonPressed(Mouse::Left))
	{
		window->setTitle("Left Click");
	}

	else if(Mouse::isButtonPressed(Mouse::Right))
	{
		window->setTitle("Right Click");
	}

	else
	{
		window->setTitle("window");
	}
}

void Engine::Update()
{
	
	deltaTime = timer.getElapsedTime().asSeconds();
	timer.restart();
	Input();
	if(!scenes.empty())
	{
		scenes.top()->Update(deltaTime);

		if(this->scenes.top()->GetQuit())
		{
			//현재 실행중인 씬 종료한다.
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else
	{
		window->close();
	}
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		if(!scenes.empty())
		{
			scenes.top()->Render(window);
		}
		window->display();
	}
}

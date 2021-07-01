#include "framework.h"
#include "Engine.h"


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

		default:
			break;
		}
	}

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
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();
		window->display();
	}
}

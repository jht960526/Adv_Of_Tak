#include "framework.h"
#include "Engine.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Title.h"

Engine::Engine()
{
	Init();
}

Engine::~Engine()
{
}

void Engine::Init()
{
	// ���� window ������ �����ͷ� �����Ѵ�.

	this->window = new RenderWindow(VideoMode(1061,640),"Adventure Of Tak");
	window->setMouseCursorVisible(true);
	Image icon;
	icon.loadFromFile("Textures/MainBackGround/Adventure_Of_Tak_Main.PNG");
	window->setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

	this->scenes.push(new Title(&scenes,window));

}

void Engine::Destroy()
{
	// �����찡 nullptr�� �ƴ϶��
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

			case Keyboard::S:
			{
				this->scenes.push(new Stage2);
				cout << "Stage2 !!\n";
				break;
			}
			case Keyboard::E:
			{
				scenes.top()->EndScene();
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
			//���� �������� �� �����Ѵ�.
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

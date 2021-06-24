#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(500,500),"WINDOW");
	window.setFramerateLimit(60);

	IntRect txSq(0, 0, 319/3, 424/4);
	// 319 x 424
	Texture tx;
	tx.loadFromFile("Textures/dragonFrames.png");

	Sprite sp(tx,txSq);
	sp.setScale(3.f,3.f);

	Clock clock;

	while (window.isOpen())
	{
		window.clear();

		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
			{
				// 윈도우를 종료한다.
				window.close();
				break;
			}
			default:
				break;
			}
		}

		if(clock.getElapsedTime().asMilliseconds() >=  0.3f)
		{
			if(txSq.left >= 318 - 106)
			{
				txSq.left = 0;
			}
			else
			{
				txSq.left += 319 / 3;
			}
			sp.setTextureRect(txSq);
			clock.restart();
		}

		window.draw(sp);
		window.display();

	}
}
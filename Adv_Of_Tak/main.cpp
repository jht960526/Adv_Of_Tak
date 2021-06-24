#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(500,500),"WINDOW");

	// 절대 사이즈가 없다.
	// Scaling
	// texture의 사이즈를 그대로 가져오기 때문에
	// 이를 배수를 곱해서 줄이거나 늘릴 수 있음
	Sprite sp;
	Texture tx;
	tx.loadFromFile("Textures/미네랄2.jpg");

	sp.setScale(0.5f,0.5f);
	sp.setTexture(tx);
	sp.setOrigin(tx.getSize().x/2.f,tx.getSize().y/2.f);
	sp.setPosition(250.f,250.f);

	while (window.isOpen())
	{
		window.clear();

		window.draw(sp);
	
		window.display();
	}
}
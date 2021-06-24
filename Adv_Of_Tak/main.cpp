#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(500,500),"WINDOW");

	// ���� ����� ����.
	// Scaling
	// texture�� ����� �״�� �������� ������
	// �̸� ����� ���ؼ� ���̰ų� �ø� �� ����
	Sprite sp;
	Texture tx;
	tx.loadFromFile("Textures/�̳׶�2.jpg");

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
#include <SFML/Graphics.hpp>
#include "Entity.h"
using namespace sf;
	Entity::Entity(Image &image, float X, float Y, int W, int H, std::string Name){ 
		x = X; y = Y; //���������� ��������� �������
		w = W; h = H;
		dx = 0; dy = 0; speed = 0;
		CurrentFrame = 0;
		health = 100; life = true; //���������������� ���������� ���������� �����, ����� ���
		texture.loadFromImage(image); //������� ���� ����������� � �������� 
		sprite.setTexture(texture); //�������� ������ ��������� 
	}

	FloatRect Entity:: getRect(){
		//����� ��������� ��������������. ��� �����, ������� (���,�����).
		FloatRect FR(x, y, w, h); // ���������� FR ���� FloatRect
		return FR; //��� ������ (�����) "sf::FloatRect" ��������� ������� ������ ���������� �������������� 
		//� ����� ���� ��� ���������� �������� ������������ ����� �� ����� 
		//����� ��� �������� ��������, ���� �� ��� �����-���� ���� �� ���� ����� //��� �-��� ����� ��� �������� ����������� 
	}


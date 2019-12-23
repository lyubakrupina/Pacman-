#ifndef __ENEMY__ 
#define __ENEMY__
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "map.h" //���������� ��� � ������
using namespace sf;

class Enemy:public Entity { 
public:

	int direction;
	
	Enemy(Image &image, float X, float Y, int W, int H, std::string Name);
		
	
	
	//����� �������� ������������ � ���������� ����� 
	void checkCollisionWithMap(float Dx, float Dy);
	

	void update(float time); //����� "���������/����������" ������� ������.
};
#endif // __ENTITY_H__
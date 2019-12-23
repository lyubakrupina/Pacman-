#ifndef __BULLET_H__ 
#define __BULLET_H__
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Enemy.h"
#include "Entity.h"
#include "map.h" //���������� ��� � ������
using namespace sf;

////////////////////////////����� ����//////////////////////// 
class Bullet :public Entity
{//����� ���� 
public: 
	
	int direction;//����������� ���� //�� ��� ��, ������ ����� � ����� ��������� ������ (int dir) //��� ������� ����������� ����� ���� 
	
	Bullet(Image &image, float X, float Y, int W, int H, std::string Name, int dir) ;
	
		void update(float time) ;
};
#endif // __BULLET_H__
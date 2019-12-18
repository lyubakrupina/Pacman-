#ifndef __PACMAN_H__ 
#define __PACMAN_H__
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "map.h" //���������� ��� � ������
using namespace sf;

///////////////////////////����� Pacman//////////////////////// 
////////////////////////////////////////////////////����� Pacman///////////////////////
class Pacman:public Entity { // ����� Pacman
public:
	int playerScore;//��� ���������� ����� ���� ������ � ������

	Pacman(Image &image, float X, float Y, int W, int H, std::string Name);
		
	void control();
	
	//����� �������� ������������ � ���������� ����� 
	void checkCollisionWithMap(float Dx, float Dy);
	

	void update(float time); //����� "���������/����������" ������� ������.
};
#endif // __ENTITY_H__
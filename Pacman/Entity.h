#ifndef __ENTITY_H__ 
#define __ENTITY_H__
#include <SFML/Graphics.hpp>

using namespace sf;

////////////////////////////����� ��������//////////////////////// 
class Entity {
public: 
	enum { left, right, up, down, stay} state;// ��� ������������ - ��������� �������
	float dx, dy, x, y, speed;
	int w, h, health; //���������� �health�, �������� ����� ������
	bool life; //���������� �life� �����, ����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	float CurrentFrame;//������ ������� ����
	std::string name;//����� ����� ���� ������, ������ ����� ��������� �� ������ 
	//������� ����� ���� ���� �������� � update() � ����������� �� �����

	Entity(Image &image, float X, float Y, int W, int H, std::string Name);

	FloatRect getRect();
	virtual void update(float time) = 0;
};
#endif // __ENTITY_H__
#include <SFML/Graphics.hpp>
#include "Pacman.h"
using namespace sf;

		Pacman::Pacman(Image &image, float X, float Y, int W, int H, std::string Name) :Entity(image, X, Y, W, H, Name){
		playerScore = 0; state = stay;
		//if (name == "Packman"){ 
			//������ ������� ���� ������������� ��� //������ ������ ������. IntRect � ��� ���������� ����� 
			//image.createMaskFromColor(Color(255, 255, 255));
		//image.createMaskFromColor(Color(0, 0, 0));
		sprite.setTextureRect(IntRect(0, 0, w, h)); 
			//sprite.setTextureRect(IntRect(0, 0, 40, 40));//�������� ������ �������������
			
		//}
	}
		
	void 	Pacman::control(){
		/////////////////////////////���������� ���������� � ���������///////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{ 
			state = left;
			speed = 0.1;
		}
		//���������� Y, �� ������� ����� ��������� ������ ������ ����� 0
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{ 
			state = right;
			speed = 0.1;
		}
		//���������� Y �� ������� ����� ��������� ������ ����� ����� 80
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			state = up;
			speed = 0.1;//����������� �����
		}
		//���������� 0, ��� ������� ����� ����������� � ������, �� ��� � ������������� 
		//������� ������������ �� 40.
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			state = down;
			speed = 0.1;//����������� ����
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down))&(Keyboard::isKeyPressed(Keyboard::Left)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down))&(Keyboard::isKeyPressed(Keyboard::Right)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;

		}
		if ((Keyboard::isKeyPressed(Keyboard::Up))&(Keyboard::isKeyPressed(Keyboard::Left)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;

		}
		if ((Keyboard::isKeyPressed(Keyboard::Up))&(Keyboard::isKeyPressed(Keyboard::Right)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;

		}
		if ((Keyboard::isKeyPressed(Keyboard::Down))&(Keyboard::isKeyPressed(Keyboard::Up)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))&(Keyboard::isKeyPressed(Keyboard::Left)))
		{
			state = stay;
			speed = 0;
			dx=0;
			dy=0;
		}
	}
	
	//����� �������� ������������ � ���������� ����� 
	void 	Pacman::checkCollisionWithMap(float Dx, float Dy) {
		for (int i = y / 40; i < (y + h) / 40; i++) 
			for (int j = x / 40; j<(x + w) / 40; j++)
			{
				//�x� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������.
				//�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ������ 
				//����� ����, j<(x + w)/32 - ������� ����������� ��������� �� �x�, �.�. ���������� ������ 
				//������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� 
				// ������� �� ����, ������� �� ������ �������� (���������������� � ������), �� ������� 
				// �������� (���������������� � ������)
				if ((TileMap[i][j] == '0') || (TileMap[i][j] == 's'))//���� ��� ��������� ������������� ������� �0� 
					//(�����), �� ��������� "����������� ��������" ���������: 
				{ 
					if (Dy>0)
					{
						//���� �� ��� ����,
						y = i * 40 - h;//�� �������� (-h) ���������� �y� ���������.
						//������� �������� ���������� �i� ������ ���������� �� ����� �
						//����� �������� �� ������ ������� ���������.
						dy = 0;
					}
					if (Dy<0)
					{ 
						y = i * 40 + 40;//���������� � ��������� �����.
						dy = 0;
					}
					if (Dx>0)
					{ 
						x = j * 40 - w;//���� ���� ������, �� ���������� �x� ����� 
						//����� (������ 0) ����� ������ ��������� 
						dx = 0;
					}
					if (Dx < 0)
					{ 
						x = j * 40 + 40; //���������� ���� �����
						dx = 0;
					}
								
					
				}
				if (TileMap[i][j] == 'f')//��������
				{
					TileMap[i][j] = ' ';
				}
				if (TileMap[i][j] == 'h')//����� 
				{
					TileMap[i][j] = ' ';
				}
			}
	}
	

	void 	Pacman::update(float time) //����� "���������/����������" ������� ������.
	{
		control();//������� ���������� ���������� 
		switch (state)//�������� ��������� �������� � ����������� �� ��������� 
		{
			case right: 
				{
					dx = speed; 
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3;
					//�������� �� ����������� �. ���������� 0
					sprite.setTextureRect(IntRect(40* int(CurrentFrame), 0, 40, 40));
					break; 
				}
			case left:
				{//��������� ���� �����
					 dx = -speed;
					 CurrentFrame += 0.005*time;
					//������ ��� ����������� �� "������". ���������� ������� �� ����, �������� ������������
					//������� � ��������. ������� 0.005, ����� �������� �������� ��������
					if (CurrentFrame > 3) CurrentFrame -= 3; //���� ������ � �������� ����� ������������ �����. 
					sprite.setTextureRect(IntRect(40* int(CurrentFrame), 40, 40, 40)); 
					break; 
				}
			case up:
				{//���� �����
					dy = -speed; 
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3;
					sprite.setTextureRect(IntRect(40* int(CurrentFrame), 80, 40, 40));
					//�������� �� ����������� �. ���������� 80,0*2,80*3 � ����� 80
					break;
				}
			case down:
				{//���� ����
					dy = speed;
					CurrentFrame += 0.005*time; 
					if (CurrentFrame > 3) CurrentFrame -= 3;
					sprite.setTextureRect(IntRect(40* int(CurrentFrame), 120, 40, 40));
					break;
				}
			case stay:
				{//����� 	
					dy = speed; dx = speed;
					break;
				}
			
		}
		
		x += dx*time; //�������� �� �X� 
		checkCollisionWithMap(dx, 0);//������������ ������������ �� �
		y += dy*time; //�������� �� �Y� 
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y
		speed = 0; //�������� ��������, ����� �������� �����������. 
		sprite.setPosition(x, y); //������� ������ � ������� (x, y). 
			//���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	}
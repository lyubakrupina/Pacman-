#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <iostream>
using namespace sf;
using namespace std;

	Enemy::Enemy(Image &image, float X, float Y, int W, int H, std::string Name) :Entity(image, X, Y, W, H, Name){
		
		if (name == "EnemyImageSh1")
		{ 
			//������ ������� ���� ������������� ��� //������ ������ ������. IntRect � ��� ���������� ����� 
			//image.createMaskFromColor(Color(255, 255, 255));
		//image.createMaskFromColor(Color(0, 0, 0));
		
			sprite.setTextureRect(IntRect(0, 0, w, h)); 
			direction = rand() % (3);
			
			speed = 0.1;
			dx = speed;
		}
	}

	Enemy::~Enemy(){
		cout<<"udalilas vrag";
		system("pause");
		}

	void Enemy::checkCollisionWithMap (float Dx, float Dy)
	{
		for (int i = y / 40; i < (y + h) / 40; i++)//���������� �� ��������� �����    
			for (int j = x / 40; j<(x + w) / 40; j++) 
 
			{     
			if ((TileMap[i][j] == '0'))//���� ������� - ������ �����    
				{      if (Dy > 0) 
						{      
							y = i * 40 - h; 
							dy = -0.1;        
							direction = rand() % (3); //����������� �������� �����       
						}//�� Y       
					   if (Dy < 0) 
						{		
							y = i * 40 + 40; 
							dy = 0.1;        
							direction = rand() % (3);//����������� �������� �����        
						}//������������ � �������� ������       
					   if (Dx > 0) 
						{       
							x = j * 40 - w; 
							dx = -0.1;        
							direction = rand() % (3);//����������� �������� �����        
						}//� ������ ����� �����      
					   if (Dx < 0) 
						{       
							x = j * 40 + 40; 
							dx = 0.1;        
							direction = rand() % (3); //����������� �������� �����       
					   }// � ����� ����� �����     
				}   
			
		}  
	}
	void Enemy::update(float time)  
	{   
		//if (name == "EnemyImageSh1")
		//{//��� ��������� � ����� ������ ������ ����� ����� 
 
		//if (life) 
		//{//���������, ��� �� �����   
			switch (direction)//�������� ��������� �������� � ����������� �� ���������  
			
			{  
			case 0:
					{//��������� ���� ������   
						dx = speed;   
						CurrentFrame += 0.005*time;   
						if (CurrentFrame > 3) CurrentFrame -= 3;  
						sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 0, 40, 40));   
						break;  
					}   
				case 1:
					{//��������� ���� �����   
						dx = -speed;   
						CurrentFrame += 0.005*time;  
						if (CurrentFrame > 3) CurrentFrame -= 3;   
						sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 40, 40, 40));  
						break;   
					}   
				case 2:
					{//���� �����   
						dy = -speed;   
						CurrentFrame += 0.005*time;  
						if (CurrentFrame > 3) CurrentFrame -= 3;  
						sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 80, 40, 40)); 
						break;  
					}   
				case 3:
					{//���� ����  
						dy = speed;  
						CurrentFrame += 0.005*time;  
						if (CurrentFrame > 3) CurrentFrame -= 3;   
						sprite.setTextureRect(IntRect(40 * int(CurrentFrame), 120, 40, 40));  
						break;   
					}  
			} 
 


 x += dx*time; //�������� �� �X�   
 checkCollisionWithMap(dx, 0);//������������ ������������ �� � 
 
 y += dy*time; //�������� �� �Y� 
 checkCollisionWithMap(0, dy);//������������ ������������ �� Y 
 
 sprite.setPosition(x, y); //������ � ������� (x, y). 
 
// if (health <= 0)
	//{ 
		//life = false;
		//}//���� ������ ������ 0, ���� ����� 0, �� �������  
	//}  
	//	}
	} //����� Enemy ������ 
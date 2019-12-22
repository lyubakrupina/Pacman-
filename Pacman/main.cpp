#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Entity.h"
#include "Pacman.h"
#include "Enemy.h"
#include "map.h" //���������� ��� � ������
#include <list>
using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::

void randomMapGenerate(){
//�������� ����������� �����
int randomElementX = 0;//���������� ��� �������� ���������� �������� �� �����������
int randomElementY = 0;//���������� ��� �������� ���������� �������� �� ���������
srand(time(0));//������������� ���������� ��������� �����
int countStone = 3;//���������� ��������
while (countStone>0)
{ 
	randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������������� �������� �� �x� �� 1 �� 
//������ �����-1. ����������� ������� ����� �� �������� ����� ������� ����� 
randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� �y�
if (TileMap[randomElementY][randomElementX] == ' ') {
	//���� ��������� ������ ������, 
	TileMap[randomElementY][randomElementX] = 'h'; //�� ������ ���� ��������.
	countStone--; 
}
}
};


void randomMapGenerate1(){
//�������� ����������� �����
int randomElementX = 0;//���������� ��� �������� ���������� �������� �� �����������
int randomElementY = 0;//���������� ��� �������� ���������� �������� �� ���������
srand(time(0));//������������� ���������� ��������� �����
int countStone = 3;//���������� ��������
while (countStone>0)
{ 
	randomElementX = 1 + rand() % (WIDTH_MAP - 1);//��������������� �������� �� �x� �� 1 �� 
//������ �����-1. ����������� ������� ����� �� �������� ����� ������� ����� 
randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//�� �y�
if (TileMap[randomElementY][randomElementX] == ' ') {
	//���� ��������� ������ ������, 
	TileMap[randomElementY][randomElementX] = 'f'; //�� ������ ���� ��������.
	countStone--; 
}
}
};
				

int main() 
{
	//������ ���� 
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(800, 600, desktop.bitsPerPixel), "Pacman");

	//Font font;
	//font.loadFromFile("Cyrilicold.ttf");
	//Text text("",font,20);
	//text.setColor(Color::Red);//��������� ����� � ������� 
	//text.setStyle(Text::Bold);//������ �����. 
 
 


	Image map_image;//������ ����������� ��� ����� 
	map_image.loadFromFile("images/Lanshaft 555.png");//��������� ���� ��� �����
	
	Texture map;//�������� ����� 
	map.loadFromImage(map_image);//�������� �������� ���������
	Sprite s_map;//������ ������ ��� ����� 
	s_map.setTexture(map);//�������� �������� ��������
	
	Clock clock; //������� ���������� ������� � ������������ ��������� ����!
	Clock gameTimeClock;//���������� �������� �������, ����� ����� ������� ����� ���� 
	int gameTime = 0;//�������� ������� �����, ����������������.
	
	Image PacmanImage;
	PacmanImage.loadFromFile("images/Pacman.png"); // ��������� ����������� ������
	
	Image EnemyImageSh1;
	EnemyImageSh1.loadFromFile("images/PSH1.png");

	Pacman p(PacmanImage, 80, 80, 40.0, 40.0,"Packman");//������� ������ p ������ player, ������ "hero.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������.
	//Enemy Psh1(EnemyImageSh1, 40, 40, 40.0, 40.0,"PSH1");
	std::list<Entity*> enemies;
	std::list<Entity*>::iterator it;

	const int ENEMY_COUNT = 3; //������������ ���������� ������ � ���� 
	int enemiesCount = 0; 

	for (int i = 0; i < ENEMY_COUNT; i++) 
		{ 
			float xr = 150 + rand() % 500; // ��������� ���������� ����� �� ���� ���� �� ��� �x� 
			float yr = 150 + rand() % 350; // ��������� ���������� ����� �� ���� ���� �� ��� �y�  
			//������� ������ � �������� � ������  
			enemies.push_back(new Enemy(EnemyImageSh1, xr, yr, 40, 40, "EnemyImageSh1"));  
			enemiesCount += 1; //��������� ������� ������ 
	} 


	
	
	//Image EnemyImageSh2;
	//Image EnemyImageSh3;

	
	
	//EnemyImageSh2.loadFromFile("images/PSH2.png");
	//EnemyImageSh3.loadFromFile("images/PSH3.png");

	
	
	//Enemy Psh1(EnemyImage, 80, 80, 40.0, 40.0,"PSH1");
	//Enemy Psh2(EnemyImage, 80, 80, 40.0, 40.0,"PSH2");
	//Enemy Psh3(EnemyImage, 80, 80, 40.0, 40.0,"PSH3");


	int createObjectForMapTimer = 0;//���������� ��� ����� ��� ������������� ������
	int createObjectForMapTimer1 = 0;//���������� ��� ����� ��� ������������� ������
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		if (p.life) gameTime = gameTimeClock.getElapsedTime().asSeconds();//������� ����� � 
		//�������� ��� ������, ���� ��� �����. ������������� ��� time ��� �� ����. 
		//��� �� ��������� ������ ����
		clock.restart(); 
		time = time / 800;


		createObjectForMapTimer += time;//���������� ������
		if (createObjectForMapTimer>2000)
		{ 
			randomMapGenerate();//��������� ������
			createObjectForMapTimer = 0;//�������� ������
		}

		createObjectForMapTimer1 += time;//���������� ������
		if (createObjectForMapTimer1>3000)
		{ 
			randomMapGenerate1();//��������� ������
			createObjectForMapTimer1 = 0;//�������� ������
		}
		sf::Event event; 
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
				window.close(); 
		}
		
		
		
		
		p.update(time);//�������� ������ �p� ������ �Player� � ������� ������� sfml, // ��������� ����� � �������� ��������� ������� update.
		
		for  (it = enemies.begin(); it != enemies.end(); it++)   
			{   
				(*it)->update(time); //��������� ����� update()  
			} 

	if (p.life == true)
	{//���� ����� ���  
		for (it = enemies.begin(); it != enemies.end(); it++)
				{//����� �� ������ ������   
					if ((p.getRect().intersects((*it)->getRect())) && ((*it)->name == "Psh1"))     
						{      
							p.health = 0;      
								std::cout << "you are lose";     
							}    
					}   
			} 
		
		window.clear(); 

		/////////////////////////////������ �����/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
				{ 
					if (TileMap[i][j] == ' ') 
						s_map.setTextureRect(IntRect(0, 0, 40, 40)); //����
					//��������� ������ ������, �� ������ 1-� ��������� 
					if (TileMap[i][j] == 's') 
						s_map.setTextureRect(IntRect(40, 0, 40, 40));//����
					//��������� ������ s, �� ������ 2� ���������
					if ((TileMap[i][j] == '0')) 
						s_map.setTextureRect(IntRect(80, 0, 40, 40));//����
					//��������� ������ 0, �� ������ 3� ���������
					if ((TileMap[i][j] == 'f')) 
				
					s_map.setTextureRect(IntRect(120, 0, 40, 40));
					
				
					if ((TileMap[i][j] == 'h')) 
						s_map.setTextureRect(IntRect(200, 0, 40, 40));
						s_map.setPosition(j * 40, i * 40);//������������ ���������� � �����.
						window.draw(s_map);//������ ���������� �� �����
			}


		window.draw(p.sprite);//������� ������ �� �����
		
		for (it = enemies.begin(); it != enemies.end(); it++)
		{ 
			//if ((*it)->life) //���� ����� ����
			window.draw((*it)->sprite); //������ enemies ������� 
			}
		
		window.display(); 
	}
return 0;

}
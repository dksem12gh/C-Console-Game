#pragma once
#include<time.h>
#include"DDR RPG.h"
#include"Item.h"
#include "Shop.h"
#include "Player.h"

//Ű�Է� ����
enum
{
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN,
	KEY_ENTER,//����
	KEY_ESC,//�Ͻ�����
	KEY_I,//�κ��丮
};

struct pos
{
	int x;
	int y;
	bool dir; //���� true : �� false : ��
	bool dir2;//���� true : �� false : �Ʒ�
};

class Shop;

class GameManager
{
private:	
	int shootCount;
	bool gamePlay;
	pos shoot[149];
public:	
	int _battleNum = 0;

	int dCount = 0;

	void title();
	void ending();

	//�׸��� �Լ�
	//lobyUI
	void drawUI();
	void fildUI();
	void drawMap(const int wallColor);
	int drawMenu(const int x, const int y, const int max);

	//heal UI
	void monsterMgr();

	//battle UI
	void battleUI();	

	void levelCheck(int curExp,int maxExp);

	//Ű�Է�
	int keyInput();

	//��
	int nowLodingMap(); //���� ������ �׸����ִ��� int �� ������ �������ֱ�
	void settingMap(const int map);	 //���Ϲ����� �� �ٲٱ�

	//����
	void gameStart(bool& gameMain); //���� ������Ʈ �Լ�

	void InitShop(Shop &shop);
	void InitMonster();

	void battleCheck(int battleNum , bool &play,int& map);

	void battleCheck02(int battleNum, bool &play, int& map);

	void battleCheck03(int battleNum, bool &play, int& map);

	int getBattleNum() { return _battleNum; }
	void setBattleNum(int battleNum) { _battleNum = battleNum; }

	void helpShow();

	GameManager();
		~GameManager();
};


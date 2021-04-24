#include "GameManager.h"
#include "Map.h"
#include "Monster.h"

Util util;
Player player;
Shop _shop;

void GameManager::helpShow()
{
}

GameManager::GameManager()
{		
	util.setHide();
	system("mode con:cols=151 lines=44");//��ũ�� 101*30	
}

GameManager::~GameManager()
{
}

void GameManager::title()
{	
	util.setColor(util.white, util.black);
	GameManager().settingMap(8);
	GameManager().drawMap(15);		

}

void GameManager::ending()
{
	if (dCount < 3)return;

	system("cls");
	Util().setXY(65, 30);
	cout << "�غ��� ������ ��������Դϴ�!" << endl;	
	Util().setXY(65, 31);
	cout << "�����մϴ�!" << endl;
	Sleep(5000);
	exit(0);
}

//����ϱ� �ڵ� ������ �ȵȴ� �׳� ¥��..

//draw�����ľ��� - �� ���� ui����ų� Ŭ������ ������
void GameManager::drawUI()
{
	util.setColor(util.white, util.black);

	util.setXY(5, 31);
	cout << "[�÷��̾� �̸� : "<<player.getPlayer().name<<"]";

	util.setXY(30, 31);
	cout << "[���� " << player.getPlayer().level << "]";

	util.setXY(50, 31);
	cout << "���� �� : "<<player.getPlayer().gold <<"��";

	util.setXY(5, 33);
	cout << "[ ü�� ]";
	player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

	util.setXY(5, 36);
	cout << "[ ����ġ ]";
	player.expbar(player.getPlayer().expMax, player.getPlayer().expCur,5, 37);


	Util().setXY(50, 33);
	cout << "[ �ּ� ~ �ִ� ���ݷ� ]";

	Util().setXY(75, 33);
	cout << "[ ������ ���� ]";

	if (!player.getPlayer().equipB[0])
	{
		Util().setXY(75, 34);
		cout << "[����]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
	}
	else
	{
		Util().setXY(75, 34);
		cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
	}


	Util().setXY(75, 36);
	cout << "[ ��â�� �� ]";
	Util().setXY(50, 36);
	cout << "[ �ּ� ~ �ִ� ���� ]";
	if (!player.getPlayer().equipB[1])
	{
		Util().setXY(75, 37);
		cout << "[����]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
	}
	else
	{
		Util().setXY(75, 37);
		cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMin() << "]";
	}

	Util().setXY(120, 36);
	cout << "�������� ���� �巡�� "<<dCount<<"/3"<< endl;

	util.setXY(125, 2);
	cout << "[ �κ��丮 ]";
	player.pShowItem2(118, 3);



	util.setColor(util.black, util.white);
	util.setXY(10, 2);
	cout << "����";

	util.setColor(util.black, util.white);
	util.setXY(80, 4);
	cout << "�ϴ���";

	util.setColor(util.black, util.white);
	util.setXY(58, 13);
	cout << "�ߴ���";

	util.setColor(util.black, util.white);
	util.setXY(90, 20);
	cout << "�����";

	util.setColor(util.black, util.white);
	util.setXY(10, 9);
	cout << "����";

	util.setColor(util.black, util.white);
	util.setXY(10, 16);
	cout << "����";

	util.setColor(util.white, util.black);
}

void GameManager::fildUI()
{
	util.setColor(util.white, util.black);

	util.setXY(5, 31);
	cout << "[�÷��̾� �̸� : " << player.getPlayer().name << "]";

	util.setXY(30, 31);
	cout << "[���� " << player.getPlayer().level << "]";

	util.setXY(50, 31);
	cout << "���� �� : " << player.getPlayer().gold << "��";

	util.setXY(100, 31);
	cout << "�����ΰ��� : ESC";


	util.setXY(5, 33);
	cout << "[ ü�� ]";
	player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

	util.setXY(5, 36);
	cout << "[ ����ġ ]";
	player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);


	Util().setXY(50, 33);
	cout << "[ �ּ� ~ �ִ� ���ݷ� ]";

	Util().setXY(75, 33);
	cout << "[ ������ ���� ]";

	if (!player.getPlayer().equipB[0])
	{
		Util().setXY(75, 34);
		cout << "[����]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
	}
	else
	{
		Util().setXY(75, 34);
		cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
		Util().setXY(50, 34);
		cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
	}


	Util().setXY(75, 36);
	cout << "[ ��â�� �� ]";
	Util().setXY(50, 36);
	cout << "[ �ּ� ~ �ִ� ���� ]";
	if (!player.getPlayer().equipB[1])
	{
		Util().setXY(75, 37);
		cout << "[����]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
	}
	else
	{
		Util().setXY(75, 37);
		cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
		Util().setXY(50, 37);
		cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMin() << "]";
	}

	util.setXY(125, 2);
	cout << "[ �κ��丮 ]";
	player.pShowItem2(118, 3);
}

void GameManager::drawMap(const int wallColor)
{
	shootCount = 0;
	system("cls");
	for (int i = 0; i < mapX; i++)
	{
		for (int j = 0; j < mapY; j++)
		{
			unsigned char temp = tMap[i][j];
			if (temp == BLOCK_null)
			{				
				util.setColor(util.black, util.black);
				cout << "��";//�����
			}
			else if (temp == BLOCK_wall)
			{
				util.setColor(util.white, util.black);
				cout << "��"; //��
			}
			else if (temp == BLOCK_wall01)
			{
				Util().setColor(Util().lightcyan, Util().darkgray);
				cout << "  ";
			}
			else if (temp == BLOCK_player)
			{
				Util().setColor(Util().lightblue, Util().black);
				cout << "  ";
				//�÷��̾� ��ġ Ȯ���ϸ� ��ġ�� �ʱ�ȭ
				player.p_Pos_X = j;
				player.p_Pos_Y = i;
				
				tMap[i][j] = BLOCK_null;				
			}
			else if (temp == BLCOK_battlePotal01)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_battlePotal02)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_battlePotal03)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_healing)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_shopPotal)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLCOK_miniPotal)
			{
				Util().setColor(Util().yellow, Util().yellow);
				cout << "  ";
			}
			else if (temp == BLOCK_monsterH || temp == BLOCK_monsterV)
			{
				Util().setColor(Util().black, Util().black);

				cout << "��";

				struct pos tempPos;
				if (temp == BLOCK_monsterV)
				{
					if (tMap[i][j - 2] == BLOCK_wall)
					{
						tempPos.dir = true;
					}
					else
					{
						tempPos.dir = false;
					}
				}
				else if (temp == BLOCK_monsterH)
				{
					if (tMap[i - 2][j] == BLOCK_wall)
					{
						tempPos.dir = true;
					}
					else
					{
						tempPos.dir = false;
					}
				}

				tempPos.x = j;
				tempPos.y = i;

				shoot[shootCount++] = tempPos;
			}	
		}
		util.setColor(util.white, util.black);
		cout << "\n";		
	}
}

int GameManager::drawMenu(const int x, const int y, const int max)
{
	bool loop = true; // �ݺ� �Ҹ���
	int selectNum = 0;//���ϰ�

	util.setXY(x, y);
	cout << "�Ͼ��" << endl;

	util.setXY(x, y+2);
	cout << "�ϴ¹��" << endl;

	util.setXY(x, y+4);
	cout << "��������" << endl;

	//���� ���� ��ġ
	util.setXY(x - 3, y + selectNum);
	cout << "��";
	util.setXY(x + 9, y + selectNum);
	cout << "��";	

	while (loop)
	{		
		Sleep(50);//������ �Ϻη��� �����Է¹���
		int s = keyInput();

		switch (s)
		{
		case 2://up
			if (selectNum > 0)
			{
				util.setXY(x - 3, y + selectNum);
				cout << " ";
				util.setXY(x + 9, y + selectNum);
				cout << " ";
				selectNum-=2;
				util.setXY(x - 3, y + selectNum);
				cout << "��";
				util.setXY(x + 9, y + selectNum);
				cout << "��";
			}
			break;
		case 3://down
			if (selectNum < 4)
			{
				util.setXY(x - 3, y + selectNum);
				cout << " ";
				util.setXY(x + 9, y + selectNum);
				cout << " ";
				selectNum+=2;
				util.setXY(x - 3, y + selectNum);
				cout << "��";
				util.setXY(x + 9, y + selectNum);
				cout << "��";
			}
			break;
		case 4://enter �����ϸ�

			util.setXY(x - 3, y + selectNum);
			cout << " ";
			util.setXY(x + 9, y + selectNum);
			cout << " ";			
			util.setXY(x - 2, y + selectNum);
			cout << "��";
			util.setXY(x + 8, y + selectNum);
			cout << "��";
			Sleep(100);

			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			util.setXY(x - 2, y + selectNum);
			cout << "��";
			util.setXY(x + 8, y + selectNum);
			cout << "��";
			Sleep(100);

			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			cout << "��";
			util.setXY(x + 8, y + selectNum);
			cout << "��";
			Sleep(100);
			util.setXY(x - 2, y + selectNum);
			cout << " ";
			util.setXY(x + 8, y + selectNum);
			cout << " ";
			util.setXY(x - 2, y + selectNum);
			cout << "��";
			util.setXY(x + 8, y + selectNum);
			cout << "��";			
			loop = false;// �ݺ�����
			break;
		}
	}
	return selectNum/2;//��� �޴� ������� ����
}

void GameManager::monsterMgr()
{
	for (int i = 0; i < shootCount; i++)
	{
		struct pos* target = &shoot[i];
		int x = target->x;
		int y = target->y;
		Util().setXY(x, y);
		cout << " ";

		unsigned char temp = tMap[y][x];
				/*[174]��//���� ��
			[175]��*///���� ��
		if (temp == 174)
		{
			if (target->dir)
			{
				if (tMap[y][x + 2] == 224)
				{
					tMap[y][x] = 224;
					tMap[y][x + 2] = 174;

					target->x++;
					target->x++;

					Util().setXY(x + 2, y);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = false;
				}
			}
			else
			{
				if (tMap[y][x - 2] == 224)
				{
					tMap[y][x] = 224;
					tMap[y][x - 2] = 174;
					
					target->x--;
					target->x--;

					Util().setXY(x-2, y);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = true;
				}
			}
		}
		else if (temp == 175)
		{
			if (target->dir)
			{
				if (tMap[y + 1][x] == 224)
				{
					tMap[y][x] = 224;
					tMap[y + 1][x] = 175;

					target->y++;					

					Util().setXY(x, y + 1);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = false;
				}
			}
			else
			{
				if (tMap[y - 1][x] == 224)
				{
					tMap[y][x] = 224;
					tMap[y - 1][x] = 175;
					
					target->y--;

					Util().setXY(x, y - 1);
					Util().setColor(Util().lightpurple, Util().black);
					cout << "M";
				}
				else
				{
					shoot[i].dir = true;
				}
			}
		}

		if (target->x == player.p_Pos_X && target->y == player.p_Pos_Y)
		{
			//���� ������ �Ҹ�
			//�浹
		}
	}
}


void GameManager::battleUI()
{
}

void GameManager::levelCheck(int curExp, int maxExp)
{
	if (curExp < maxExp) return;
	util.setXY(40, 31);
	util.setColor(util.black, util.white);
	cout << "[Level Up!]";
	Sleep(1000);
	util.setXY(40, 31);
	util.setColor(util.black, util.black);
	cout << "[Level Up!]";
	util.setColor(util.white, util.black);



	player.setPlayer().level += player.getLevelTable().level;
	player.setPlayer().hpMax += player.getLevelTable().hpMax;
	player.setPlayer().hpCur = player.getPlayer().hpMax;
	player.setPlayer().attackMin += player.getLevelTable().attackMin;
	player.setPlayer().attackMax += player.getLevelTable().attackMax;
	player.setPlayer().defMin += player.getLevelTable().defMin;
	player.setPlayer().defMax += player.getLevelTable().defMax;
	player.setPlayer().expMax += player.getLevelTable().expMax;
	player.setPlayer().expCur = 0;	
}

int GameManager::keyInput()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		return KEY_LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		return KEY_RIGHT;
	}
	else if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return KEY_UP;
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return KEY_DOWN;
	}
	else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
		return KEY_ENTER;
	}
	else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
		return KEY_ESC;
	}
	else {
		return -1;
	}
}

int GameManager::nowLodingMap()
{
	int cur = player.getPlayerMap();	

	return cur;
}

void GameManager::settingMap(const int map)
{
	//�� ����
	switch (map)
	{
	default:
	case 0:
		memcpy(tMap, loby, sizeof(tMap));
		break;
	case 1:
		memcpy(tMap, shop, sizeof(tMap));
		break;
	case 2:
		memcpy(tMap, bag, sizeof(tMap));
		break;
	case 3:
		memcpy(tMap, hospital, sizeof(tMap));
		break;
	case 4:
		memcpy(tMap, fild01, sizeof(tMap));
		break;
	case 5:
		memcpy(tMap, fild02, sizeof(tMap));
		break;
	case 6:
		memcpy(tMap, fild03, sizeof(tMap));
		break;
	case 7:
		memcpy(tMap, battle, sizeof(tMap));
		break;
	case 8:
		memcpy(tMap, mTitle, sizeof(tMap));
		break;
	case 9:
		memcpy(tMap, battle, sizeof(tMap));
		break;
	}
}

void GameManager::gameStart(bool& gameMain)
{	
	bool nameCheck = true;
	bool nameLoop = true;
	int s = 0;
	int select = 0;
	int a = 0;

	InitShop(_shop);
	InitMonster();

	while (nameCheck)
	{
		nameLoop = true;

		system("cls");
		util.setXY(65, 20);
		cout << "���� �̸��� �����ΰ�?" << endl;
		cin >> player.setPlayer().name;			
		while (nameLoop)
		{
			system("cls");
			util.setXY(65, 20);
			cout << "'" << player.getPlayer().name << "' �� ���� �̸��� �³�?" << endl;
			util.setXY(65, 22);
			cout << "(1) ��  (2) �ƴϿ�" << endl;
			cin >> s;

			if (s == 2)
			{
				nameLoop = false;
			}
			else if (s == 1)
			{
				nameCheck = false;
				nameLoop = false;				
			}
			else
			{
				system("cls");
				util.setXY(65, 20);
				cout << "�� / �ƴϿ� �� �ϳ��� �����ؾ��Ѵ�." << endl;
				Sleep(1000);
				continue;
			}
		}
	}

	gamePlay = false;

	while (true)
	{		
		int map = nowLodingMap();//�÷��̾� �� ����� �޾ƿ;���

		system("cls");

		switch (map)
		{
		case 0:
			settingMap(LOBY);
			gamePlay = true;
			break;
		case 1:
			settingMap(SHOP);
			gamePlay = true;
			break;
		case 2:
			settingMap(INVEN);
			gamePlay = true;
			break;
		case 3:
			settingMap(HOSPITAL);
			gamePlay = true;
			break;
		case 4:
			settingMap(FILD01);
			gamePlay = true;
			break;
		case 5:
			settingMap(FILD02);
			gamePlay = true;
			break;
		case 6:
			settingMap(FILD03);
			gamePlay = true;
			break;
		case 7:
			settingMap(BATTLE);
			gamePlay = true;
			break;
		case 8:
			settingMap(BATTLE02);
			gamePlay = true;
			break;
		case 9:
			settingMap(BATTLE03);
			gamePlay = true;
			break;
		default:
			return;
		}

		ending();//���� ���ϰ�

		//<- ���� ����
		drawMap(15);
		Sleep(100);
		/*
			�߰��Ұ�

			��, ���� �� �÷��̾� ���� ���� ��¾ȵǰ�
			��, ���� ui���� ����� draw�Լ��� ���� ����ų� draw�Լ� Ŭ������ ���� ������
		*/
		//����
		while (gamePlay)
		{				
			int s = keyInput();									

			if (map == LOBY || map == FILD01 || map == FILD02 || map == FILD03)
			{
				switch (s)
				{
				case KEY_LEFT:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, -2, 0, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_RIGHT:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 2, 0, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_UP:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 0, -1, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_DOWN:
					if (player.getPlayer().hpCur > 1)
					{
						player.setPlayer().hpCur = player.getPlayer().hpCur - 1;
						player.setPlayer().expCur = player.getPlayer().expCur + 1;
					}
					util.move(tMap, 0, 1, player.p_Pos_X, player.p_Pos_Y, map, gamePlay);
					break;
				case KEY_ESC:
					if (map == FILD01 || map == FILD02 || map == FILD03)
					{
						map = 0;
						gamePlay = false;
					}
					else if (map == LOBY)
					{

					}
					break;
				case KEY_I:
					break;
				default:
					break;
				}
			}
			else if (map == SHOP)
			{
				_shop.inShop(player,gamePlay,map);
			}
			else if (map == INVEN)
			{
				player.playerEquipShow(player,gamePlay,map);
			}
			else if (map == HOSPITAL)
			{
				_shop.isHospital(player, gamePlay, map);
			}
			else if (map == BATTLE)
			{
				battleCheck(_battleNum,gamePlay,map);
			}
			else if (map == BATTLE02)
			{
				battleCheck02(_battleNum, gamePlay, map);
			}
			else if (map == BATTLE03)
			{
				battleCheck03(_battleNum, gamePlay, map);
			}
			levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
			player.setPlayerMap(map);

			if (map == LOBY)
			{
				drawUI();
			}
			else if(map == FILD01 || map == FILD02 || map == FILD03)
			{
				fildUI();
				monsterMgr();
			}			
			Sleep(50);
		}
	}
}

void GameManager::InitShop(Shop & shop)
{
	//����
	shop.sAddItem(Item("�챸������ �ͱ� ��Ŭ", 300, 3, 0, 10, 20), true);
	shop.sAddItem(Item("������ �밡�� ���尩", 500, 3, 0, 15, 25), true);
	shop.sAddItem(Item("�ָ� �尩", 1000, 2, 0, 30, 50), true);
	shop.sAddItem(Item("������ �������� ö�尩", 1200, 4, 0, 40, 75), true);
	shop.sAddItem(Item("������ ������ ���� ��Ŭ", 2000, 1, 0, 80, 150), true);
	shop.sAddItem(Item("�ǵ����ǻ���", 100000, 1, 0, 1, 1000), true);
	shop.sAddItem(Item("¯�ڹ���", 200000, 1, 0, 1000, 1000), true);

	//��
	shop.sAddItem(Item("���ں��� ���� ��", 200, 5, 1, 5, 8), true);
	shop.sAddItem(Item("����縣�� ��", 450, 3, 1, 10, 15), true);
	shop.sAddItem(Item("¥�չ����� �� õ����", 700, 2, 1, 10, 30), true);
	shop.sAddItem(Item("�⼺������ ���޺���", 1000, 1, 1, 25, 60), true);
	shop.sAddItem(Item("�ù�� ����ǰ ���־Ƹ�", 1500, 1, 1, 70, 100), true);
	shop.sAddItem(Item("���þȷ귿 �Ƹ�", 50000, 1, 1, 1, 1000), true);	
}

void GameManager::InitMonster()
{
	monster[0]._name = "�ٶ���";
	monster[0]._text = "�ؽ��� �ٶ��㸦 �ѷ���!!";
	monster[0]._maxHp = 300;
	monster[0]._curHp = monster[0]._maxHp;
	monster[0]._minAttack = 50;
	monster[0]._maxAttack = 100;
	monster[0]._def = 10;
	monster[0]._exp = 30;
	monster[0]._gold = 120;

	monster[1]._name = "��";
	monster[1]._text = "�����⸦ �հ� ������ ���� ����";
	monster[1]._maxHp = 350;
	monster[1]._curHp = monster[1]._maxHp;
	monster[1]._minAttack = 70;
	monster[1]._maxAttack = 100;
	monster[1]._def = 15;
	monster[1]._exp = 60;
	monster[1]._gold = 200;

	monster[2]._name = "�ذ�";
	monster[2]._text = "WA!!!! ���ֿ�!!!";
	monster[2]._maxHp = 500;
	monster[2]._curHp = monster[2]._maxHp;
	monster[2]._minAttack = 50;
	monster[2]._maxAttack = 200;
	monster[2]._def = 30;
	monster[2]._exp = 150;
	monster[2]._gold = 400;

	monster[3]._name = "�����";
	monster[3]._text = "������ ���� ���~�� ������ �������";
	monster[3]._maxHp = 700;
	monster[3]._curHp = monster[3]._maxHp;
	monster[3]._minAttack = 100;
	monster[3]._maxAttack = 250;
	monster[3]._def = 40;
	monster[3]._exp = 350;
	monster[3]._gold = 1000;

	monster[4]._name = "���ȷ���";
	monster[4]._text = "�����غ��̴� �ܸ�ʹ� �޸� �ſ� ��Ȥ�� ����";
	monster[4]._maxHp = 500;
	monster[4]._curHp = monster[4]._maxHp;
	monster[4]._minAttack = 150;
	monster[4]._maxAttack = 300;
	monster[4]._def = 60;
	monster[4]._exp = 300;
	monster[4]._gold = 2500;

	monster[5]._name = "�巡��";
	monster[5]._text = "������ ���� ���ĳ��Դ�.";
	monster[5]._maxHp = 1000;
	monster[5]._curHp = monster[5]._maxHp;
	monster[5]._minAttack = 300;
	monster[5]._maxAttack = 550;
	monster[5]._def = 60;
	monster[5]._exp = 500;
	monster[5]._gold = 5000;
}

void GameManager::battleCheck(int battleNum, bool &play, int& map)
{	
	srand(time(NULL));	
	char s;

	int battle = _battleNum;

	int n = rand() % 2;
	int a = 0;

	GameManager().settingMap(7);
	GameManager().drawMap(15);

	while (true)
	{			
		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[�÷��̾� �̸� : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[���� " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "���� �� : " << player.getPlayer().gold << "��";

		Util().setXY(5, 33);
		cout << "[ ü�� ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ ����ġ ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ �ּ� ~ �ִ� ���ݷ� ]";

		Util().setXY(75, 33);
		cout << "[ ������ ���� ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[����]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ ��â�� �� ]";
		Util().setXY(50, 36);
		cout << "[ �ּ� ~ �ִ� ���� ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[����]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}								

		if (battle == 0)
		{
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "���� :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "���ݷ� :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "���� :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "óġ�� ȹ�� ����ġ :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "óġ�� ȹ�� ��� :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. �����ϱ�     2.��������" << endl;
			Util().setXY(60, 27);
			cout << "�޴��� �����ϼ��� :"; cin >> a;

			if (a == 2)
			{				
				play = false;
				map = 4;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//���� �����ִٸ� ����
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "���͸� ��Ҵ�!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;			

					system("pause");
					play = false;
					map = 4;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "�÷��̾� ���!"<<endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //������ ����ġ �� ���
					player.setPlayer().gold -= tGold;	

					map = 0;
					play = false;
					break;
				}
			}
		}
	}
}

void GameManager::battleCheck02(int battleNum, bool & play, int & map)
{
	srand(time(NULL));
	char s;

	int battle = _battleNum;

	int n = rand() % 4 +2;
	int a = 0;
	GameManager().settingMap(7);
	GameManager().drawMap(15);
	while (true)
	{
		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);

		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[�÷��̾� �̸� : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[���� " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "���� �� : " << player.getPlayer().gold << "��";

		Util().setXY(5, 33);
		cout << "[ ü�� ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ ����ġ ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ �ּ� ~ �ִ� ���ݷ� ]";

		Util().setXY(75, 33);
		cout << "[ ������ ���� ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[����]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ ��â�� �� ]";
		Util().setXY(50, 36);
		cout << "[ �ּ� ~ �ִ� ���� ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[����]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}

		if (battle == 0)
		{
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "���� :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "���ݷ� :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "���� :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "óġ�� ȹ�� ����ġ :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "óġ�� ȹ�� ��� :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. �����ϱ�     2.��������" << endl;
			Util().setXY(60, 27);
			cout << "�޴��� �����ϼ��� :"; cin >> a;

			if (a == 2)
			{
				play = false;
				map = 5;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//���� �����ִٸ� ����
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "���͸� ��Ҵ�!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;

					system("pause");
					play = false;
					map = 5;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "�÷��̾� ���!" << endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //������ ����ġ �� ���
					player.setPlayer().gold -= tGold;

					map = 0;
					play = false;
					break;
				}
			}
		}
	}
}

void GameManager::battleCheck03(int battleNum, bool & play, int & map)
{
	srand(time(NULL));
	char s;

	int battle = _battleNum;

	int n = 5;
	int a = 0;

	GameManager().settingMap(7);
	GameManager().drawMap(15);

	while (true)
	{

		levelCheck(player.getPlayer().expCur, player.getPlayer().expMax);
		Util().setColor(Util().white, Util().black);

		Util().setXY(5, 31);
		cout << "[�÷��̾� �̸� : " << player.getPlayer().name << "]";

		Util().setXY(30, 31);
		cout << "[���� " << player.getPlayer().level << "]";

		Util().setXY(50, 31);
		cout << "���� �� : " << player.getPlayer().gold << "��";

		Util().setXY(5, 33);
		cout << "[ ü�� ]";
		player.progressbar(player.getPlayer().hpMax, player.getPlayer().hpCur, 5, 34);

		Util().setXY(5, 36);
		cout << "[ ����ġ ]";
		player.expbar(player.getPlayer().expMax, player.getPlayer().expCur, 5, 37);

		Util().setXY(50, 33);
		cout << "[ �ּ� ~ �ִ� ���ݷ� ]";

		Util().setXY(75, 33);
		cout << "[ ������ ���� ]";

		if (!player.getPlayer().equipB[0])
		{
			Util().setXY(75, 34);
			cout << "[����]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << " ~ " << player.getPlayer().attackMax << "]";
		}
		else
		{
			Util().setXY(75, 34);
			cout << "[" << player.getPlayer().equipT[0].getName() << "]" << endl;
			Util().setXY(50, 34);
			cout << "[" << player.getPlayer().attackMin << "+" << player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax << "+" << player.getPlayer().equipT[0].getMax() << "]";
		}


		Util().setXY(75, 36);
		cout << "[ ��â�� �� ]";
		Util().setXY(50, 36);
		cout << "[ �ּ� ~ �ִ� ���� ]";
		if (!player.getPlayer().equipB[1])
		{
			Util().setXY(75, 37);
			cout << "[����]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << " ~ " << player.getPlayer().defMax << "]";
		}
		else
		{
			Util().setXY(75, 37);
			cout << "[" << player.getPlayer().equipT[1].getName() << "]" << endl;
			Util().setXY(50, 37);
			cout << "[" << player.getPlayer().defMin << "+" << player.getPlayer().equipT[1].getMin() << " ~ " << player.getPlayer().defMax << "+" << player.getPlayer().equipT[1].getMax() << "]";
		}
			Util().setXY(60, 4);
			Util().setColor(Util().white, Util().black);
			cout << "[" << monster[n]._name << "]";
			player.progressbar(monster[n]._maxHp, monster[n]._curHp, 60, 5);
			Util().setXY(60, 7);
			cout << "���� :" << monster[n]._text;
			Util().setXY(60, 8);
			cout << "���ݷ� :" << monster[n]._minAttack << " ~ " << monster[n]._maxAttack;
			Util().setXY(60, 9);
			cout << "���� :" << monster[n]._def;
			Util().setXY(60, 10);
			cout << "óġ�� ȹ�� ����ġ :" << monster[n]._exp;
			Util().setXY(60, 11);
			cout << "óġ�� ȹ�� ��� :" << monster[n]._gold;

			Util().setXY(60, 26);
			cout << "1. �����ϱ�     2.��������" << endl;
			Util().setXY(60, 27);
			cout << "�޴��� �����ϼ��� :"; cin >> a;

			if (a == 2)
			{
				play = false;
				map = 6;
				break;
			}
			else if (a == 1)
			{
				int tAttackMin = player.getPlayer().attackMin;
				int tAttackMax = player.getPlayer().attackMax;

				if (player.getPlayer().equipB[EQ_WEPON])//���� �����ִٸ� ����
				{
					tAttackMin += player.getPlayer().equipT[EQ_WEPON].getMin();
					tAttackMax += player.getPlayer().equipT[EQ_WEPON].getMax();
				}

				int tAttack = rand() % (tAttackMax - tAttackMin + 1) + tAttackMin;
				int tArmor = monster[n]._def;

				int Damage = tAttack - tArmor;
				Damage = Damage < 1 ? 1 : Damage;

				monster[n]._curHp -= Damage;

				if (monster[n]._curHp <= 0)
				{
					Util().setXY(60, 27);
					cout << "���͸� ��Ҵ�!" << endl;
					Sleep(1000);
					player.setPlayer().expCur += monster[n]._exp;
					player.setPlayer().gold += monster[n]._gold;

					monster[n]._curHp = monster[n]._maxHp;

					dCount++;

					system("pause");
					play = false;
					map = 6;
					break;
				}

				tAttack = rand() % (monster[n]._maxAttack - monster[n]._minAttack + 1) + monster[n]._minAttack;

				int pArmorMin = player.getPlayer().defMin;
				int pArmorMax = player.getPlayer().defMax;

				if (player.getPlayer().equipB[EQ_ARMOR])
				{
					pArmorMin += player.getPlayer().equipT[EQ_ARMOR].getMin();
					pArmorMax += player.getPlayer().equipT[EQ_ARMOR].getMax();
				}
				tArmor = rand() % (pArmorMax - pArmorMin + 1) + pArmorMin;
				Damage = tAttack - tArmor;

				Damage = Damage < 1 ? 1 : Damage;

				player.setPlayer().hpCur -= Damage;

				if (player.getPlayer().hpCur <= 0)
				{
					Util().setXY(60, 27);
					cout << "�÷��̾� ���!" << endl;
					Sleep(1000);

					int tExp = player.getPlayer().expCur*0.1;
					int tGold = player.getPlayer().gold *0.1;

					player.setPlayer().expCur -= tExp; //������ ����ġ �� ���
					player.setPlayer().gold -= tGold;

					map = 0;
					play = false;
					break;
				}
			}
		
	}
}

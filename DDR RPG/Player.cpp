#include "Player.h"

void Player::playerDraw(const int dirx,const int diry, int& p_x, int& p_y)
{		
	Util().setXY(p_x, p_y);
	cout << " ";
	Util().setXY(p_x + dirx, p_y + diry);
	Util().setColor(Util().lightyellow, Util().black);
	cout << "P";
	p_x += dirx;
	p_y += diry;	
}

void Player::pShowItem(int x, int y)
{
	int num = 1;

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++, num++)
	{
		Util().setXY(x, y + num);
		cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "| �ǸŰ� :" << (*i).getPrice() * 0.6 << endl;
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y + 1);
		cout << "���� �������� ����                          " << endl;
	}
}


void Player::pShowItem2(int x, int y) //���� ȭ���� ���� ����
{
	int num = 1;	

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++ , num++)
	{
		Util().setXY(x,y + num);
		cout << num << ". " << (*i).getName().substr(0,4) + "������" << " X " << (*i).getCount() <<endl;
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y+1);
		cout << "���� �������� ����." << endl;
	}
}

void Player::pShowItem3(int x, int y) //���� �ǹ��� ����
{
	int num = 1;

	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++, num++)
	{
		Util().setXY(x, y + num);
		if ((*i).getType() == 0)
		{
			cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "|\t [�ּ� ���ݷ� :" << (*i).getMin()<<"] [�ִ� ���ݷ� :"<< (*i).getMax() <<"]"<< endl;
		}
		else if ((*i).getType() == 1)
		{
			cout << num << ". " << (*i).getName() << " X " << (*i).getCount() << "|\t [�ּ� ���� :" << (*i).getMin() << "] [�ִ� ���� :" << (*i).getMax() << "]" << endl;
		}
	}

	if (itemList.size() == 0)
	{
		Util().setXY(x, y + 1);
		cout << "���� �������� ����." << endl;
	}
}

void Player::playerEquip(string name)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == name) //��ǰ�� ã����
		{
			EQUIP eq;

			switch ((*i).getType())
			{
			case 0:
				eq = EQ_WEPON;
				break;
			case 1:
				eq = EQ_ARMOR;
				break;			
			}

			//������ �̹� ������ ����
			if (player.equipB[eq] == true)
			{
				Item temp = player.equipT[eq];
				player.equipT[eq] = (*i);
				(*i) = temp;
			}
			else//���� ���ٸ� ������ �������� �κ� �����
			{
				player.equipT[eq] = (*i);
				pDelItem(name);
				player.equipB[eq] = true;
			}

			return;
		}
		else
		{						
		}
	}
}

void Player::playerEquipShow(Player &player, bool &play, int &map)
{
	bool done = false;
	char s;
	string name;
	while (done == false)
	{
		system("cls");
		GameManager().settingMap(2);
		GameManager().drawMap(15);

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
			cout << "[" << player.getPlayer().attackMin<<"+"<< player.getPlayer().equipT[0].getMin() << " ~ " << player.getPlayer().attackMax<<"+"<< player.getPlayer().equipT[0].getMax() << "]";
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
			cout << "[" << player.getPlayer().defMin <<"+"<< player.getPlayer().equipT[1].getMin()<< " ~ " << player.getPlayer().defMax<<"+"<<player.getPlayer().equipT[1].getMax() << "]";
		}

		Util().setXY(70, 2);
		cout << "[ �κ��丮 ]";
		player.pShowItem3(42, 3);

		Util().setXY(45, 25);
		cout << "�ΰ����� �ϳ��� ���ÿ�. (���� (e), ������(q)) : ";
		cin >> s;
		cin.ignore(1024, '\n');
		if (s == tolower('q'))// tolower - �ڵ��� �ҹ��� ��ȯ
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('e'))
			{
				Util().setXY(45, 25);
				Util().setColor(Util().black, Util().black);
				cout << "                                                         ";
				Util().setColor(Util().white, Util().black);
				Util().setXY(45, 25);
				cout << "������ �������� �Է��ϼ���. : ";
				getline(cin, name);
				cin.ignore(1024, '\n');
				playerEquip(name);
			}
		}
	}
	
}

void Player::pAddItem(const Item & item, bool first)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == item.getName()) //��ǰ�� ã����
		{
			(*i).addItem();//�� �߰�
			return;
		}
	}
	//�������� �߰�
	itemList.push_back(item);

	if (first == false) //�� ��ǰ�� ������ �ϳ�
	{
		itemList.back().setCount(1);
	}
}

bool Player::pDelItem(const string & itemName)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			(*i).delItem();

			if ((*i).getCount() <= 0) //������ 0�̵Ǹ� ����Ʈ���� ����
			{
				itemList.erase(i);
				return true;
			}
		}
	}
	//ã�°� ���ٸ�
	return false;
}

bool Player::buyItem(const Item & item)
{
	int price = item.getPrice();

	if (player.gold >= price)
	{
		player.gold -= price;
		pAddItem(item);
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

void Player::sellItem(const string & itemName, int price)
{
	pDelItem(itemName);
	player.gold += price;
}


void Player::progressbar(int maxHp, int curHp, float x, float y)
{
	int len = 15;
	int maxHP = maxHp;
	int curHP = curHp;
	int barCount = 0;

	float tick = (float)100 / len;
	float percent;

	Util().setXY(x, y);
	cout << curHP << " / " << maxHP << "\t";
	percent = (float)curHP / maxHP * 100;
	barCount = percent / tick;

	for (int i = 0; i < len; i++)
	{
		if (barCount > i)
		{
			Util().setColor(Util().black, Util().lightgreen);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
		else
		{
			Util().setColor(Util().black, Util().red);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
	}
}

void Player::expbar(int maxExp, int curExp, float x, float y)
{
	int len = 15;
	int maxEXP = maxExp;
	int curEXP = curExp;
	int barCount = 0;

	float tick = (float)100 / len;
	float percent;

	Util().setXY(x, y);
	cout << curEXP << " / " << maxEXP << "\t";
	percent = (float)curEXP / maxEXP * 100;
	barCount = percent / tick;

	for (int i = 0; i < len; i++)
	{
		if (barCount <= i)
		{
			Util().setColor(Util().black, Util().darkgray);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
		else
		{
			Util().setColor(Util().black, Util().yellow);
			cout << " ";
			Util().setColor(Util().white, Util().black);
		}
	}
}

//����Ʈ �˻��� �̸�ã���� ����������
void Player::getItem(const string & itemName, Item & item)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			item = *i;
		}
	}
}

Player::Player()
{	
	player.level = 1;
	player.hpMax = 500;
	player.hpCur = player.hpMax;	
	player.attackMin = 10;
	player.attackMax = 30;
	player.defMin = 10;
	player.defMax = 15;
	player.expMax = 100;
	player.expCur = 0;	
	player.gold = 1000000;	
	player.equipB[0] = false;
	player.equipB[1] = false;
}

Player::~Player()
{
}

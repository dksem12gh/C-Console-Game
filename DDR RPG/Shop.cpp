#include "Shop.h"
#include "Player.h"

//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������
//�������������������������

Shop::Shop()
{
}

Shop::~Shop()
{
	itemList.clear();
}

void Shop::sAddItem(const Item & item, bool first)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == item.getName())
		{
			(*i).addItem();
			return;
		}
	}

	itemList.push_back(item);

	if (first == false)
	{
		itemList.back().setCount(1);
	}
}

bool Shop::sDelItem(const string & itemName)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			(*i).delItem();

			if ((*i).getCount() <= 0)
			{
				itemList.erase(i);
				return true;
			}
		}
	}
	return false;
}

void Shop::inShop(Player & player,bool &play,int &map)
{
	bool done = false;
	char s;			
	while (done == false)
	{
		GameManager().settingMap(1);
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

		Util().setXY(30, 2);
		cout << "[ �� �� ]";
		showShopList(15, 3);

		Util().setXY(110, 2);
		cout << "[ �κ��丮 ]";
		player.pShowItem(90, 3);

		Util().setXY(4, 20);
		cout << "�ϰ� ������ ���ÿ�. (���� (b), �Ǹ� (s), ������(q)) : ";		
		cin >> s;
		cin.clear();
		if (s == tolower('q'))// tolower - �ڵ��� �ҹ��� ��ȯ
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('b'))
			{
				sSellItem(player);
			}
			else if (s == tolower('s'))
			{
				sBuyItem(player);
			}						
		}
	}
}

void Shop::isHospital(Player & player, bool & play, int & map)
{
	bool done = false;
	char s;	
	while (done == false)
	{	
		int sprite = 0;
		GameManager().settingMap(2);
		GameManager().drawMap(15);
		while (sprite < 2)
		{
			Util().setXY(50, 2);
			cout << "              �����������";
			Util().setXY(50, 3);
			cout << "            ���      ���      ���";
			Util().setXY(50, 4);
			cout << "          ���        ���        ���";
			Util().setXY(50, 5);
			cout << "          ��        �����        ��";
			Util().setXY(50, 6);
			cout << "          ��          ���          ��";
			Util().setXY(50, 7);
			cout << "        ��  ���      ���      ���  ��";
			Util().setXY(50, 8);
			cout << "        ��      ���������      ��";
			Util().setXY(50, 9);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 10);
			cout << "      ��      ��    ��    ��    ��      ��";
			Util().setXY(50, 11);
			cout << "      ��    ��      ��    ��      ��    ��";
			Util().setXY(50, 12);
			cout << "        ��  ��                    ��  ��";
			Util().setXY(50, 13);
			cout << "          �����            �����";
			Util().setXY(50, 14);
			cout << "            ��    ���    ���    ��";
			Util().setXY(50, 15);
			cout << "          ��  ��      ���      ��  ��";
			Util().setXY(50, 16);
			cout << "          ��    ��            ��    ��";
			Util().setXY(50, 17);
			cout << "            ���  ��        ��  ���";
			Util().setXY(50, 18);
			cout << "            �����        �����";
			Util().setXY(50, 19);
			cout << "              ��                ��";
			Util().setXY(50, 20);
			cout << "                ���������";
			Util().setXY(50, 21);
			cout << "                ��    ���    ��";
			Util().setXY(50, 22);
			cout << "                 ���    ���";

			Sleep(500);
			Util().setColor(Util().black, Util().black);
			Util().setXY(50, 2);
			cout << "              �����������";
			Util().setXY(50, 3);
			cout << "            ���      ���      ���";
			Util().setXY(50, 4);
			cout << "          ���        ���        ���";
			Util().setXY(50, 5);
			cout << "          ��        �����        ��";
			Util().setXY(50, 6);
			cout << "          ��          ���          ��";
			Util().setXY(50, 7);
			cout << "        ��  ���      ���      ���  ��";
			Util().setXY(50, 8);
			cout << "        ��      ���������      ��";
			Util().setXY(50, 9);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 10);
			cout << "      ��      ��    ��    ��    ��      ��";
			Util().setXY(50, 11);
			cout << "      ��    ��      ��    ��      ��    ��";
			Util().setXY(50, 12);
			cout << "        ��  ��                    ��  ��";
			Util().setXY(50, 13);
			cout << "          �����            �����";
			Util().setXY(50, 14);
			cout << "            ��    ���    ���    ��";
			Util().setXY(50, 15);
			cout << "          ��  ��      ���      ��  ��";
			Util().setXY(50, 16);
			cout << "          ��    ��            ��    ��";
			Util().setXY(50, 17);
			cout << "            ���  ��        ��  ���";
			Util().setXY(50, 18);
			cout << "            �����        �����";
			Util().setXY(50, 19);
			cout << "              ��                ��";
			Util().setXY(50, 20);
			cout << "                ���������";
			Util().setXY(50, 21);
			cout << "                ��    ���    ��";
			Util().setXY(50, 22);
			cout << "                 ���    ���";

			Sleep(100);
			Util().setColor(Util().white, Util().black);

			Util().setXY(50, 2);
			cout << "              �����������";
			Util().setXY(50, 3);
			cout << "            ���      ���      ���";
			Util().setXY(50, 4);
			cout << "          ���        ���        ���";
			Util().setXY(50, 5);
			cout << "          ��        �����        ��";
			Util().setXY(50, 6);
			cout << "          ��          ���          ��";
			Util().setXY(50, 7);
			cout << "        ��  ���      ���      ���  ��";
			Util().setXY(50, 8);
			cout << "        ��      ���������      ��";
			Util().setXY(50, 9);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 10);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 11);
			cout << "      ��    ��       _     _      ��    ��";
			Util().setXY(50, 12);
			cout << "        ��  ��                    ��  ��";
			Util().setXY(50, 13);
			cout << "          �����            �����";
			Util().setXY(50, 14);
			cout << "            ��    ���    ���    ��";
			Util().setXY(50, 15);
			cout << "          ��  ��      ���      ��  ��";
			Util().setXY(50, 16);
			cout << "          ��    ��            ��    ��";
			Util().setXY(50, 17);
			cout << "            ���  ��        ��  ���";
			Util().setXY(50, 18);
			cout << "            �����        �����";
			Util().setXY(50, 19);
			cout << "              ��                ��";
			Util().setXY(50, 20);
			cout << "                ���������";
			Util().setXY(50, 21);
			cout << "                ��    ���    ��";
			Util().setXY(50, 22);
			cout << "                 ���    ���";

			Sleep(100);
			Util().setColor(Util().white, Util().black);

			Util().setXY(50, 2);
			cout << "              �����������";
			Util().setXY(50, 3);
			cout << "            ���      ���      ���";
			Util().setXY(50, 4);
			cout << "          ���        ���        ���";
			Util().setXY(50, 5);
			cout << "          ��        �����        ��";
			Util().setXY(50, 6);
			cout << "          ��          ���          ��";
			Util().setXY(50, 7);
			cout << "        ��  ���      ���      ���  ��";
			Util().setXY(50, 8);
			cout << "        ��      ���������      ��";
			Util().setXY(50, 9);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 10);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 11);
			cout << "      ��    ��       _     _      ��    ��";
			Util().setXY(50, 12);
			cout << "        ��  ��                    ��  ��";
			Util().setXY(50, 13);
			cout << "          �����            �����";
			Util().setXY(50, 14);
			cout << "            ��    ���    ���    ��";
			Util().setXY(50, 15);
			cout << "          ��  ��      ���      ��  ��";
			Util().setXY(50, 16);
			cout << "          ��    ��            ��    ��";
			Util().setXY(50, 17);
			cout << "            ���  ��        ��  ���";
			Util().setXY(50, 18);
			cout << "            �����        �����";
			Util().setXY(50, 19);
			cout << "              ��                ��";
			Util().setXY(50, 20);
			cout << "                ���������";
			Util().setXY(50, 21);
			cout << "                ��    ���    ��";
			Util().setXY(50, 22);
			cout << "                 ���    ���";

			Sleep(100);

			Util().setXY(50, 2);
			cout << "              �����������";
			Util().setXY(50, 3);
			cout << "            ���      ���      ���";
			Util().setXY(50, 4);
			cout << "          ���        ���        ���";
			Util().setXY(50, 5);
			cout << "          ��        �����        ��";
			Util().setXY(50, 6);
			cout << "          ��          ���          ��";
			Util().setXY(50, 7);
			cout << "        ��  ���      ���      ���  ��";
			Util().setXY(50, 8);
			cout << "        ��      ���������      ��";
			Util().setXY(50, 9);
			cout << "      ��      ��                ��      ��";
			Util().setXY(50, 10);
			cout << "      ��      ��    ��    ��    ��      ��";
			Util().setXY(50, 11);
			cout << "      ��    ��      ��    ��      ��    ��";
			Util().setXY(50, 12);
			cout << "        ��  ��                    ��  ��";
			Util().setXY(50, 13);
			cout << "          �����            �����";
			Util().setXY(50, 14);
			cout << "            ��    ���    ���    ��";
			Util().setXY(50, 15);
			cout << "          ��  ��      ���      ��  ��";
			Util().setXY(50, 16);
			cout << "          ��    ��            ��    ��";
			Util().setXY(50, 17);
			cout << "            ���  ��        ��  ���";
			Util().setXY(50, 18);
			cout << "            �����        �����";
			Util().setXY(50, 19);
			cout << "              ��                ��";
			Util().setXY(50, 20);
			cout << "                ���������";
			Util().setXY(50, 21);
			cout << "                ��    ���    ��";
			Util().setXY(50, 22);
			cout << "                 ���    ���";

			sprite++;
		}

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

		int price;

		Util().setXY(53, 25);
		cout << "ü��ȸ�� ��� :"<<player.getPlayer().gold*0.3;
		price = player.getPlayer().gold*0.3;
		Util().setXY(53, 27);
		cout << "������ ���͵帱���?. (ü��ȸ�� (h), ������(q)) : ";
		cin >> s;
		cin.clear();
		if (s == tolower('q'))// tolower - �ڵ��� �ҹ��� ��ȯ
		{
			map = 0;
			play = false;
			done = true;
		}
		else
		{
			if (s == tolower('h'))
			{
				player.setPlayer().gold -= price;

				player.setPlayer().hpCur = player.getPlayer().hpMax;

				Util().setXY(53, 28);
				cout << "�����մϴ�, ������ �� ������!" << endl;
				Sleep(1000);
				return;
			}
		}
	}
}

void Shop::sGetItem(const string & itemName, Item & item)
{
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++)
	{
		if ((*i).getName() == itemName)
		{
			item = *i;
		}
	}
}

bool Shop::sSellItem(Player & player)
{
	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);
	cout << "������ ��ǰ�� ��������. :";
	string name;
	cin.ignore(1024, '\n');
	getline(cin, name);
	cin.ignore(1024, '\n');
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "������ ��ǰ�� ��������. :                        ";

	Item item;
	sGetItem(name, item); //������ǰã�� �����ۿ� �ִ´�

	if (item.getName() == "����")//���� ��ã����
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "�׷� ��ǰ�� �����ϴ�.";
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "�׷� ��ǰ�� �����ϴ�.";
		Util().setColor(Util().white, Util().black);	
		return false;
	}

	if (player.buyItem(item) == false) //���� ���ϸ�
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "���� " << item.getPrice() - player.getPlayer().gold << "��ŭ �����մϴ�.";
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                  ";
		Util().setColor(Util().white, Util().black);

		return false;
	}
	else
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);
		cout << "�������� �Ǹ� �߽��ϴ�." << endl;
		sDelItem(name);
		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                  ";
		Util().setColor(Util().white, Util().black);
		return true;
	}
	
	return true;
}

bool Shop::sBuyItem(Player & player)
{
	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << "�Ǹ��� ��ǰ�� �����ּ���. ���Ǹ� ������ ���������� 60%�Դϴ�. : ";
	string name;	
	cin.ignore(1024, '\n');
	getline(cin, name);

	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "�Ǹ��� ��ǰ�� �����ּ���. ���Ǹ� ������ ���������� 60%�Դϴ�. :                                           ";

	Item item;
	player.getItem(name, item);

	if (item.getName() == "����")
	{
		Util().setXY(4, 24);
		Util().setColor(Util().white, Util().black);

		cout << "����� ��������.";

		Sleep(500);
		Util().setXY(4, 24);
		Util().setColor(Util().black, Util().black);
		cout << "                                                            ";
		Util().setColor(Util().white, Util().black);
		return false;
	}

	int price = static_cast<int>(item.getPrice() *0.6);

	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << name << "�� " << price << " �� ���ݿ� �Ǹ��Ҽ� �ֽ��ϴ�.";

	Sleep(500);
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "                                                             ";
	Util().setColor(Util().white, Util().black);

	sAddItem(item);
	player.sellItem(name, price);

	Util().setXY(4, 24);
	Util().setColor(Util().white, Util().black);

	cout << name << "�� �Ǹ� �߽��ϴ�.";

	Sleep(500);
	Util().setXY(4, 24);
	Util().setColor(Util().black, Util().black);
	cout << "                                                            ";
	Util().setColor(Util().white, Util().black);

	return true;
}

void Shop::showShop(int x, int y)
{
}

void Shop::showShopList(int x, int y)
{
	int num = 1;
	for (list<Item>::iterator i = itemList.begin(); i != itemList.end(); i++,num++)
	{	
		Util().setXY(x, y + num);		
		cout << num << ".\t" << (*i).getName() << " X " << (*i).getCount() << "| ���� �� : " << (*i).getPrice()<<endl;				
	}

}

#include "Item.h"

void Item::addItem()
{
	if (_count < 99) //�ִ� ���� 99����
	{
		_count++;
	}
}

void Item::delItem()
{
	if (_count > 0)//�ʿ� ������ ���� ���� �������
	{
		_count--;
	}
}

Item::~Item()
{
}

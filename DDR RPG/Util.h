#pragma once
#include "DDR RPG.h"

class Util
{
public:
	//�� ����
	enum
	{
		black,		//��
		blue,		//��
		green,		//��
		cyan,		//�ϴ�
		red,		//��
		purple,		//��
		yellow,		//��
		lightgray,	//��ȸ
		darkgray,	//��ȸ
		lightblue,	//����
		lightgreen,	//����
		lightcyan,	//����
		lightred,	//�໡
		lightpurple,//�ຸ
		lightyellow,//���
		white		//�Ͼ�
	};

	//��ġ ����
	void setXY(const float x, const float y);
	
	//�̵�
	void move(unsigned char map[][149],const int dirX, const int dirY,int& p_X, int& p_Y,int& pMap, bool& inMap);//�� ����,�̵�����X,�̵�����Y,�̵��ϴ� ������Ʈ ��ǥ X,Y,��ƮŻ��

	//Ŀ�� ������
	void setHide();

	//�� ����
	void setColor(const int fGround, const int bGround);

	bool _battle01;

	bool getBattle01() { return _battle01; }
	void setBattle01(bool battle01) { battle01 = _battle01; }

	Util();
	~Util();
};


#pragma once
#include "Dxlib.h"
#include "target.h"

class Bonus
{
public:

	int point;						//�X�R�A���Z

	bool aliveflag;					//���������������

	bool blueflag;
	bool blueflag2;
	bool blueflag3;
	bool blueflag4;

	void Init();					//������
	void Update(Player&player);		//���Ղ�
};
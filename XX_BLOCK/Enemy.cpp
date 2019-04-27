#include "Enemy.h"
//�G�̏�����
void Enemy::Init()
{
	//�G�摜
	Graph = LoadGraph("data/texture/redbox.png");
	//�G�̗�
	Life = 3;
	//�K�����W
	X = 540;//�ŏ��̈�̂�0.0�ɏo�邱�Ƃ̏C���A�o���ʒu�͉�ʓ��H
	Y = 540;
	GetGraphSize(Graph, &W, &H);
	enemyShotintarvalcount = 30;
	HitFlag = true;
	point = 200;
	sector = 0;
	sectorvec = 0;
	sectorflag = false;
	outside_screen = true;
	aliveFlag = false;
}
//�G�̍X�V
void Enemy::Update(Player&player,Scr&scr)
{
	if (aliveFlag == true)
	{
		HitFlag = true;
	}

	if (enemyShotintarvalcount != 0)//�@�\�m�F�ς�
	{
		enemyShotintarvalcount--;
	}
	//
	if (enemyShotintarvalcount == 0)
	{
		sectorvec = 0;

		if (sector - 2 == -2)
		{
			sectorvec -= DX_PI_F / 3;
		}
		if (sector - 2 == -1)
		{
			sectorvec -= DX_PI_F / 6;
		}
		if (sector - 2 == 0)
		{
			sectorvec = 0;
		}
		if (sector - 2 == 1)
		{
			sectorvec += DX_PI_F / 6;
		}
		if (sector - 2 == 2)
		{
			sectorvec += DX_PI_F / 3;
		}

		if (sector >= 4)
		{
			sectorflag = true;
		}
		if (sector <= 0)
		{
			sectorflag = false;
		}

		if (sectorflag == false)
		{
			sector ++;
		}
		if (sectorflag == true)
		{
			sector --;
		}
	}

	if (X >= SCREEN_W + scr.scrX)//�X�N���[���̉E�[�O
	{
		outside_screen = true;
	}
	if (X + W <= scr.scrX)
	{
		outside_screen = true;
	}
	if (Y + H <= scr.scrY)
	{
		outside_screen = true;
	}
	if (Y >= SCREEN_H + scr.scrY)
	{
		outside_screen = true;
	}
	
	//
	if(X < 64)
	{
		X = 64;
	}
	if(X + 64 > SCREEN_W + 1920)
	{
		X = SCREEN_W + 1920 - 256;
	}
	if (Y < 64)
	{
		Y = 64;
	}
	if (Y + 64 > SCREEN_H + 1080)
	{
		Y = SCREEN_H + 1080 - 256;
	}

	//��ʓ�
	if ((X + W < SCREEN_W + scr.scrX && X > 64 + scr.scrX) && (Y > 64 + scr.scrY && Y + H < SCREEN_H + scr.scrY))
	{
		outside_screen = false;
	}

	//�̗͂O�Ȃ�����悤��
	if (Life <= 0)
	{
		aliveFlag = false;
	}
	if (aliveFlag == false)
	{
		player.score += point;
		player.scoreflag = true;
		HitFlag = false;
		outside_screen =false;
		Life = 3;
		
	}
}
//�G�̕`��
void Enemy::Draw(Scr&scr)
{
    if (aliveFlag == true)//�����͓����Ă���
    {
            DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY,0.0,0.0,1.5,0.0, Graph, TRUE);
    }
}
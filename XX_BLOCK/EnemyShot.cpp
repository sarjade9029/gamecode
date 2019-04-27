#include "EnemyShot.h"
void EnemyShot::Init()
{
	enemyShotGraph = LoadGraph("data/texture/test.png");//�摜�̓Ǎ�
	GetGraphSize(enemyShotGraph, &enemyShotW, &enemyShotH);//�摜�̏c���ǂ݂Ƃ�
	speed = 5;
	enemyShotX = 0;//���W�̏�����
	enemyShotY = 0;
	enemyShotDmg = 1;
	angle = 0;
	NumericAngle = 0;
	enemyShotflag = false;//���Ă��Ԃɂ��Ă���
	enemyShotVisibleFlag = false;
	sectorvec = 0;
}

void EnemyShot::enemyShotSet(Player&player,Enemy&enemy)
{
	enemyShotX = enemy.X + (enemy.W * 0.75);//�G�̒���
	enemyShotY = enemy.Y + (enemy.H * 0.75);//�G�̒���
	enemyShotX = enemyShotX - (enemyShotW * 0.5);
	enemyShotY = enemyShotY - (enemyShotH * 0.5);
	NumericAngle = atan2f((float)(player.Y + (player.H * 0.75) - enemyShotY), (float)(player.X + (player.W * 0.75) - enemyShotX));//�X�̐��l��������Ă���
	angle = - NumericAngle * 180 / DX_PI_F ;
	sectorvec = enemy.sectorvec;
	if (enemyShotflag == false && enemy.HitFlag == true)
	{
		enemyShotflag = true;//��������ɐi�ނ悤�ɂ���
		enemyShotVisibleFlag = true;//������悤�ɂ���
	}
	enemy.enemyShotintarvalcount = 30;//�҂����Ԃ���͓����Ă���
}

void EnemyShot::Update(Scr&scr)
{
	if (enemyShotflag == true)
	{
		enemyShotX += cosf(NumericAngle + sectorvec) * speed;//����
		enemyShotY += sinf(NumericAngle + sectorvec) * speed;
	}
	if (/*enemyShotX > SCREEN_W + enemyShotW + scr.scrX ||*/ enemyShotX < 63 || enemyShotY < 63 /*|| enemyShotY > SCREEN_H + enemyShotH + scr.scrY*/ || enemyShotX > SCREEN_W * 2 - (enemyShotW + 64) || enemyShotY > SCREEN_H * 2 - (enemyShotH + 48) || enemyShotX < scr.scrX || enemyShotY <scr.scrY)//�����Ă��Ȃ�������e�̋��������������Ȃ�A�����Ȃ���
	{
		enemyShotVisibleFlag = false;//�O�ɏo���猩���Ȃ�����
	}
	if (enemyShotVisibleFlag == false)
	{
		enemyShotflag = false;//���Ă��Ԃɖ߂�
	}
}

void EnemyShot::Draw(Scr&scr)
{
	if (enemyShotVisibleFlag == true)
	{
		DrawRotaGraph2F(enemyShotX - scr.scrX + (enemyShotW * 0.5),enemyShotY - scr.scrY + (enemyShotH * 0.5),(enemyShotW * 0.5), (enemyShotH * 0.5),1.0,(double)NumericAngle + sectorvec,enemyShotGraph,TRUE);//�\��
	}
}
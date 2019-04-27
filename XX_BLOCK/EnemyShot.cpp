#include "EnemyShot.h"
void EnemyShot::Init()
{
	enemyShotGraph = LoadGraph("data/texture/test.png");//‰æ‘œ‚Ì“Çž
	GetGraphSize(enemyShotGraph, &enemyShotW, &enemyShotH);//‰æ‘œ‚Ìc‰¡“Ç‚Ý‚Æ‚è
	speed = 5;
	enemyShotX = 0;//À•W‚Ì‰Šú‰»
	enemyShotY = 0;
	enemyShotDmg = 1;
	angle = 0;
	NumericAngle = 0;
	enemyShotflag = false;//Œ‚‚Ä‚éó‘Ô‚É‚µ‚Ä‚¨‚­
	enemyShotVisibleFlag = false;
	sectorvec = 0;
}

void EnemyShot::enemyShotSet(Player&player,Enemy&enemy)
{
	enemyShotX = enemy.X + (enemy.W * 0.75);//“G‚Ì’†‰›
	enemyShotY = enemy.Y + (enemy.H * 0.75);//“G‚Ì’†‰›
	enemyShotX = enemyShotX - (enemyShotW * 0.5);
	enemyShotY = enemyShotY - (enemyShotH * 0.5);
	NumericAngle = atan2f((float)(player.Y + (player.H * 0.75) - enemyShotY), (float)(player.X + (player.W * 0.75) - enemyShotX));//ŒÂX‚Ì”’l‚ª‚¢‚©‚ê‚Ä‚¢‚é
	angle = - NumericAngle * 180 / DX_PI_F ;
	sectorvec = enemy.sectorvec;
	if (enemyShotflag == false && enemy.HitFlag == true)
	{
		enemyShotflag = true;//Œ‚‚Á‚½Œã‚Éi‚Þ‚æ‚¤‚É‚·‚é
		enemyShotVisibleFlag = true;//Œ©‚¦‚é‚æ‚¤‚É‚·‚é
	}
	enemy.enemyShotintarvalcount = 30;//‘Ò‚¿ŽžŠÔ‚±‚ê‚Í“­‚¢‚Ä‚¢‚é
}

void EnemyShot::Update(Scr&scr)
{
	if (enemyShotflag == true)
	{
		enemyShotX += cosf(NumericAngle + sectorvec) * speed;//”½•œ
		enemyShotY += sinf(NumericAngle + sectorvec) * speed;
	}
	if (/*enemyShotX > SCREEN_W + enemyShotW + scr.scrX ||*/ enemyShotX < 63 || enemyShotY < 63 /*|| enemyShotY > SCREEN_H + enemyShotH + scr.scrY*/ || enemyShotX > SCREEN_W * 2 - (enemyShotW + 64) || enemyShotY > SCREEN_H * 2 - (enemyShotH + 48) || enemyShotX < scr.scrX || enemyShotY <scr.scrY)//“®‚¢‚Ä‚¢‚È‚©‚Á‚½‚ç’e‚Ì‹““®‚ª‚¨‚©‚µ‚­‚È‚éAÁ‚¦‚È‚¢‚µ
	{
		enemyShotVisibleFlag = false;//ŠO‚Éo‚½‚çŒ©‚¦‚È‚­‚µ‚Ä
	}
	if (enemyShotVisibleFlag == false)
	{
		enemyShotflag = false;//Œ‚‚Ä‚éó‘Ô‚É–ß‚·
	}
}

void EnemyShot::Draw(Scr&scr)
{
	if (enemyShotVisibleFlag == true)
	{
		DrawRotaGraph2F(enemyShotX - scr.scrX + (enemyShotW * 0.5),enemyShotY - scr.scrY + (enemyShotH * 0.5),(enemyShotW * 0.5), (enemyShotH * 0.5),1.0,(double)NumericAngle + sectorvec,enemyShotGraph,TRUE);//•\Ž¦
	}
}
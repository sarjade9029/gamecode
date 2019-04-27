#include "Player.h"
//�v���C���[�̏������`���[�g���A���p
void Player::Init()
{
	//�����̏�����
	direction = 0;
	direction2 = 0;
	shotIntervalCount = 15;
	Img = LoadGraph("data/texture/bluebox.png");
	Hp = 100;
    X = 912;
    Y = 492;
    Xs = 7;
    Ys = 7;
	addcounter = 1;
	witetime = 60;
	HitFlag = true;
	scoreflag = false;
	GetGraphSize(Img, &W, &H);
}

//�v���C���[�̍X�V
void Player::Update(Scr&scr)
{
	if (shotIntervalCount != 0)//�@�\�m�F�ς�
	{
		shotIntervalCount--;
	}
	if (witetime != 0)
	{
		witetime--;
	}
	if (scoreflag == true)
	{
		if (plscore <= score)
		{
			plscore++;
			plscore++;
			if (plscore == score)
			{
				scoreflag = false;
			}
		}
	}

	//���ړ�
    if (CheckHitKey(KEY_INPUT_A) == 1)
    {
		X -= Xs;
    }
	//�E�ړ�
    if (CheckHitKey(KEY_INPUT_D) == 1)
    {
		X += Xs;
    }
	//��ړ�
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		Y -= Ys;
	}
	//���ړ�
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		Y += Ys;
	}

	//�����ǔ���
	if (X > SCREEN_W - (W + 15 + 64) + scr.scrX)//�O�ɏo�悤�Ƃ���Ɩ߂����
	{
		X = SCREEN_W - (W + 15 + 64) + scr.scrX;//
	}
	if (X < 64)
	{
		X = 64;
	}
	if (Y < 64)
	{
		Y = 64;
	}
	if (Y > SCREEN_H - (H + 15 + 64) + scr.scrY)
	{
		Y = SCREEN_H - (H + 15 + 64) + scr.scrY;
	}

	//�e�̔��ː���ƕ����y��   ����m�F�ς�

	direction = 0;
	direction2 = 0;

	if (CheckHitKey(KEY_INPUT_UP))
	{
		direction = 8;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		direction = 2;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		direction = 6;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		direction = 4;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP))
	{
		direction = 4;
		direction2 = 8;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN))
	{
		direction = 4;
		direction2 = 2;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP))
	{
		direction = 6;
		direction2 = 8;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN))
	{
		direction = 6;
		direction2 = 2;
	}
	//�V�t�g�������Ȃ���Ȃ�K���e���΂߂ɂł�
	if (CheckHitKey(KEY_INPUT_LSHIFT) || CheckHitKey(KEY_INPUT_RSHIFT))
	{
		if (CheckHitKey(KEY_INPUT_UP))
		{
			direction = 0;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			direction = 0;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			direction = 0;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			direction = 0;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_UP))
		{
			direction = 4;
			direction2 = 8;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_DOWN))
		{
			direction = 4;
			direction2 = 2;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_UP))
		{
			direction = 6;
			direction2 = 8;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_DOWN))
		{
			direction = 6;
			direction2 = 2;
		}
	}

	if (Hp <= 0)
	{
		HitFlag = false;
	}

}

//�v���C���[�̕`��
void Player::Draw(Scr&scr)
{
	if (HitFlag == true)
	{
		DrawRotaGraph2F(X - scr.scrX,Y - scr.scrY,0,0,1.5,0.0,Img,TRUE);
	}
}
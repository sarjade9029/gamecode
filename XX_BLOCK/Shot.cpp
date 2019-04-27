#include "Shot.h"
#include "HitCheck.h"

//�e�̏�����
void Shot::Init()
{
    // �V���b�g�̃O���t�B�b�N���������Ƀ��[�h.
    Graph = LoadGraph("data/texture/blueshot.png");


    // �e����ʏ�ɑ��݂��Ă��邩�ێ�����ϐ��Ɂw���݂��Ă��Ȃ��x���Ӗ�����false�������Ă���
    VisibleFlag = false;
	directionflag = false;
	
	wite = 15;
	Dmg = 1;
    // �e�̃O���t�B�b�N�̃T�C�Y
    GetGraphSizeF(Graph, &W, &H);
	Ys = 10;
	Xs = 10;

	Shotflag = false;
}

void Shot::Setshot(Player* player)
{
	//�v���C���[�̉摜�̒��������
	//�v���C���[�̉����̒��S
	X = (player->X) + (player->W*0.75);
	//�v���C���[�̏c�̒��S
	Y = (player->Y) + (player->H*0.75);
	if (Shotflag == false && player->direction != 0)
	{
		VisibleFlag = true;
		directionflag = true;
		Shotflag = true;
	}
	//�����Ă���Ȃ�������͐����Ԃ点���Ȃ���������߂�
	if (Shotflag == true)
	{
		if (player->direction == 2 || player->direction2 == 2)
		{
			//�摜��]
			South = true;
		}
		if (player->direction == 4 || player->direction2 == 4)
		{
			//�摜��]
			West = true;
		}
		if (player->direction == 6 || player->direction2 == 6)
		{
			//�摜��]
			East = true;
		}
		if (player->direction == 8 || player->direction2 == 8)
		{
			//�摜��]
			North = true;
		}
		player->shotIntervalCount = wite;
	}

}

//�e�̍X�V(�e�̈ړ��Ɠ����蔻��
void Shot::Update(Scr&scr)
{
	if(directionflag == true)//�����Ă���
	{ 
		if (South == true)
		{
			Y += Ys;
		}
		if (North == true)
		{
			Y -= Ys;
		}
		if (West == true)
		{
			X -= Xs;
		}
		if (East == true)
		{
			X += Xs;
		}
	}
	if (X > SCREEN_W - W + scr.scrX|| X < 64 || Y < 64 || Y > SCREEN_H - H + scr.scrY || X > SCREEN_W * 2 - (W + 64) || Y > SCREEN_H * 2 - (H + 48) || X < scr.scrX || Y < scr.scrY)//�����Ă��Ȃ�������e�̋��������������Ȃ�A�����Ȃ���
	{
		VisibleFlag = false;
	}
	if (VisibleFlag == false)
	{
		directionflag = false;
		Shotflag = false;
		South = false;
		North = false;
		East = false;
		West = false;
	}
	
}

//�e�̕`��
void Shot::Draw(Scr&scr)
{
	//�ŏ��̈ꔭ�͉摜�����������Ȃ邱�Ƃ�����i�΂߂��`�悵�Ă���j
    if (VisibleFlag == true)
    {
        // ��ʂɒei��`�悷��
		if (South || North)
		{
			if (!East && !West)
			{
				DrawRotaGraph2F(X - scr.scrX,Y - scr.scrY,0.0,0.0,1.0, 0.0,Graph, TRUE);//�㉺
			}
		}
		if (East || West)
		{
			if (!South && !North)
			{
				DrawRotaGraph2F(X - scr.scrX,Y - scr.scrY,0.0,0.0,1.0, DX_PI_F/2,Graph, TRUE);//���E
			}
		}
		if ((North && East) || (South && West))
		{
			DrawRotaGraph2F(X - scr.scrX,Y - scr.scrY,0.0,0.0,1.0, DX_PI_F/4,Graph, TRUE);//�΂߉E��or����
		}
		if ((North && West) || (South && East))
		{
			DrawRotaGraph2F(X - scr.scrX,Y - scr.scrY,0.0,0.0,1.0, DX_PI_F*1.75,Graph, TRUE);//�΂ߍ���or�E��
		}
    }
}
#include "target.h"
void Tg::Init()
{
	//������
	redGraph = LoadGraph("data/texture/redtarget.png");
	redGraph2 = LoadGraph("data/texture/redtarget2.png");
	redGraph3 = LoadGraph("data/texture/redtarget3.png");
	redGraph1 = LoadGraph("data/texture/redtarget1.png");
	blueGraph = LoadGraph("data/texture/bluetarget.png");
	blueGraph2 = LoadGraph("data/texture/bluetarget2.png");
	blueGraph3 = LoadGraph("data/texture/bluetarget3.png");
	blueGraph1 = LoadGraph("data/texture/bluetarget1.png");
	grayGraph= LoadGraph("data/texture/graytarget.png");
	Thp = -5;
	Ppt = 0;
	Ept = 0;
	X = 0;//�Œ�ʒu�l��������
	Y = 0;
	ux = 0;
	uy = 0;
	GetGraphSize(redGraph,&W,&H);
	PptFlag = false;
	EptFlag = false;
}

void Tg::Update()
{
	if (Thp >= 1)
	{
		//�N���X�^���̐F�ύX�i�j
		if (Thp > 4)
		{
			Thp = 4;//�F
		}
		PptFlag = true;	
	}
	if (Thp >= 1 && Thp <= 3)
	{
		PptFlag = false;
	}
	if (Thp == 0)
	{
		//�N���X�^���̐F�i���Z�b�g�j
		PptFlag = false;
		EptFlag = false;
	}
	if(Thp <= -1 && Thp >= 3)
	{
		EptFlag = false;
	}
	if (Thp <= -1)
	{
		//�N���X�^���̐F�ύX�i�ԁj
		if (Thp < -4)
		{
			Thp = -4;//�ԐF
		}
		EptFlag = true;
	}
}

void Tg::Draw(Scr&scr)
{
	//�N���X�^���̕`��
	if (Thp != 0)
	{
		//�\��

		if (PptFlag == true)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, blueGraph, TRUE);
		}
		if (Thp == 3)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, blueGraph3, TRUE);
		}
		if (Thp == 2)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, blueGraph2, TRUE);
		}
		if (Thp == 1)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, blueGraph1, TRUE);
		}

		//�ԕ\��
		if (EptFlag == true)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, redGraph, TRUE);
		}
		if (Thp == -3)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, redGraph3, TRUE);
		}
		if (Thp == -2)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, redGraph2, TRUE);
		}
		if (Thp == -1)
		{
			DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, redGraph1, TRUE);
		}
	}
	else
	{
		DrawRotaGraph2F(X - scr.scrX, Y - scr.scrY, 0.0, 0.0, 1.55, 0.0, grayGraph, TRUE);
	}

	//32*i+1=���o�𓥂܂����l
	//�Ԋu�J���̂��߂̐���
	//1920-128=�`��ʒu
	//�����͌X��hp�ƍ��킹��΂���
	//�ēx���������̂�`��
	//�`��̖��
	

	if (Thp != 0)
	{
		//�\��
		if (PptFlag == true)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, blueGraph, TRUE);
		}
		if (Thp == 3)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, blueGraph3, TRUE);
		}
		if (Thp == 2)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, blueGraph2, TRUE);
		}
		if (Thp == 1)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, blueGraph1, TRUE);
		}

		//�ԕ\��
		if (EptFlag == true)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, redGraph, TRUE);
		}
		if (Thp == -3)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, redGraph3, TRUE);
		}
		if (Thp == -2)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, redGraph2, TRUE);
		}
		if (Thp == -1)
		{
			DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, redGraph1, TRUE);
		}
	}
	else
	{
		DrawRotaGraph2F(ux, uy, 0.0, 0.0, 1.55, 0.0, grayGraph, TRUE);
	}

}
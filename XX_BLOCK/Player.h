#pragma once
#include "Shot.h"
#include "Scr.h"
#include "DxLib.h"
#include "Common.h"

class Player
{
public:
	int		direction;					//�e�̕�����
	int		direction2;					//�e�̕������΂ߗp
	int		shotIntervalCount;			//�O��ł����e�����Ƃɍ������Ă�����
    int		Hp;							//�̗�
	int		W;							//����
	int		H;							//�c��
    int		Xs;							//�����x
    int		Ys;							//�c���x
    int		Img;						//�摜
	int		witetime;					
	int		score;						//�X�R�A
	int		plscore;					//�\�������X�R�A
	int		addcounter;					//�q�@�̐�
    float	X;							//
    float	Y;							//
	bool	scoreflag;					//�X�R�A�C���N�������g�v�Z�p
	bool	HitFlag;					
    void	Init();						//
    void	Update(Scr&scr);			//
	void	CheckAdd(Add&add);			//2 3 4 5(2 + 3) 6(4 + 2) 7(4 + 3) 9(2 + 3 + 4)
    void	Draw(Scr&scr);				//
};
#pragma once
#include "DxLib.h"
#include "Scr.h"
class Tg
{
public:
	int Thp;			//�^�[�Q�b�g�ׂ̍������
	int Ppt;			//�v���C���[�̃|�C���g
	int Ept;			//�G�̃|�C���g
	int X;				//�����W
	int Y;				//�c���W
	int H;
	int W;
	int ux;
	int uy;
	int redGraph;
	int	redGraph2;			//3�i�K
	int	redGraph3;			//2�i�K
	int	redGraph1;			//1�i�K
	int blueGraph;
	int	blueGraph2;			//3�i�K
	int	blueGraph3;			//2�i�K
	int	blueGraph1;			//1�i�K
	int grayGraph;
	bool Visibleflag;
	bool HitFlag;
	bool PptFlag;			//�|�C���g�l���̃t���O
	bool EptFlag;			//�G�̃|�C���g�l���̃t���O
	
	void Init();			//������
	void Update();			//�X�V
	void Draw(Scr&scr);		//�`��
};
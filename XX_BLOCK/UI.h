#pragma once
#include "DxLib.h"
#include "Common.h"
#include "target.h"
#include "bitmapText.h"
class UI
{
public:

	int		mainmusic;							//���C����
	int		shothit;							//�V���b�g�̉�
	int		titleGraph;							//�^�C�g���摜
	int		endGraph;							//�I���̉摜
	int		framenum;							//�Q�[���J�n�i�^�C�g������ł͂Ȃ��v���C�j����̎���
	int		starttime;							//�Q�[���J�n�i�^�C�g���ӂ肩��j
	int		zerotime;							//���̃^�C�~���O�łƂ�
	int		drawtime;							//�`��p�̎���
	int		waittime;
	int     tutgraph;
	int     tutgraph2;
	int		shiftGraph;
	int		textGraph;
	int		textGraph2;
	int		textGraph3;
	int		textGraph4;
	int		enemycount;
	int		enemycount2;
	int		enemycount3;
	int		enemycount4;
	int		cs[TARGET];							//ui�p�摜
	void	Init(BitmapText & text);			//
	void	Draw(Tg&target);					//

};
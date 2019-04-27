#pragma once
#include "DxLib.h"
#include "Scr.h"
#include "Common.h"
#include "Enemy.h"
#include "player.h"

class Player;
//����g�����̂����u���ĂȂ�
class Shot
{
public:
	//shot_state
    double		X;
    double		Y;
    int		Xs;
    int		Ys;
	int		Dmg;
	int		wite;					//���̒e���܂ő҂Ă�
    bool	VisibleFlag;			//�`��p
    bool	Shotflag;               // �����Ă��邽�܂��H

	//shot_graph
    int		Graph;					//�������Ȃ�
    float		W;						//����
    float		H;						//�c��

	//shot_vector
	bool	East;					//�e�͓��ɐi��
	bool	West;					//�e�͐��ɐi��
	bool	South;					//�e�͓�ɐi��
	bool	North;					//�e�͖k�ɐi��
	bool	directionflag;			//���p�w��


    void	Init();						//������
	void    Setshot( Player* player );
    void	Update(Scr&scr);
    void	Draw(Scr&scr);

};

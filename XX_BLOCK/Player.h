#pragma once
#include "Shot.h"
#include "Scr.h"
#include "DxLib.h"
#include "Common.h"

class Player
{
public:
	int		direction;					//弾の方向性
	int		direction2;					//弾の方向性斜め用
	int		shotIntervalCount;			//前回打った弾をもとに今撃っていいか
    int		Hp;							//体力
	int		W;							//横幅
	int		H;							//縦幅
    int		Xs;							//横速度
    int		Ys;							//縦速度
    int		Img;						//画像
	int		witetime;					
	int		score;						//スコア
	int		plscore;					//表示されるスコア
	int		addcounter;					//子機の数
    float	X;							//
    float	Y;							//
	bool	scoreflag;					//スコアインクリメント計算用
	bool	HitFlag;					
    void	Init();						//
    void	Update(Scr&scr);			//
	void	CheckAdd(Add&add);			//2 3 4 5(2 + 3) 6(4 + 2) 7(4 + 3) 9(2 + 3 + 4)
    void	Draw(Scr&scr);				//
};
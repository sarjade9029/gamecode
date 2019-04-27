#pragma once
#include "DxLib.h"
#include "Scr.h"
#include "Common.h"
#include "Enemy.h"
#include "player.h"

class Player;
//Œ»óg‚¤‚à‚Ì‚µ‚©’u‚¢‚Ä‚È‚¢
class Shot
{
public:
	//shot_state
    double		X;
    double		Y;
    int		Xs;
    int		Ys;
	int		Dmg;
	int		wite;					//Ÿ‚Ì’eŒ‚‚Â‚Ü‚Å‘Ò‚Ä‚æ
    bool	VisibleFlag;			//•`‰æ—p
    bool	Shotflag;               // ‚¢‚«‚Ä‚¢‚é‚½‚Ü‚©H

	//shot_graph
    int		Graph;					//‰¼‚µ‚©‚È‚¢
    float		W;						//‰¡•
    float		H;						//c•

	//shot_vector
	bool	East;					//’e‚Í“Œ‚Éi‚Ş
	bool	West;					//’e‚Í¼‚Éi‚Ş
	bool	South;					//’e‚Í“ì‚Éi‚Ş
	bool	North;					//’e‚Í–k‚Éi‚Ş
	bool	directionflag;			//•ûŠpw’è


    void	Init();						//‰Šú‰»
	void    Setshot( Player* player );
    void	Update(Scr&scr);
    void	Draw(Scr&scr);

};

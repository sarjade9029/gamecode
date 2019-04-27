#include "hitcheck.h"

//“ü‚ê‚éêŠ‚Í‚»‚ê‚¼‚êˆá‚¤


void HitCheck::hitcheck_pes(Player& player,EnemyShot& enemyshot,UI&ui)
{
	//“G’e‚ÆƒvƒŒƒCƒ„[‚ÌÀ•W
	if (enemyshot.enemyShotVisibleFlag == true && player.HitFlag == true)
	{
		// ƒGƒlƒ~[‚Æ’e‚Ì“–‚½‚è”»’è
		if (((enemyshot.enemyShotX > player.X && enemyshot.enemyShotX < player.X + player.W * 1.5) ||
			(player.X > enemyshot.enemyShotX && player.X < enemyshot.enemyShotX + enemyshot.enemyShotW)) &&
			((enemyshot.enemyShotY > player.Y && enemyshot.enemyShotY < player.Y + player.H * 1.5) ||
			(player.Y > enemyshot.enemyShotY && player.Y < enemyshot.enemyShotY + enemyshot.enemyShotH)))
		{
			// ÚG‚µ‚Ä‚¢‚éê‡‚Í“–‚½‚Á‚½’e‚Ì‘¶Ý‚ðÁ‚·
			enemyshot.enemyShotVisibleFlag = false;
			//‚±‚±‚É“Gƒ_ƒ[ƒWˆ—‚ð“ü‚ê‚é
			player.Hp -= enemyshot.enemyShotDmg;
			PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
		}
	}
}

void HitCheck::hitcheck_pse(Shot& shot,Enemy& enemy,UI&ui)
{
	//Ž©’e‚Æ“G‚ÌÀ•W
	if (shot.VisibleFlag == true && enemy.HitFlag == true)
	{
		if (shot.East || shot.West)
		{
			if (!shot.South && !shot.North)
			{
				if (((shot.X > enemy.X && shot.X < enemy.X + enemy.W * 1.5) ||
					(enemy.X > shot.X && enemy.X < shot.X + shot.H)) &&
					((shot.Y > enemy.Y && shot.Y < enemy.Y + enemy.H * 1.5) ||
					(enemy.Y > shot.Y && enemy.Y < shot.Y + shot.W)))
				{
					// ÚG‚µ‚Ä‚¢‚éê‡‚Í“–‚½‚Á‚½’e‚Ì‘¶Ý‚ðÁ‚·
					shot.VisibleFlag = false;
					//‚±‚±‚É“Gƒ_ƒ[ƒWˆ—‚ð“ü‚ê‚é
					enemy.Life -= shot.Dmg;
					PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
				}
			}
		}
		// ƒGƒlƒ~[‚Æ’e‚Ì“–‚½‚è”»’è
		if (((shot.X > enemy.X && shot.X < enemy.X + enemy.W * 1.5) ||
			(enemy.X > shot.X && enemy.X < shot.X + shot.W)) &&
			((shot.Y > enemy.Y && shot.Y < enemy.Y + enemy.H * 1.5) ||
			(enemy.Y > shot.Y && enemy.Y < shot.Y + shot.H)))
		{
			// ÚG‚µ‚Ä‚¢‚éê‡‚Í“–‚½‚Á‚½’e‚Ì‘¶Ý‚ðÁ‚·
			shot.VisibleFlag = false;
			//‚±‚±‚É“Gƒ_ƒ[ƒWˆ—‚ð“ü‚ê‚é
			enemy.Life -= shot.Dmg;
			PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
		}
	}
}

void HitCheck::hitcheck_psc(Tg& target, Shot&shot,UI&ui)
{
	if (shot.VisibleFlag == true && target.Thp < 4)
	{
		// ƒ^[ƒQƒbƒg‚ÆŽ©’e‚Ì“–‚½‚è”»’è
		if (((shot.X > target.X && shot.X < target.X + target.W * 1.55) ||
			(target.X > shot.X && target.X < shot.X + shot.W)) &&
			((shot.Y > target.Y && shot.Y < target.Y + target.H * 1.55) ||
			(target.Y > shot.Y && target.Y < shot.Y + shot.H)))
		{
			// ÚG‚µ‚Ä‚¢‚éê‡‚Í“–‚½‚Á‚½’e‚Ì‘¶Ý‚ðÁ‚·
			shot.VisibleFlag = false;
			//‚±‚±‚ÉƒNƒŠƒXƒ^ƒ‹ƒ_ƒ[ƒWˆ—‚ð“ü‚ê‚éF‚Ì•ÏX‚Ítarget.update‚É‚ ‚é
			target.Thp += shot.Dmg;
		}
	}
}

void HitCheck::hitcheck_pc(Tg& target, Player&player)
{
	if (player.HitFlag == true && target.Thp < 5)
	{
		// ƒ^[ƒQƒbƒg‚ÆŽ©’e‚Ì“–‚½‚è”»’è
		if (((player.X > target.X && player.X < target.X + target.W * 1.55) ||
			(target.X > player.X && target.X < player.X + player.W * 1.5)) &&
			((player.Y > target.Y && player.Y < target.Y + target.H * 1.55) ||
			(target.Y > player.Y && target.Y < player.Y + player.H * 1.5)))
		{
			//ÚG‚µ‚Ä‚¢‚é‚¾‚¯,hp‚Æˆø‚«Š·‚¦‚É‘ŠŽè‚Éƒ_ƒ[ƒWH
			//‚±‚±‚ÅŽ~‚ß‚é‚È‚è–ß‚·‚È‚è‚·‚é
			if (player.X > target.X && player.X <= target.X + target.W * 1.55)
			{
				player.X = target.X + target.W * 1.55 + 7;
			}
		}
		else
		{
			player.Ys = 7;
			player.Xs = 7;
		}
	}
}
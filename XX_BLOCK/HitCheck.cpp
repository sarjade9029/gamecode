#include "hitcheck.h"

//�����ꏊ�͂��ꂼ��Ⴄ


void HitCheck::hitcheck_pes(Player& player,EnemyShot& enemyshot,UI&ui)
{
	//�G�e�ƃv���C���[�̍��W
	if (enemyshot.enemyShotVisibleFlag == true && player.HitFlag == true)
	{
		// �G�l�~�[�ƒe�̓����蔻��
		if (((enemyshot.enemyShotX > player.X && enemyshot.enemyShotX < player.X + player.W * 1.5) ||
			(player.X > enemyshot.enemyShotX && player.X < enemyshot.enemyShotX + enemyshot.enemyShotW)) &&
			((enemyshot.enemyShotY > player.Y && enemyshot.enemyShotY < player.Y + player.H * 1.5) ||
			(player.Y > enemyshot.enemyShotY && player.Y < enemyshot.enemyShotY + enemyshot.enemyShotH)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			enemyshot.enemyShotVisibleFlag = false;
			//�����ɓG�_���[�W����������
			player.Hp -= enemyshot.enemyShotDmg;
			PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
		}
	}
}

void HitCheck::hitcheck_pse(Shot& shot,Enemy& enemy,UI&ui)
{
	//���e�ƓG�̍��W
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
					// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
					shot.VisibleFlag = false;
					//�����ɓG�_���[�W����������
					enemy.Life -= shot.Dmg;
					PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
				}
			}
		}
		// �G�l�~�[�ƒe�̓����蔻��
		if (((shot.X > enemy.X && shot.X < enemy.X + enemy.W * 1.5) ||
			(enemy.X > shot.X && enemy.X < shot.X + shot.W)) &&
			((shot.Y > enemy.Y && shot.Y < enemy.Y + enemy.H * 1.5) ||
			(enemy.Y > shot.Y && enemy.Y < shot.Y + shot.H)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shot.VisibleFlag = false;
			//�����ɓG�_���[�W����������
			enemy.Life -= shot.Dmg;
			PlaySoundMem(ui.shothit, DX_PLAYTYPE_BACK);
		}
	}
}

void HitCheck::hitcheck_psc(Tg& target, Shot&shot,UI&ui)
{
	if (shot.VisibleFlag == true && target.Thp < 4)
	{
		// �^�[�Q�b�g�Ǝ��e�̓����蔻��
		if (((shot.X > target.X && shot.X < target.X + target.W * 1.55) ||
			(target.X > shot.X && target.X < shot.X + shot.W)) &&
			((shot.Y > target.Y && shot.Y < target.Y + target.H * 1.55) ||
			(target.Y > shot.Y && target.Y < shot.Y + shot.H)))
		{
			// �ڐG���Ă���ꍇ�͓��������e�̑��݂�����
			shot.VisibleFlag = false;
			//�����ɃN���X�^���_���[�W����������F�̕ύX��target.update�ɂ���
			target.Thp += shot.Dmg;
		}
	}
}

void HitCheck::hitcheck_pc(Tg& target, Player&player)
{
	if (player.HitFlag == true && target.Thp < 5)
	{
		// �^�[�Q�b�g�Ǝ��e�̓����蔻��
		if (((player.X > target.X && player.X < target.X + target.W * 1.55) ||
			(target.X > player.X && target.X < player.X + player.W * 1.5)) &&
			((player.Y > target.Y && player.Y < target.Y + target.H * 1.55) ||
			(target.Y > player.Y && target.Y < player.Y + player.H * 1.5)))
		{
			//�ڐG���Ă��邾��,hp�ƈ��������ɑ���Ƀ_���[�W�H
			//�����Ŏ~�߂�Ȃ�߂��Ȃ肷��
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
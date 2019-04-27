#pragma once
#include "DxLib.h"
#include "Shot.h"
#include "Enemy.h"
#include "target.h"
#include "EnemyShot.h"
#include "Player.h"
#include "Common.h"
#include "UI.h"
class HitCheck
{
public:
	//�v���C���[�ƓG�e�̓����蔻��
	void hitcheck_pes(Player& player,EnemyShot& enemyshot,UI& ui);

	//���e�ƓG�̓����蔻��
	void hitcheck_pse(Shot& shot,Enemy& enemy,UI& ui);

	//���e�ƃN���X�^���̓����蔻��
	void hitcheck_psc(Tg& target,Shot& shot,UI& ui);

	//���@�ƃN���X�^���̓����蔻��(����
	void hitcheck_pc(Tg& target,Player& player);
};
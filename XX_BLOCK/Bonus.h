#pragma once
#include "Dxlib.h"
#include "target.h"

class Bonus
{
public:

	int point;						//ƒXƒRƒA‰ÁZ

	bool aliveflag;					//ğŒ‚ª‚»‚ë‚Á‚½‚ç

	bool blueflag;
	bool blueflag2;
	bool blueflag3;
	bool blueflag4;

	void Init();					//‰Šú‰»
	void Update(Player&player);		//‚ ‚Õ‚Å
};
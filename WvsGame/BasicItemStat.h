#pragma once

/*
�Ӫ��~�y������O�����ݩ� -- ���A�S���o��class
*/
struct BasicIncrementStat
{
	//�W�[ inc
	int	niSTR,
		niDEX,
		niINT,
		niLUK,
		niMaxHP,
		niMaxMP,
		niPAD,
		niMAD,
		niPDD,
		niMDD,
		niACC,
		niEVA,
		niCraft,
		niSpeed,
		niJump,
		niSwim,
		niFatigue;
};

/*
�Ӫ��~�������ݩʡA�Ҧp�i�_����� -- ���A�S���o��class
*/
struct BasicAbilityStat
{
	bool bTimeLimited,
		bCash,
		bQuest,
		bPartyQuest,
		bOnly,
		bTradeBlock,
		bNotSale,
		bExpireOnLogout,
		bBigSize;
};
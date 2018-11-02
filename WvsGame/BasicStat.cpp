#include "BasicStat.h"
#include "..\Database\GA_Character.hpp"
#include "..\Database\GW_ItemSlotBase.h"
#include "..\Database\GW_ItemSlotEquip.h"
#include "..\Database\GW_CharacterStat.h"
#include "..\Database\GW_CharacterLevel.h"

#include "SecondaryStat.h"
#include "ItemInfo.h"
#include "..\WvsLib\Memory\MemoryPoolMan.hpp"

BasicStat::BasicStat()
{
	m_bOption = AllocObj( BasicStatRateOption );
}


BasicStat::~BasicStat()
{
	FreeObj( m_bOption );
}

void BasicStat::SetFrom(GA_Character * pChar, int nMaxHPIncRate, int nMaxMPIncRate, int nBasicStatInc)
{
	const GW_CharacterStat *pCS = pChar->mStat;

	nGender = pChar->nGender;
	nLevel = pChar->mLevel->nLevel;
	nJob = pCS->nJob;
	nSTR = pCS->nStr;
	nINT = pCS->nInt;
	nDEX = pCS->nDex;
	nLUK = pCS->nLuk;
	nPOP = pCS->nPOP;
	nMHP = pCS->nMaxHP;
	nMMP = pCS->nMaxMP;
	nCharismaEXP = pCS->nCharismaEXP;
	nInsightEXP = pCS->nInsightEXP;
	nWillEXP = pCS->nWillEXP;
	nSenseEXP = pCS->nSenseEXP;
	nCharmEXP = pCS->nCharmEXP;

	const GW_ItemSlotEquip* pEquip;
	for (const auto& itemEquipped : pChar->mItemSlot[1])
	{
		pEquip = (const GW_ItemSlotEquip*)itemEquipped.second;
		nSTR += pEquip->nSTR;
		nLUK += pEquip->nLUK;
		nDEX += pEquip->nDEX;
		nINT += pEquip->nINT;
		
		nMHP += pEquip->nMaxHP;
		nMMP += pEquip->nMaxMP;

		//Apply item option here.
	}
	nMHP = nMHP * (nMaxHPIncRate + 100) / 100;
	nMMP = nMMP * (nMaxMPIncRate + 100) / 100;
	if (nMHP > 500000)
		nMHP = 500000;
	if (nMMP > 500000)
		nMMP = 500000;
}

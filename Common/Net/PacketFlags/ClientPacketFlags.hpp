#pragma once
#include "PacketFlags.hpp"

#define MAKE_CLIENT_PACKET_FLAG(flagName, value) namespace FlagInstances{ const static ClientPacketFlag flagName {value, #flagName}; } const static int flagName = value

MAKE_FLAG_COLLECTION_BODY(ClientPacketFlag)
//�H�U�}�l���U�ʥ]Opcode Flag

//=======================Send==========================

MAKE_CLIENT_PACKET_FLAG(Out_OnUserSkillUp, 0x4C);
MAKE_CLIENT_PACKET_FLAG(Out_OnMessage, 0x57);

MAKE_CLIENT_PACKET_FLAG(Out_OnQuestResult, 0x2D4);

//========================Recv=========================

MAKE_CLIENT_PACKET_FLAG(ClientCheckPasswordRequest, 0x69);
MAKE_CLIENT_PACKET_FLAG(ClientSelectWorld, 0x6A);
MAKE_CLIENT_PACKET_FLAG(ClientSecondPasswordCheck, 0x6D);
MAKE_CLIENT_PACKET_FLAG(ClientMigrateIn, 0x6E);
MAKE_CLIENT_PACKET_FLAG(ClientSelectCharacter, 0x6F);
MAKE_CLIENT_PACKET_FLAG(ClientRequestServerList, 0x72);
MAKE_CLIENT_PACKET_FLAG(ClientCheckDuplicatedID, 0x74);
MAKE_CLIENT_PACKET_FLAG(ClientCreateNewCharactar, 0x7D);
MAKE_CLIENT_PACKET_FLAG(ClientLoginBackgroundRequest, 0xA0);
MAKE_CLIENT_PACKET_FLAG(ClientRequestStart, 0xA5);


MAKE_CLIENT_PACKET_FLAG(OnUserTransferFieldRequest, 0xB3);
MAKE_CLIENT_PACKET_FLAG(OnUserMoveRequest, 0xC4);
MAKE_CLIENT_PACKET_FLAG(OnUserAttack_MeleeAttack, 0xC9);
MAKE_CLIENT_PACKET_FLAG(OnUserAttack_ShootAttack, 0xCA);
MAKE_CLIENT_PACKET_FLAG(OnUserAttack_MagicAttack, 0xCB);
MAKE_CLIENT_PACKET_FLAG(OnUserAttack_BodyAttack, 0xCC);
MAKE_CLIENT_PACKET_FLAG(OnUserAttack_AreaDot, 0xCD);


MAKE_CLIENT_PACKET_FLAG(OnSelectNpc, 0xE3);
MAKE_CLIENT_PACKET_FLAG(OnScriptMessageAnswer, 0xE5);

MAKE_CLIENT_PACKET_FLAG(OnUserChat, 0xD1);
MAKE_CLIENT_PACKET_FLAG(OnUserChangeSlotRequest, 0xF7);

MAKE_CLIENT_PACKET_FLAG(OnUserSkillUpRequest, 0x13E);
MAKE_CLIENT_PACKET_FLAG(OnUserSkillUseRequest, 0x13F);
MAKE_CLIENT_PACKET_FLAG(OnUserSkillCancelRequest, 0x140);
MAKE_CLIENT_PACKET_FLAG(OnQuestRequest, 0x154);
MAKE_CLIENT_PACKET_FLAG(OnChangeCharacterRequest, 0x204);


//����Opcode Flag���U
FLAG_COLLECTION_BODY_END
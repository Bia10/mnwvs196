#pragma once
#ifndef GAME_FLAG
#define GAME_FLAG

#include "PacketFlags.hpp"

#define MAKE_GAME_PACKET_FLAG(flagName, value) namespace FlagInstances{ const static GamePacketFlag flagName {value, #flagName}; } const static int flagName = value

MAKE_FLAG_COLLECTION_BODY(GamePacketFlag)
//�H�U�}�l���U�ʥ]Opcode Flag

//Flags to Center
MAKE_GAME_PACKET_FLAG(RequestMigrateIn, 0x6001);
MAKE_GAME_PACKET_FLAG(RequestMigrateOut, 0x6002);


//Flags to Game
MAKE_GAME_PACKET_FLAG(Client_SetFieldStage, 0x1BF); //Stage::OnSetField

//����Opcode Flag���U
FLAG_COLLECTION_BODY_END

#endif
#pragma once
#ifndef FIELD_FLAG
#define FIELD_FLAG

#include "PacketFlags.hpp"

#define MAKE_FIELD_SEND_PACKET_FLAG(flagName, value) namespace FlagInstances{ const static FieldSendPacketFlag flagName {value, #flagName}; } const static int flagName = value

MAKE_FLAG_COLLECTION_BODY(FieldSendPacketFlag)
//�H�U�}�l���U�ʥ]Opcode Flag


													//����Opcode Flag���U
FLAG_COLLECTION_BODY_END

#endif
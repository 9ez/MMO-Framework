/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_TypePacketH
#define PCS_TypePacketH

#include "TypeDef.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsPCS
{
  enum
  {
  // from Client
    ePacket_TryEnterRoom,// ������ ����� ����� � ���
    ePacket_TryEnterGarage,// ������ ����� ����� �� ���
  // from Slave
    // �������� ����� �����������
    ePacket_EnterGarage,
    ePacket_EnterQueue,
    ePacket_EnterRoom,
    // Room events
    ePacket_LoadMap,// Slave ��������� ����� ��� ��������
    ePacket_CorrectGameObjects,// ������������� ���������� ���������� ������� ��������
    ePacket_AddGameObjects,
    ePacket_EnableGameObjects,
    ePacket_DisableGameObjects,
    ePacket_DeleteGameObjects,
  // from Client/Slave
    // ������������� ������� ������� (e.g. �������� �������� ���������, 
    // ����������� ������� ����(������������),
    // ������� GUI(���,��������� �����, ��), �������� �������)
    ePacket_GameImpl,
  };
  
  struct DllExport TBasePacket_PCS
  {
    TBasePacket_PCS(unsigned char _type){type = _type;}
    unsigned char type;
  }_PACKED;
}

#ifdef WIN32
#pragma pack(pop)
#endif

#endif

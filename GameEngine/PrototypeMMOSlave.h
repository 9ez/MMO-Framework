/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PrototypeMMOSlaveH
#define PrototypeMMOSlaveH

#include "PrototypeMMOActiveServer.h"

class DllExport PrototypeMMOSlave : public PrototypeMMOActiveServer
{
public:
  PrototypeMMOSlave();
  virtual ~PrototypeMMOSlave();

  virtual void SaveContext(unsigned int id_session, void* data, int size) = 0;
  virtual bool FindClientKeyBySession(unsigned int id_session, unsigned int &id) = 0;
  virtual bool FindSessionByClientKey(unsigned int id, unsigned int& id_session) = 0;

  struct TDescDownSlave // ��� GetDescDown
  {
    unsigned int id_session;
  };
};

#endif

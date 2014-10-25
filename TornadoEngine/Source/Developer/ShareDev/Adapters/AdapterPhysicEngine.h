/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef AdapterPhysicEngineH
#define AdapterPhysicEngineH

#include "PrototypeDev.h"

class DllExport AdapterPhysicEngine : public PrototypeDev
{
public:
  AdapterPhysicEngine();
  virtual ~AdapterPhysicEngine();

  virtual bool Work();
};

#endif

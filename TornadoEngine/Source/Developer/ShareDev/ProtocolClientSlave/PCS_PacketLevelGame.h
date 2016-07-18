/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PCS_PacketLevelGameH
#define PCS_PacketLevelGameH

#include "PCS_TypePacket.h"
#include <string>
#include <vector>

namespace nsPCS
{
  typedef int            TypeID_GameMap;
  typedef unsigned short TypeID_GameOject;
  typedef unsigned short TypeSizeInternalState;
  typedef unsigned char  TypeSizeNameModel;
  typedef unsigned char  TypeSizeNameFGIObject;
  typedef unsigned short TypeSizeDescFGIObject;
  typedef unsigned char  TypeMovable;
  typedef unsigned char  TypeFGIObject;
  typedef unsigned int   TypeTryEnterRoom;
  typedef enum
  {
    Map,
    Model,
    Shape,
    Terrain,
  }eTypeFGIObject;
  //-----------------------------------------------------------------
  class DllExport TPacket_TryEnterRoom : public TBasePacket_PCS
  {
  public:
    TPacket_TryEnterRoom();
    TypeTryEnterRoom mTypeRoom;// клиент выбирает какой тип боя ему нужен
    // 4 байта - запас под тренировочные бои, 4(например) + id_room - номер тренировочной комнаты
    // для Slave он ничего не значит, 
    // для Master - правила для создания, балансировки, выбора карты, условий боя (Игровая логика).
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_TryEnterGarage : public TBasePacket_PCS
  {
  public:
    TPacket_TryEnterGarage();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterGarage : public TBasePacket_PCS
  {
  public:
    TPacket_EnterGarage();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterQueue : public TBasePacket_PCS
  {
    TPacket_EnterQueue();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnterRoom : public TBasePacket_PCS
  {
    TPacket_EnterRoom();
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_LoadMap : public TBasePacket_PCS
  {
  public:
    TPacket_LoadMap();
    TypeID_GameMap mID_Map;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_CorrectGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_CorrectGameObjects();
    struct TDescCorrection
    {
      TypeID_GameOject mID_Object;
      TContainer       mInternalState;
    };
    typedef std::vector<TDescCorrection> TVectorDescCorrection;
    TVectorDescCorrection mVector;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_AddGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_AddGameObjects();
    struct TDescAdd
    {
      std::string      mNameModel;
      TypeMovable      mMovable;
      TypeID_GameOject mID_Object;
      TContainer       mInternalState;
    };
    typedef std::vector<TDescAdd> TVectorAdd;
    TVectorAdd mVector;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_EnableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_EnableGameObjects();
    std::vector<TypeID_GameOject> mVectorID_Object;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DisableGameObjects : public TBasePacket_PCS
  {
  public:
    TPacket_DisableGameObjects();
    std::vector<TypeID_GameOject> mVectorID_Object;
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_AddFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TContainer    mDesc;
    TPacket_AddFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_ModifyFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TContainer    mDesc;
    TPacket_ModifyFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_DeleteFGIObject : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TPacket_DeleteFGIObject();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_UpdateGameObjectByFGI : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TPacket_UpdateGameObjectByFGI();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_UpdateGameObjectByPattern : public TBasePacket_PCS
  {
  public:
    TypeFGIObject mTypeFGIObject;
    std::string   mNameObject;
    TContainer    mDesc;
    TPacket_UpdateGameObjectByPattern();
  protected:
    virtual TContainer PackInherit();
    virtual void UnpackInherit( char* p, int size );
  };
  //-----------------------------------------------------------------
  class DllExport TPacket_GameImpl : public TBasePacket_PCS
  {
  public:
    TPacket_GameImpl();
    // empty! add some members!
  protected:
    virtual TContainer PackInherit(){return TContainer();}
    virtual void UnpackInherit( char* p, int size ){}
  };
  //-----------------------------------------------------------------
}

#endif

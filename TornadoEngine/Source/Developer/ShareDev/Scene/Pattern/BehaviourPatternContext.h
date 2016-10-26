/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourPatternContextH
#define BehaviourPatternContextH

/*
  ������� ��� ��������� �������� �������.
  ������� ���, ���� ������ ������. ������ ���� ������
  ��� ������ ������� ����� �������� (�����).
  ��������� �������� �������������� ��� ����� ������ � ����������� ������� (Ogre,Bullet,OpenAL).
*/

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "MathTools.h"
#include "MapItem.h"

class TGameObject;
class TFactoryGameItem;
class TFactoryBehaviourPatternModel;

class DllExport TBehaviourPatternContext
{
  std::string mNameModel;
protected:
  TGameObject*                   mGO;
  
  TMapItem::TMapStrStr mParameterMap;
  TMapItem::TMapStrStr mDefaultParameterMap;

  int mPhysicWorldID;
public:
  TBehaviourPatternContext(std::string nameModel);
  virtual ~TBehaviourPatternContext();

  void SetPhysicWorld(int id_physic_world);

  void SetName(std::string v);
  std::string GetName();

  void SetGameObject(TGameObject* p);
  //void SetFactory(TFactoryGameItem* pFGI, TFactoryBehaviourPatternModel* pFBP);

  // ��� �������� �����/�������
  virtual void SetParameterMap(TMapItem::TMapStrStr& m);// L
  // ��� ���������� �����/�������,
  // ��� �� ����� ����� ����� ������ ��������, �������������� ����� ����
  //virtual void GetDefualtParameterMap(TMapItem::TMapStrStr& m);// L
  // �� ������ �������� �������, ��������� 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

  // ��� - ���������, ����������� - ��� ����������� (� �������� ��� �������)
  // ��������� �� ������ ���. ���� ���������������� � �������� � ������
  //virtual bool GetNeedSynchro();// B

  // ������ ������
  virtual void SetPosition(nsMathTools::TVector3& v);// L
  virtual bool GetPosition(nsMathTools::TVector3& v);// B, ���������� ��������
  virtual void SetOrientation(nsMathTools::TVector3& v);// L
  virtual bool GetOrientation(nsMathTools::TVector3& v);// B, ���������� ��������

  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L

  const TMapItem::TMapStrStr* GetParameterMap();
protected:
  struct TParameterMap
  {
    bool flgMobility;
    std::string nameGameItem;
    std::string nameVariant;
    TParameterMap(){flgMobility=false;}
  };
  TParameterMap mStructParameterMap;

  virtual void ParseParameterMap(TMapItem::TMapStrStr& m);

};

#endif

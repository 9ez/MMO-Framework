/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_ModelH
#define PatternModel_ModelH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"
#include "PatternConfigItem.h"
#include "ModelItem.h"

class DllExport TPatternModel_Model : public TBehaviourPatternModel
{
	TModelItem::eType mTypeContent;

	struct TBaseDesc
	{
		TModelItem::eType type;
		std::string  namePart;
		std::string  nameVariant;
	};
	struct TModelDesc : public TBaseDesc
	{
		TPatternModel_Model* pModel;
		TModelDesc(){type=TModelItem::eModel;pModel=NULL;}
		~TModelDesc();
	};
	struct TShapeDesc : public TBaseDesc
	{
		std::string  nameShapeItem;
		std::string  nameMaterial; // реальный материал и переопределенный могут не совпадать
		// результат создания формы:
		Ogre::Entity* pEntity;
		btRigidBody* pRigidBody;
		TShapeDesc(){type=TModelItem::eShape;pRigidBody=NULL;pEntity=NULL;}
	};

protected:
	typedef std::map<std::string,TBaseDesc*> TMapStrPtrDesc;
	typedef TMapStrPtrDesc::iterator         TMapStrPtrDescIt;
	typedef TMapStrPtrDesc::value_type       TMapStrPtrDescVT;

	typedef std::map<std::string,TMapStrPtrDesc> TMapStr_StrPtrDesc;
	typedef TMapStr_StrPtrDesc::iterator        TMapStr_StrPtrDescIt;
	typedef TMapStr_StrPtrDesc::value_type      TMapStr_StrPtrDescVT;

	// набор форм или моделей
	TMapStr_StrPtrDesc mMapNamePart_NameVariantDesc;
public:
  TPatternModel_Model();
  TPatternModel_Model(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);
  virtual ~TPatternModel_Model();

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L

  // Выполнить задания в каждом из потоков
  virtual void LoadByModule_Logic();
  virtual bool LoadByModule_Graphic(bool fast = false);
  virtual bool LoadByModule_Physic(bool fast = false);
  virtual bool LoadByModule_Sound(bool fast = false);

  virtual void UnloadByModule_Logic();
  virtual bool UnloadByModule_Graphic(bool fast = false);
  virtual bool UnloadByModule_Physic(bool fast = false);
  virtual bool UnloadByModule_Sound(bool fast = false);

  virtual void SynchroByModule_Logic();  // внешняя синхронизация
  virtual void SynchroByModule_Graphic();// графика от физики
  virtual void SynchroByModule_Physic(); // внутренняя синхронизация
  virtual void SynchroByModule_Sound();  // звук от физики
protected:
	void Init(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);

  void LoadModelsByModule_Logic(TModelItem::TMapStrPart& mapNamePart);
  void LoadShapesByModule_Logic(TModelItem::TMapStrPart& mapNamePart);

  void LoadShapeByModule_Graphic(TShapeDesc* pShapeDesc);
	void PostLoadByModule_Graphic();

	void LoadShapeByModule_Physic(TShapeDesc* pShapeDesc);
	void PostLoadByModule_Physic();

protected:
	TModelItem::eType GetTypeContent();
	void SetTypeContent(TModelItem::eType type);

	// игровой итэм для загрузки и управления частями
	void SetNameGameItem(std::string& name);
	std::string GetNameGameItem();
	// подвижность
	void SetMobility(bool v);
	bool GetMobility();

	void AddDesc(TBaseDesc* pDesc);
	TBaseDesc* GetDesc(std::string& namePart, std::string& nameVariant);

	int GetCountPart();
	std::string GetNamePart(int index);

	int GetCountVariant(std::string& namePart);
	std::string GetNameVariant(std::string& namePart, int index);

protected:
	TMapStrPtrDesc* FindMapByNamePart(std::string& namePart);
};

#endif

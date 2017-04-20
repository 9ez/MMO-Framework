/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourPatternH
#define BehaviourPatternH

/*
  Базовый тип поведения игрового объекта.

  Идеология: модель-логика без данных.
  Контекст: данные для модели для текущего вызова функции.
  GameObject: данные только Ogre, Bullet, OpenAL.
  Контекст: надстройка данных над Ogre, Bullet, OpenAL.

  Реализация класса предполагает: данные, которые используются для загрузки объекта не меняются
  в процессе загрузки. В частности это FactoryGameItem.
*/

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "MathTools.h"
#include "PatternConfigItem.h"
#include "BL_Debug.h"
#include "ManagerNamePattern.h"

#include "Builder_Ogre.h"
#include "Builder_OpenAL.h"
#include "Builder_Bullet.h"

#include "Destructor_Bullet.h"
#include "Destructor_Ogre.h"
#include "Destructor_OpenAL.h"

#include <boost/lexical_cast.hpp>

/*
  Базовый тип поведения игрового объекта.
*/

class TFactoryGameItem;
class TFactoryBehaviourPattern;
class TGameObject;

class DllExport TBehaviourPattern
{
  std::string mName;
	
	TPatternConfigItem::TMapStrStr* mPtrDefaultParameterMap;
protected:
	TGameObject*                   mGO;

	// список возможных свойств поведения
	TPatternConfigItem::TMapStrStr mParameterMap;// from MapItem
	std::string 									 mNameMapItem;
	int         									 mPhysicWorldID;

	nsMathTools::TVector3 mPosition;
	nsMathTools::TVector4 mOrientQuaternion;
public:
  TBehaviourPattern(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);
  virtual ~TBehaviourPattern();

	// при сохранении карты/объекта,
	// что бы знать какие ключи вообще возможны, проектирование новых карт
	/*nonvirtual!*/const TPatternConfigItem::TMapStrStr* GetDefaultParameterMap();

  virtual void SetName(std::string v);
  virtual std::string GetName();

	virtual void SetPhysicWorld(int id_physic_world);
	virtual int GetPhysicWorld();

	virtual void SetGameObject(TGameObject* p);

	virtual void SetNameMapItem(std::string nameMap);
	virtual std::string GetNameMapItem();

	// для поиска в редакторе объекта для редактирования
	virtual TManagerNamePattern::eBaseType GetBaseType();

	// меняет физику
	virtual void SetPosition(nsMathTools::TVector3& v);
	virtual bool GetPosition(nsMathTools::TVector3& v);// мгновенное значение
	virtual void SetOrientation(nsMathTools::TVector4& v);
	virtual bool GetOrientation(nsMathTools::TVector4& v);// мгновенное значение

	virtual TPatternConfigItem::TMapStrStr* GetParameterMap();
	virtual void SetParameterMap(TPatternConfigItem::TMapStrStr& m);

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// to Client
  virtual TContainer GetParameterToPattern(bool full = false);// from Slave

	// разделение по модулям нужно потому что у разных реализаций разное кол-во модулей
  // сначала отрабатывает функция Логики, потом уже все остальные
  virtual void BuildByModule_Logic();// инициализация внутренней структуры
  virtual bool BuildByModule_Graphic(bool fast = false);
  virtual bool BuildByModule_Physic( bool fast = false);
  virtual bool BuildByModule_Sound(  bool fast = false);

  virtual void DestructByModule_Logic();// подготовка к освобождению ресурсов
  virtual bool DestructByModule_Graphic(bool fast = false);
  virtual bool DestructByModule_Physic( bool fast = false);
  virtual bool DestructByModule_Sound(  bool fast = false);

  virtual void SynchroByModule_Logic();  // внешняя синхронизация от сервера(например,MMO)
  virtual void SynchroByModule_Graphic();// графика от физики
  virtual void SynchroByModule_Physic(); // внутренняя синхронизация (физика влияет сама на себя)
  virtual void SynchroByModule_Sound();  // звук от физики

	// обновить все ресурсы, на основании которых строится объект на карте
	// учитывает изменения, совершённые через интерфейс паттерна
	// то есть паттерн копит все изменения
	virtual void UpdateResources();
	
	// обновить внутренности по ресурсам
	virtual void UpdateByResourcesByModule_Logic();
	virtual void UpdateByResourcesByModule_Graphic();
	virtual void UpdateByResourcesByModule_Physic();
	virtual void UpdateByResourcesByModule_Sound();
protected:
  TBuilder_Ogre*   GetBuilderOgre();
  TBuilder_Bullet* GetBuilderBullet();
  TBuilder_OpenAL* GetBuilderOpenAL();

  TDestructor_Ogre*   GetDestructorOgre();
  TDestructor_Bullet* GetDestructorBullet();
  TDestructor_OpenAL* GetDestructorOpenAL();

protected:
	template<typename T>
	T GetFromParameterMap(std::string name, T* defaultT = NULL );

	template<typename T>
	bool GetFromParameterMap(std::string name, T& result);

	template<typename T>
	bool SetFromParameterMap(std::string name, T& value);
};

//----------------------------------------------------------------------------
template<typename T>
T TBehaviourPattern::GetFromParameterMap(std::string name, T* defaultT )
{
	T result;
	bool flgResult = GetFromParameterMap(name, result);
	if( flgResult )
		return result;
	if( defaultT )
		result = *defaultT;
	return result;
}
//----------------------------------------------------------------------------
template<typename T>
bool TBehaviourPattern::GetFromParameterMap(std::string name, T& result)
{
	TPatternConfigItem::TMapStrStrIt fit = mParameterMap.find(name);
	if( fit==mParameterMap.end() )
	{
		if( mPtrDefaultParameterMap==NULL )
		{
			BL_FIX_BUG();
			return false;
		}
		// хоть это и не страшно, но такого быть все-равно не должно
		fit = mPtrDefaultParameterMap->find(name);
		if( fit==mPtrDefaultParameterMap->end() )
		{
			BL_FIX_BUG();
			return false;
		}
	}
	result = boost::lexical_cast<T>(fit->second);
	return true;
}
//----------------------------------------------------------------------------
template<typename T>
bool TBehaviourPattern::SetFromParameterMap(std::string name, T& value)
{
	TPatternConfigItem::TMapStrStrIt fit = mParameterMap.find(name);
	if( fit==mParameterMap.end() )
	{
		// проверить есть ли в дефолтной карте
		fit = mPtrDefaultParameterMap->find(name);
		if( fit==mPtrDefaultParameterMap->end() )
		{
			BL_FIX_BUG();
			return false;
		}
		mParameterMap.insert(TPatternConfigItem::TMapStrStrVT(name,value));
		return true;
	}
	fit->second = boost::lexical_cast<std::string>(value);
	return true;
}
//----------------------------------------------------------------------------
#endif

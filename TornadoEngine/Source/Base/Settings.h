/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SettingsH
#define SettingsH

#include <string>
#include <boost/lexical_cast.hpp>
#include <typeinfo.h>

#include "TypeDef.h"
#include "BL_Debug.h"

class IXML;

// not thread save

class DllExport TSettings
{
	IXML* mXML;

	// ���� ������
	std::string mNameApplication;
	// ���� ���, �� �� ������� � ������, 
	// ���� ����, �� ��� ������ � ����� � ������
	std::string mNameCurrentGroup;

public:
	TSettings();
	virtual ~TSettings();

	// ���� �� �����, �� �������
	void Init(std::string pathFileXML);

	// ���� �� �����, �� �������
	void BeginApplication(std::string nameApp);
	std::string GetNameApplication();

	// ���� �� �����, �� �������
	void BeginGroup(std::string nameGroup);
	std::string GetNameCurrentGroup();
	
	// ���� �� �����, �� �������
	template <typename T>
	void WriteEntry(std::string key, T value);

	template <typename T>
	T ReadEntry( std::string key, T* defaultValue = NULL);
protected:
	bool CreateDefault(char* sPath);
	
	void WriteEntryPrivate(std::string key, std::string value);
	std::string ReadEntryPrivate(std::string key);

	bool TryLoad(std::string pathFileXML);
};
//-----------------------------------------------------------------------
template <typename T>
void TSettings::WriteEntry(std::string key, T value)
{
	std::string strValue = boost::lexical_cast<std::string>(value);
	WriteEntryPrivate(key, strValue);
}
//-----------------------------------------------------------------------
template <typename T>
T TSettings::ReadEntry( std::string key, T* defaultValue)
{
	T t;
	std::string value = ReadEntryPrivate(key);
	if( value.length() )
		t = boost::lexical_cast<T>(value);
	else
		if( defaultValue )
			t = *defaultValue;
	return t;
}
//-----------------------------------------------------------------------

#endif 

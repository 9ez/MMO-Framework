/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "EventGameEngine.h"
#include "TypeDef.h"

namespace nsGameEngine
{
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct TDescEvent 
  {
    int id; 
    std::string str;
  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif

  TDescEvent g_StrEvents[] = 
  {
    {eStartThreads,          "�������� � ��������� ������� ���������, ������ ������� �������."},
    {eStopThreads,           "��������� �������, ������� %s."                                 },
    {eStopThreadsEnd,        "��������� �������."                                             },
    {eParseFileConveyerError,"������ ������� ����� ���������: %s."                            },
    {eModuleNotMade,         "������ � ������ %s �� ������."                                  },
    {eThreadsNotExist,       "�� ������� ������"                                              },
  };
  
  bool GetStrEventsByID(int id, std::string& str)
  {
    int cnt = sizeof(g_StrEvents)/sizeof(TDescEvent);
    for( int i = 0 ; i < cnt ; i++ )
    {
      if(g_StrEvents[i].id==id)
      {
        str = g_StrEvents[i].str;
        return true;
      }
    } 
    return false;
  }
}

/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ListObjH
#define ListObjH

#include <list>
#include <boost/foreach.hpp>
/*
  ������ ���������� �� �������
  Not Thread safe
*/
template <class TClass> 
class TListObj
{
public:
  typedef std::list<TClass*> T;
  ~TListObj()
  {
    Clear();
  }
  T* Get(){return &mList;}
  T* operator ->(){return Get();}
  void Clear()
  {
    BOOST_FOREACH(TClass* p, mList)
      delete p;
    mList.clear();
  }
protected:
  T mList;
};

#endif



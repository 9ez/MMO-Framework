/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ContainerObjectH
#define ContainerObjectH

#include "Container.h"
#include <memory.h>
#include <stddef.h>

template <typename T>
class TContainerObject : public TContainer
{
  T* pData;
public:
  TContainerObject();
  virtual ~TContainerObject();
  // ���������� ������
  virtual void Done();
  // ������ ��� �������� ����� ������, ������ ������ ���� �������� new char[N]
  virtual void Entrust(char* p, int s);
  // ���������� ������ ������
  virtual void SetData(char* p, int s);
  // �������� ������ � ������
  virtual char* GetData(int &s);
  // ����� �������� ������ ��� ��������� �������
  virtual void* GetPtr()const;
  virtual int GetSize()const;
  // ��� �� �� ����������� ������ � ������� Done()
  virtual void Unlink();

  //static void Free(char* p){delete[]p;}
};
//---------------------------------------------------------------
template <typename T>
TContainerObject<T>::TContainerObject():
TContainer()
{
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
TContainerObject<T>::~TContainerObject()
{
  Done();
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Done()
{
  delete pData;
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::SetData(char* p, int s)
{
  Done();
  pData = new T;
  if(p)
    *pData = *((T*)p);
}
//---------------------------------------------------------------
template <typename T>
char* TContainerObject<T>::GetData(int &s)
{
  s = sizeof(T);
  return (char*)pData;
}
//---------------------------------------------------------------
template <typename T>
void* TContainerObject<T>::GetPtr()const
{
  return pData;
}
//---------------------------------------------------------------
template <typename T>
int TContainerObject<T>::GetSize()const
{
  return sizeof(T);
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Unlink()
{
  pData = NULL;
}
//---------------------------------------------------------------
template <typename T>
void TContainerObject<T>::Entrust(char* p, int s)
{
  Done();
  pData = (T*)p;
}
//---------------------------------------------------------------
#endif


/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BreakPacketFastH
#define BreakPacketFastH

#include "TypeDef.h"
#include "ContainerTypes.h"

// �������� �� ����� �����. ��������, ����� ����� ��������� �� ������ ������ �������� ����� ���������.

class DllExport TBreakPacketFast
{
  int mSizeBuffer;

  TContainer mBackBuffer;
  int mBackOffset;

  TContainer mFrontBuffer;
  int mFrontOffset;

  TContainer mCollect;
public:
  TBreakPacketFast( int sizeBuffer = 0xFFFF );
  TBreakPacketFast(const TBreakPacketFast& bp);
  virtual ~TBreakPacketFast();

  // �������� ����� ������
  // copyData=true - �������� ���� � ����� ������������ �������� ����������
  void PushBack(char* p,int size);
  void PushFront(char* p,int size);
  // ������� ������� � ���� ����� (������������), 
  // ������ ����� �������� ��������� �� ��������� ����� ����� GetPtr
  // ���� ���-�� ������ ����� 1, �� ������ �� �����.
  void Collect();
  void* GetCollectPtr();
  int GetSize();

  // ���������� ������, ������� �������������� ��� ��������� �����
  void UnlinkCollect();
  void UnlinkPart();

  TBreakPacketFast& operator =( const TBreakPacketFast& b );
protected:
  void CopyFrom(const TBreakPacketFast& bp);
};


#endif


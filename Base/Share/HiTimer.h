/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef HiTimerH
#define HiTimerH

#include "TypeDef.h"

//------------------------------------------------------------------------------
// ������ ������ � �������� �������� ����������
//------------------------------------------------------------------------------

// ��������� ����� ���������� (� �������� �������� ����������)
unsigned __int64 DllExport ht_GetUSCount();

// �������� �� ������������
void DllExport ht_usleep( unsigned int us );

// �������� �� ������������
void DllExport ht_msleep( unsigned int ms );

// �������� �� ������������ c �������������� ��������� ���������
// ���������: true - ����� �� ���������� func, false - ����� �� ��������
typedef bool (*THT_CheckFunc)(void);
bool DllExport ht_sleep( unsigned int us, THT_CheckFunc func );

// ����� � ������������� � ������� ������� ��� ��� ���������.
// �������� �� 55 ���� � ����
unsigned int DllExport ht_GetMSCount();
//------------------------------------------------------------------------------

#endif

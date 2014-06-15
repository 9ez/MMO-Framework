/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MeshStructH
#define MeshStructH

#include "MathTools.h"

// �������� ������ �������� Mesh
// ������ ������� (����������, �������, ���������� ����������) � �������
namespace nsMeshStruct
{
  // Vertex format
#ifdef WIN32
#pragma pack(push, 1)
#endif
  struct VERTEX
  {
    nsMathTools::TVector3 position;
    nsMathTools::TVector3 normal;
    nsMathTools::TVector2 texcoord;

    bool operator == ( const VERTEX& v) const
    {
      if((position!=v.position)||
         (normal  !=v.normal  )||
         (texcoord!=v.texcoord))
         return false;
      return true;
    }
    bool operator != ( const VERTEX& v) const
    {
      if((position!=v.position)||
         (normal  !=v.normal  )||
         (texcoord!=v.texcoord))
        return true;
      return false;
    }
    bool operator < ( const VERTEX& v) const
    {
      if(position < v.position) return true;// ������ ������
      else if(position > v.position) return false;
      //-------------------------------------------
      if(normal < v.normal) return true;
      else if(normal > v.normal) return false;
      //-------------------------------------------
      if(texcoord < v.texcoord) // ������ ������
        return true;

      return false;
    }
    bool operator > ( const VERTEX& v) const
    {
      if(position > v.position) return true;// ������ ������
      else if(position < v.position) return false;
      //-------------------------------------------
      if(normal > v.normal) return true;
      else if(normal < v.normal) return false;
      //-------------------------------------------
      if(texcoord > v.texcoord) // ������ ������
        return true;

      return false;
    }

  }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
}


#endif

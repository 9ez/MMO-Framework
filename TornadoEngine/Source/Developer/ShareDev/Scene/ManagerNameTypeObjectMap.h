/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
������� ������ ��������� 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagerNameTypeObjectMapH
#define ManagerNameTypeObjectMapH

#include <vector>
#include <string>

class TManagerNameTypeObjectMap
{
  typedef std::vector<std::string> TVectorStr;
  TVectorStr mVecNameType;
public:
  TManagerNameTypeObjectMap();
  int GetCount();
  std::string Get(int index);

  static std::string Animated();
  static std::string Light();
  static std::string Model();
  static std::string Skybox();
  static std::string Sound();
  static std::string Terrain();
  static std::string Zone();
};

#endif

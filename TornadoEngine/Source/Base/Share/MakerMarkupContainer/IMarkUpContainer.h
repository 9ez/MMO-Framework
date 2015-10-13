#ifndef IMarkUpContainerH
#define IMarkUpContainerH

/*
    ������ ���������.
  ��������: Root( C, Arr( C )) - ����� ������� �� ����������� ����� � ������� ��������
                 "A" "D" "E"
=========================================================================
  // ��������
  IMarkUpContainer::TDesc* pRoot = new IMarkUpContainer::TDesc;

  IMarkUpContainer::TDesc* pDA = new IMarkUpContainer::TDesc;
  pDA->name = "A";
  pDA->size = sizeof(int);
  pRoot->list.push_back(pDA);

  IMarkUpContainer::TDesc* pDD = new IMarkUpContainer::TDesc;
  pDD->name = "D";
  pDD->size = sizeof(int);
    IMarkUpContainer::TDesc* pDE = new IMarkUpContainer::TDesc;
    pDE->name = "E";
    pDE->size = sizeof(int);
  pDD->list.push_back(pDE);
  
  pRoot->list.push_back(pDD);
=========================================================================
  IMarkUpContainer* pMarkUp = new ...;
  pMarkUp->SetMarkUp(pRoot);
=========================================================================
  // ���������, ������ � ���������
  int* pA = (int*)pMarkUp->GetPtrConst("A");
  int �nt = pMarkUp->GetCount();
  for(int i = 0 ; i < �nt ; i++)
  {
    if(pMarkUp->Enter("B", i))
    {
      int* pElem = (int*)pMarkUp->GetPtrConst("E");
      *pElem = i;
      pMarkUp->Leave();
    }
  }
=========================================================================
  // ����� ������������ 
  pMarkUp->Collect();// � ������ ���� ���������
  void* pPacket  = pMarkUp->GetPtr();
  int sizePacket = pMarkUp->GetSize();
=========================================================================
  // ��������� ������ �� �����
  void* pPacketFromNet = ...;
  int sizePacketFromNet = ...;
  pMarkUp->Set(pPacketFromNet, sizePacketFromNet);
=========================================================================
*/

#include <string>
#include <list>

class IMarkUpContainer
{
public:
  typedef enum
  {
    eUndef,
    eArr,   // ������ ���������
    eRoot,  // ������ ������ � 1 ��������� size==0
    eConst, // ������� ���������� �����
  }eType;
  struct TDesc
  {
    std::string name;
    int size; // ����
    std::list<TDesc*> list;
    TDesc();
    ~TDesc();
    TDesc* CloneHierarhy();
  };
  //--------------------------------------------------------------------------------------
  IMarkUpContainer();
  virtual ~IMarkUpContainer();

  // �������� ����������, �������� ���������� �� pDesc
  virtual void SetMarkUp(TDesc* pDesc) = 0;

  // ���������
  virtual void  EnterRoot()                            = 0;
  // ����� � ������
  virtual bool  Enter(const char* name, int indexElem) = 0;
  virtual void  Leave()                                = 0;

  // ����� ��������� ������ �������
  virtual int   GetCountDesc()                   = 0;
  virtual std::string GetNameDesc(int indexDesc) = 0;
  virtual eType GetTypeDesc(int indexDesc)       = 0;
  
  virtual void  SetCount(int indexDesc, int cnt)    = 0;
  virtual int   GetCount(int indexDesc)             = 0;
  virtual void  SetCount(const char* name, int cnt) = 0;
  virtual int   GetCount(const char* name)          = 0;
  virtual void* GetPtrConst(int indexDesc)          = 0;
  virtual void* GetPtrConst(const char* name)       = 0;
  virtual int   GetSizeConst(int indexDesc)         = 0;
  virtual int   GetSizeConst(const char* name)      = 0;

  // ��������� - ���� ������� ������ �������� ������
  virtual void  Collect() = 0;
  virtual void* GetPtr()  = 0;
  virtual int   GetSize() = 0;
  
  // ������� � �������� ������� ���������
  virtual int   Set(void* p, int size) = 0;
protected:
  TDesc* mRoot;
};

#endif


/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <boost/thread/thread.hpp>

#include "QtLib4.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QThread>

#include "QtMediator.h"
#include "HiTimer.h"
#include "BL_Debug.h"
#include "Logger.h"

TQtLib4::TQtLib4()
{
  mQtComm      = NULL;
  mApplication = NULL;
}
//-------------------------------------------------------------------
TQtLib4::~TQtLib4()
{
  Stop();
}
//-------------------------------------------------------------------
void TQtLib4::Init(int argc, char** argv)
{
  mArgc = argc;
  mArgv = argv;

  Start();
}
//-------------------------------------------------------------------
void TQtLib4::CallFromQtThread(TCallBackRegistrator0* pCallBack)
{
  mQtComm->CallFromQtThread(pCallBack);
}
//-------------------------------------------------------------------
void TQtLib4::Work()
{
  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread start.\n");

  QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
  // т.к. mQtComm наследуется от QObject, то сначала нужно создать объект типа QApplication
  // иначе все события от других потоков через postEvent не дойдут до Qt
  mApplication = new QApplication(mArgc, mArgv);
  mQtComm = new TQtMediator();

  mApplication->exec();

  delete mApplication;
  mApplication = NULL;

  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread stop.\n");
}
//--------------------------------------------------------------------
void TQtLib4::Stop()
{
  GetLogger(STR_NAME_QT)->WriteF_time("Qt Thread: request stop.\n");
  mQtComm->StopQtThread();// стоп потока Qt

  TThreadBoost::Stop();

  delete mQtComm;
  mQtComm = NULL;
}
//--------------------------------------------------------------------


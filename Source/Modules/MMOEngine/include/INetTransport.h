/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallBackRegistrator.h"
#include "ShareMisc.h"
#include "BreakPacket.h"

namespace nsMMOEngine
{
    // транспорт
    class DllExport INetTransport
    {
    public:
        //типы callback вызовов
        typedef enum
        {
            eTcp = 0,
            eUdp = 1,
        }eTypeRecv;
        // callback вернет данную структуру
        struct TDescRecv
        {
            TIP_Port ip_port;
            char* data;
            int   dataSize;
            eTypeRecv type;
        };

        INetTransport();
        virtual ~INetTransport();

        virtual bool Open(unsigned short port, unsigned char numNetWork = 0) = 0;
        virtual unsigned short GetLocalPort() = 0;
        virtual unsigned char GetNumNetWork() = 0;

        // в качестве передаваемых данных выступает объект, который
        // содержит цепочку данных
        virtual void Send(unsigned int ip, unsigned short port, TBreakPacket& packet, bool check = true) = 0;

        // чтение - зарегистрируйся
        // вызывается из потока транспорта, поэтому ЗАПРЕЩАЕТСЯ вызывать методы транспорта по данным событиям
        virtual TCallBackRegistrator1<TDescRecv*>* GetCallbackRecv() = 0;
        virtual TCallBackRegistrator1<TIP_Port* >* GetCallbackConnectFrom() = 0;
        virtual TCallBackRegistrator1<TIP_Port* >* GetCallbackDisconnect() = 0;

        // старт и стоп движка
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual bool IsActive() = 0;

        // синхронная функция
        // вызывать до вызова Start()
        virtual bool Connect(unsigned int ip, unsigned short port) = 0; // вызов только для клиента

        virtual void Close(unsigned int ip, unsigned short port) = 0;
    };
}

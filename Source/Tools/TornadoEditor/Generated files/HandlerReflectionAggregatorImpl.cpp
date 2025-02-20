/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "HandlerReflectionAggregatorImpl.h"

#include "HandlerTypeFactoryImpl.h"
#include "HandlerTypeInformationImpl.h"

using namespace nsTornadoEditor;

THandlerReflectionAggregatorImpl::THandlerReflectionAggregatorImpl()
{
    mTypeFactory = new THandlerTypeFactoryImpl();
    mTypeInfo = new THandlerTypeInformationImpl();
}
//-------------------------------------------------------------------------------------
THandlerReflectionAggregatorImpl::~THandlerReflectionAggregatorImpl()
{
    delete mTypeFactory;
    delete mTypeInfo;
}
//-------------------------------------------------------------------------------------
/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.3.0, build 57 [Json, Binary, ImGui, EcsComponentExtension, EcsSystemExtension, Reflection, TypeInformation]
// File has been generated at 2022_06_21 20:52:37.223
	
#include "ComponentJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEngine;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

std::vector<TComponentJsonSerializer::TypeFunc> TComponentJsonSerializer::mTypeFuncVector;

void TComponentJsonSerializer::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit ) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::map<int, TypeFunc> m;
    
    TypeFunc _nsCommonWrapper_TGuidComponentTypeFunc;
    _nsCommonWrapper_TGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str);
    };
    _nsCommonWrapper_TGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TGuidComponent>((nsCommonWrapper::TGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TGuidComponentTypeFunc, _nsCommonWrapper_TGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_THandlerTargetTypeFunc;
    _nsCommonWrapper_THandlerTargetTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::THandlerTarget>((nsCommonWrapper::THandlerTarget*) p, str);
    };
    _nsCommonWrapper_THandlerTargetTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::THandlerTarget>((nsCommonWrapper::THandlerTarget*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_THandlerTargetTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::THandlerTarget>();
    
    m.insert({ rtti__nsCommonWrapper_THandlerTargetTypeFunc, _nsCommonWrapper_THandlerTargetTypeFunc });
    
    TypeFunc _nsCommonWrapper_TNameComponentTypeFunc;
    _nsCommonWrapper_TNameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str);
    };
    _nsCommonWrapper_TNameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TNameComponent>((nsCommonWrapper::TNameComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TNameComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TNameComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TNameComponentTypeFunc, _nsCommonWrapper_TNameComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc;
    _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TNeedDestroyObjectTagComponent>((nsCommonWrapper::TNeedDestroyObjectTagComponent*) p, str);
    };
    _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TNeedDestroyObjectTagComponent>((nsCommonWrapper::TNeedDestroyObjectTagComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TNeedDestroyObjectTagComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc, _nsCommonWrapper_TNeedDestroyObjectTagComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TObjectInMemoryComponentTypeFunc;
    _nsCommonWrapper_TObjectInMemoryComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TObjectInMemoryComponent>((nsCommonWrapper::TObjectInMemoryComponent*) p, str);
    };
    _nsCommonWrapper_TObjectInMemoryComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TObjectInMemoryComponent>((nsCommonWrapper::TObjectInMemoryComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TObjectInMemoryComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TObjectInMemoryComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TObjectInMemoryComponentTypeFunc, _nsCommonWrapper_TObjectInMemoryComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TParentGuidComponentTypeFunc;
    _nsCommonWrapper_TParentGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str);
    };
    _nsCommonWrapper_TParentGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TParentGuidComponent>((nsCommonWrapper::TParentGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TParentGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TParentGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TParentGuidComponentTypeFunc, _nsCommonWrapper_TParentGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabGuidComponent>((nsCommonWrapper::TPrefabGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabGuidComponent>((nsCommonWrapper::TPrefabGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabGuidComponentTypeFunc, _nsCommonWrapper_TPrefabGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabInstanceGuidComponent>((nsCommonWrapper::TPrefabInstanceGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabInstanceGuidComponent>((nsCommonWrapper::TPrefabInstanceGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabInstanceGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc, _nsCommonWrapper_TPrefabInstanceGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc;
    _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabOriginalGuidComponent>((nsCommonWrapper::TPrefabOriginalGuidComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabOriginalGuidComponent>((nsCommonWrapper::TPrefabOriginalGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabOriginalGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc, _nsCommonWrapper_TPrefabOriginalGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TPrefabRootComponentTypeFunc;
    _nsCommonWrapper_TPrefabRootComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TPrefabRootComponent>((nsCommonWrapper::TPrefabRootComponent*) p, str);
    };
    _nsCommonWrapper_TPrefabRootComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TPrefabRootComponent>((nsCommonWrapper::TPrefabRootComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TPrefabRootComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TPrefabRootComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TPrefabRootComponentTypeFunc, _nsCommonWrapper_TPrefabRootComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneGuidComponent>((nsCommonWrapper::TSceneGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneGuidComponentTypeFunc, _nsCommonWrapper_TSceneGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneInstanceGuidComponent>((nsCommonWrapper::TSceneInstanceGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneInstanceGuidComponent>((nsCommonWrapper::TSceneInstanceGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneInstanceGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc, _nsCommonWrapper_TSceneInstanceGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc;
    _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneOriginalGuidComponent>((nsCommonWrapper::TSceneOriginalGuidComponent*) p, str);
    };
    _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneOriginalGuidComponent>((nsCommonWrapper::TSceneOriginalGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneOriginalGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc, _nsCommonWrapper_TSceneOriginalGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TSceneRootComponentTypeFunc;
    _nsCommonWrapper_TSceneRootComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str);
    };
    _nsCommonWrapper_TSceneRootComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TSceneRootComponent>((nsCommonWrapper::TSceneRootComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TSceneRootComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TSceneRootComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TSceneRootComponentTypeFunc, _nsCommonWrapper_TSceneRootComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TTransformComponentTypeFunc;
    _nsCommonWrapper_TTransformComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TTransformComponent>((nsCommonWrapper::TTransformComponent*) p, str);
    };
    _nsCommonWrapper_TTransformComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TTransformComponent>((nsCommonWrapper::TTransformComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TTransformComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TTransformComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TTransformComponentTypeFunc, _nsCommonWrapper_TTransformComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TUniverseGuidComponentTypeFunc;
    _nsCommonWrapper_TUniverseGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TUniverseGuidComponent>((nsCommonWrapper::TUniverseGuidComponent*) p, str);
    };
    _nsCommonWrapper_TUniverseGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TUniverseGuidComponent>((nsCommonWrapper::TUniverseGuidComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TUniverseGuidComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseGuidComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TUniverseGuidComponentTypeFunc, _nsCommonWrapper_TUniverseGuidComponentTypeFunc });
    
    TypeFunc _nsCommonWrapper_TUniverseIndexComponentTypeFunc;
    _nsCommonWrapper_TUniverseIndexComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsCommonWrapper::TUniverseIndexComponent>((nsCommonWrapper::TUniverseIndexComponent*) p, str);
    };
    _nsCommonWrapper_TUniverseIndexComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsCommonWrapper::TUniverseIndexComponent>((nsCommonWrapper::TUniverseIndexComponent*) p, str, err);
    };
    
    auto rtti__nsCommonWrapper_TUniverseIndexComponentTypeFunc = globalTypeIdentifier->Type<nsCommonWrapper::TUniverseIndexComponent>();
    
    m.insert({ rtti__nsCommonWrapper_TUniverseIndexComponentTypeFunc, _nsCommonWrapper_TUniverseIndexComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraComponentTypeFunc;
    _nsGraphicWrapper_TCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraComponent>((nsGraphicWrapper::TCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraComponentTypeFunc, _nsGraphicWrapper_TCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc;
    _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraTextureTagComponent>((nsGraphicWrapper::TCameraTextureTagComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraTextureTagComponent>((nsGraphicWrapper::TCameraTextureTagComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraTextureTagComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraTextureTagComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraTextureTagComponentTypeFunc, _nsGraphicWrapper_TCameraTextureTagComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc;
    _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraWindowPositionComponent>((nsGraphicWrapper::TCameraWindowPositionComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraWindowPositionComponent>((nsGraphicWrapper::TCameraWindowPositionComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowPositionComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc, _nsGraphicWrapper_TCameraWindowPositionComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc;
    _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TCameraWindowSizeComponent>((nsGraphicWrapper::TCameraWindowSizeComponent*) p, str);
    };
    _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TCameraWindowSizeComponent>((nsGraphicWrapper::TCameraWindowSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TCameraWindowSizeComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc, _nsGraphicWrapper_TCameraWindowSizeComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc;
    _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TGuiCameraTagComponent>((nsGraphicWrapper::TGuiCameraTagComponent*) p, str);
    };
    _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TGuiCameraTagComponent>((nsGraphicWrapper::TGuiCameraTagComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TGuiCameraTagComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TGuiCameraTagComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TGuiCameraTagComponentTypeFunc, _nsGraphicWrapper_TGuiCameraTagComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TLightComponentTypeFunc;
    _nsGraphicWrapper_TLightComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str);
    };
    _nsGraphicWrapper_TLightComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TLightComponent>((nsGraphicWrapper::TLightComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TLightComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TLightComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TLightComponentTypeFunc, _nsGraphicWrapper_TLightComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc;
    _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TRenderToTextureCameraComponent>((nsGraphicWrapper::TRenderToTextureCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TRenderToTextureCameraComponent>((nsGraphicWrapper::TRenderToTextureCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TRenderToTextureCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc, _nsGraphicWrapper_TRenderToTextureCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc;
    _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TTextureFromCameraComponent>((nsGraphicWrapper::TTextureFromCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TTextureFromCameraComponent>((nsGraphicWrapper::TTextureFromCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TTextureFromCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TTextureFromCameraComponentTypeFunc, _nsGraphicWrapper_TTextureFromCameraComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TTextureFromFileComponentTypeFunc;
    _nsGraphicWrapper_TTextureFromFileComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TTextureFromFileComponent>((nsGraphicWrapper::TTextureFromFileComponent*) p, str);
    };
    _nsGraphicWrapper_TTextureFromFileComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TTextureFromFileComponent>((nsGraphicWrapper::TTextureFromFileComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TTextureFromFileComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TTextureFromFileComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TTextureFromFileComponentTypeFunc, _nsGraphicWrapper_TTextureFromFileComponentTypeFunc });
    
    TypeFunc _nsGraphicWrapper_TUniverseCameraComponentTypeFunc;
    _nsGraphicWrapper_TUniverseCameraComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGraphicWrapper::TUniverseCameraComponent>((nsGraphicWrapper::TUniverseCameraComponent*) p, str);
    };
    _nsGraphicWrapper_TUniverseCameraComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGraphicWrapper::TUniverseCameraComponent>((nsGraphicWrapper::TUniverseCameraComponent*) p, str, err);
    };
    
    auto rtti__nsGraphicWrapper_TUniverseCameraComponentTypeFunc = globalTypeIdentifier->Type<nsGraphicWrapper::TUniverseCameraComponent>();
    
    m.insert({ rtti__nsGraphicWrapper_TUniverseCameraComponentTypeFunc, _nsGraphicWrapper_TUniverseCameraComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonClickHandlerComponent>((nsGuiWrapper::TButtonClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TButtonClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonClickHandlerComponentTypeFunc, _nsGuiWrapper_TButtonClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TButtonComponentTypeFunc;
    _nsGuiWrapper_TButtonComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str);
    };
    _nsGuiWrapper_TButtonComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TButtonComponent>((nsGuiWrapper::TButtonComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TButtonComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TButtonComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TButtonComponentTypeFunc, _nsGuiWrapper_TButtonComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc;
    _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TDialogCloseEventHandlerComponent>((nsGuiWrapper::TDialogCloseEventHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TDialogCloseEventHandlerComponent>((nsGuiWrapper::TDialogCloseEventHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TDialogCloseEventHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc, _nsGuiWrapper_TDialogCloseEventHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TDialogComponentTypeFunc;
    _nsGuiWrapper_TDialogComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TDialogComponent>((nsGuiWrapper::TDialogComponent*) p, str);
    };
    _nsGuiWrapper_TDialogComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TDialogComponent>((nsGuiWrapper::TDialogComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TDialogComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TDialogComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TDialogComponentTypeFunc, _nsGuiWrapper_TDialogComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFocusComponentTypeFunc;
    _nsGuiWrapper_TFocusComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str);
    };
    _nsGuiWrapper_TFocusComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFocusComponent>((nsGuiWrapper::TFocusComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFocusComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFocusComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFocusComponentTypeFunc, _nsGuiWrapper_TFocusComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameComponentTypeFunc;
    _nsGuiWrapper_TFrameComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameComponent>((nsGuiWrapper::TFrameComponent*) p, str);
    };
    _nsGuiWrapper_TFrameComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameComponent>((nsGuiWrapper::TFrameComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameComponentTypeFunc, _nsGuiWrapper_TFrameComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameKeyHandlerComponent>((nsGuiWrapper::TFrameKeyHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameKeyHandlerComponent>((nsGuiWrapper::TFrameKeyHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameKeyHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc, _nsGuiWrapper_TFrameKeyHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseClickHandlerComponent>((nsGuiWrapper::TFrameMouseClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseClickHandlerComponent>((nsGuiWrapper::TFrameMouseClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseMoveHandlerComponent>((nsGuiWrapper::TFrameMouseMoveHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseMoveHandlerComponent>((nsGuiWrapper::TFrameMouseMoveHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseMoveHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseMoveHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc;
    _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TFrameMouseWheelHandlerComponent>((nsGuiWrapper::TFrameMouseWheelHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TFrameMouseWheelHandlerComponent>((nsGuiWrapper::TFrameMouseWheelHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TFrameMouseWheelHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc, _nsGuiWrapper_TFrameMouseWheelHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TInputTextComponentTypeFunc;
    _nsGuiWrapper_TInputTextComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TInputTextComponent>((nsGuiWrapper::TInputTextComponent*) p, str);
    };
    _nsGuiWrapper_TInputTextComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TInputTextComponent>((nsGuiWrapper::TInputTextComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TInputTextComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TInputTextComponentTypeFunc, _nsGuiWrapper_TInputTextComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TInputTextValueComponentTypeFunc;
    _nsGuiWrapper_TInputTextValueComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TInputTextValueComponent>((nsGuiWrapper::TInputTextValueComponent*) p, str);
    };
    _nsGuiWrapper_TInputTextValueComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TInputTextValueComponent>((nsGuiWrapper::TInputTextValueComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TInputTextValueComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TInputTextValueComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TInputTextValueComponentTypeFunc, _nsGuiWrapper_TInputTextValueComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TLabelComponentTypeFunc;
    _nsGuiWrapper_TLabelComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TLabelComponent>((nsGuiWrapper::TLabelComponent*) p, str);
    };
    _nsGuiWrapper_TLabelComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TLabelComponent>((nsGuiWrapper::TLabelComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TLabelComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TLabelComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TLabelComponentTypeFunc, _nsGuiWrapper_TLabelComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TLabelValueComponentTypeFunc;
    _nsGuiWrapper_TLabelValueComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TLabelValueComponent>((nsGuiWrapper::TLabelValueComponent*) p, str);
    };
    _nsGuiWrapper_TLabelValueComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TLabelValueComponent>((nsGuiWrapper::TLabelValueComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TLabelValueComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TLabelValueComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TLabelValueComponentTypeFunc, _nsGuiWrapper_TLabelValueComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMainWindowComponentTypeFunc;
    _nsGuiWrapper_TMainWindowComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMainWindowComponent>((nsGuiWrapper::TMainWindowComponent*) p, str);
    };
    _nsGuiWrapper_TMainWindowComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMainWindowComponent>((nsGuiWrapper::TMainWindowComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMainWindowComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMainWindowComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMainWindowComponentTypeFunc, _nsGuiWrapper_TMainWindowComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc;
    _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMenuNodeClickHandlerComponent>((nsGuiWrapper::TMenuNodeClickHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMenuNodeClickHandlerComponent>((nsGuiWrapper::TMenuNodeClickHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeClickHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc, _nsGuiWrapper_TMenuNodeClickHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TMenuNodeComponentTypeFunc;
    _nsGuiWrapper_TMenuNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TMenuNodeComponent>((nsGuiWrapper::TMenuNodeComponent*) p, str);
    };
    _nsGuiWrapper_TMenuNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TMenuNodeComponent>((nsGuiWrapper::TMenuNodeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TMenuNodeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TMenuNodeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TMenuNodeComponentTypeFunc, _nsGuiWrapper_TMenuNodeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TNodeIconComponentTypeFunc;
    _nsGuiWrapper_TNodeIconComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TNodeIconComponent>((nsGuiWrapper::TNodeIconComponent*) p, str);
    };
    _nsGuiWrapper_TNodeIconComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TNodeIconComponent>((nsGuiWrapper::TNodeIconComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TNodeIconComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TNodeIconComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TNodeIconComponentTypeFunc, _nsGuiWrapper_TNodeIconComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TPositionComponentTypeFunc;
    _nsGuiWrapper_TPositionComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str);
    };
    _nsGuiWrapper_TPositionComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TPositionComponent>((nsGuiWrapper::TPositionComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TPositionComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TPositionComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TPositionComponentTypeFunc, _nsGuiWrapper_TPositionComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc;
    _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSelectedTreeNodeGuidComponent>((nsGuiWrapper::TSelectedTreeNodeGuidComponent*) p, str);
    };
    _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSelectedTreeNodeGuidComponent>((nsGuiWrapper::TSelectedTreeNodeGuidComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSelectedTreeNodeGuidComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc, _nsGuiWrapper_TSelectedTreeNodeGuidComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TSizeComponentTypeFunc;
    _nsGuiWrapper_TSizeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str);
    };
    _nsGuiWrapper_TSizeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TSizeComponent>((nsGuiWrapper::TSizeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TSizeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TSizeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TSizeComponentTypeFunc, _nsGuiWrapper_TSizeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTitleComponentTypeFunc;
    _nsGuiWrapper_TTitleComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str);
    };
    _nsGuiWrapper_TTitleComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTitleComponent>((nsGuiWrapper::TTitleComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTitleComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTitleComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTitleComponentTypeFunc, _nsGuiWrapper_TTitleComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTreeNodeComponentTypeFunc;
    _nsGuiWrapper_TTreeNodeComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTreeNodeComponent>((nsGuiWrapper::TTreeNodeComponent*) p, str);
    };
    _nsGuiWrapper_TTreeNodeComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTreeNodeComponent>((nsGuiWrapper::TTreeNodeComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTreeNodeComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTreeNodeComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTreeNodeComponentTypeFunc, _nsGuiWrapper_TTreeNodeComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TTreeViewComponentTypeFunc;
    _nsGuiWrapper_TTreeViewComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TTreeViewComponent>((nsGuiWrapper::TTreeViewComponent*) p, str);
    };
    _nsGuiWrapper_TTreeViewComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TTreeViewComponent>((nsGuiWrapper::TTreeViewComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TTreeViewComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TTreeViewComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TTreeViewComponentTypeFunc, _nsGuiWrapper_TTreeViewComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TVisibilityComponentTypeFunc;
    _nsGuiWrapper_TVisibilityComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str);
    };
    _nsGuiWrapper_TVisibilityComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TVisibilityComponent>((nsGuiWrapper::TVisibilityComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TVisibilityComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TVisibilityComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TVisibilityComponentTypeFunc, _nsGuiWrapper_TVisibilityComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc;
    _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TWindowCloseEventHandlerComponent>((nsGuiWrapper::TWindowCloseEventHandlerComponent*) p, str);
    };
    _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TWindowCloseEventHandlerComponent>((nsGuiWrapper::TWindowCloseEventHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TWindowCloseEventHandlerComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc, _nsGuiWrapper_TWindowCloseEventHandlerComponentTypeFunc });
    
    TypeFunc _nsGuiWrapper_TWindowComponentTypeFunc;
    _nsGuiWrapper_TWindowComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str);
    };
    _nsGuiWrapper_TWindowComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsGuiWrapper::TWindowComponent>((nsGuiWrapper::TWindowComponent*) p, str, err);
    };
    
    auto rtti__nsGuiWrapper_TWindowComponentTypeFunc = globalTypeIdentifier->Type<nsGuiWrapper::TWindowComponent>();
    
    m.insert({ rtti__nsGuiWrapper_TWindowComponentTypeFunc, _nsGuiWrapper_TWindowComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc;
    _nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TObjectInstanceEndHandlerComponent>((nsLogicWrapper::TObjectInstanceEndHandlerComponent*) p, str);
    };
    _nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TObjectInstanceEndHandlerComponent>((nsLogicWrapper::TObjectInstanceEndHandlerComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TObjectInstanceEndHandlerComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc, _nsLogicWrapper_TObjectInstanceEndHandlerComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc;
    _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TPrefabObjectReferenceComponent>((nsLogicWrapper::TPrefabObjectReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TPrefabObjectReferenceComponent>((nsLogicWrapper::TPrefabObjectReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabObjectReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc, _nsLogicWrapper_TPrefabObjectReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TPrefabReferenceComponentTypeFunc;
    _nsLogicWrapper_TPrefabReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TPrefabReferenceComponent>((nsLogicWrapper::TPrefabReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TPrefabReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TPrefabReferenceComponent>((nsLogicWrapper::TPrefabReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TPrefabReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TPrefabReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TPrefabReferenceComponentTypeFunc, _nsLogicWrapper_TPrefabReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc;
    _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSceneObjectReferenceComponent>((nsLogicWrapper::TSceneObjectReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSceneObjectReferenceComponent>((nsLogicWrapper::TSceneObjectReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSceneObjectReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc, _nsLogicWrapper_TSceneObjectReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSceneReferenceComponentTypeFunc;
    _nsLogicWrapper_TSceneReferenceComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSceneReferenceComponent>((nsLogicWrapper::TSceneReferenceComponent*) p, str);
    };
    _nsLogicWrapper_TSceneReferenceComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSceneReferenceComponent>((nsLogicWrapper::TSceneReferenceComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSceneReferenceComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSceneReferenceComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSceneReferenceComponentTypeFunc, _nsLogicWrapper_TSceneReferenceComponentTypeFunc });
    
    TypeFunc _nsLogicWrapper_TSystemComponentTypeFunc;
    _nsLogicWrapper_TSystemComponentTypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsLogicWrapper::TSystemComponent>((nsLogicWrapper::TSystemComponent*) p, str);
    };
    _nsLogicWrapper_TSystemComponentTypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsLogicWrapper::TSystemComponent>((nsLogicWrapper::TSystemComponent*) p, str, err);
    };
    
    auto rtti__nsLogicWrapper_TSystemComponentTypeFunc = globalTypeIdentifier->Type<nsLogicWrapper::TSystemComponent>();
    
    m.insert({ rtti__nsLogicWrapper_TSystemComponentTypeFunc, _nsLogicWrapper_TSystemComponentTypeFunc });
    
    TypeFunc _nsMathTools_TMatrix16TypeFunc;
    _nsMathTools_TMatrix16TypeFunc.serializeFunc = [] (void* p, std::string& str) {
    Serialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str);
    };
    _nsMathTools_TMatrix16TypeFunc.deserializeFunc = [] (void* p, const std::string& str, std::string& err) {
        return Deserialize<nsMathTools::TMatrix16>((nsMathTools::TMatrix16*) p, str, err);
    };
    
    auto rtti__nsMathTools_TMatrix16TypeFunc = globalTypeIdentifier->Type<nsMathTools::TMatrix16>();
    
    m.insert({ rtti__nsMathTools_TMatrix16TypeFunc, _nsMathTools_TMatrix16TypeFunc });
    
    int max = 0;
    for (auto& vt : m) {
        max = std::max(vt.first, max);
    }
    
    mTypeFuncVector.resize(max + 1);
    for (auto& vt : m) {
        mTypeFuncVector[vt.first] = vt.second;
    }
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::Serialize(void* p, std::string& str, int rtti)
{
    Init();
    mTypeFuncVector[rtti].serializeFunc(p, str);
}
//---------------------------------------------------------------------------------------
bool TComponentJsonSerializer::Deserialize(void* p, const std::string& str, int rtti, std::string& err)
{
    Init();
    return mTypeFuncVector[rtti].deserializeFunc(p, str, err);
}
//---------------------------------------------------------------------------------------
bool TComponentJsonSerializer::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mTypeFuncVector.size()) {
        return false;
    }
    return mTypeFuncVector[rtti].serializeFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::THandlerTarget* p, Jobj& obj)
{
    PUM::Push(obj, "handlerTypeName", p->handlerTypeName);
    PUM::Push(obj, "partOfGuid", p->partOfGuid);
    PUM::Push(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::THandlerTarget* p, const Jobj& obj)
{
    POM::PopStr(obj, "handlerTypeName", p->handlerTypeName);
    POM::PopStr(obj, "partOfGuid", p->partOfGuid);
    POM::PopStr(obj, "entityGuid", p->entityGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TNameComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TNameComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TNeedDestroyObjectTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TObjectInMemoryComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TObjectInMemoryComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TParentGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TParentGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TPrefabGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TPrefabGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TPrefabInstanceGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TPrefabOriginalGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TPrefabRootComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TPrefabRootComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneInstanceGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneOriginalGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TSceneRootComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TSceneRootComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TTransformComponent* p, Jobj& obj)
{
    auto value_o = PUM::AddObject(obj, "value");
    _Serialize(&(p->value), value_o);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TTransformComponent* p, const Jobj& obj)
{
    auto value_o0 = POM::FindObject(obj, "value");
    _Deserialize(&(p->value), value_o0);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TUniverseGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TUniverseGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsCommonWrapper::TUniverseIndexComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsCommonWrapper::TUniverseIndexComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TCameraTextureTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TCameraTextureTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TCameraWindowPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TCameraWindowSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TGuiCameraTagComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TGuiCameraTagComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TLightComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TLightComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TRenderToTextureCameraComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TTextureFromCameraComponent* p, Jobj& obj)
{
    PUM::Push(obj, "cameraGuid", p->cameraGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TTextureFromCameraComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "cameraGuid", p->cameraGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TTextureFromFileComponent* p, Jobj& obj)
{
    PUM::Push(obj, "resourceGuid", p->resourceGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TTextureFromFileComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "resourceGuid", p->resourceGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGraphicWrapper::TUniverseCameraComponent* p, Jobj& obj)
{
    PUM::Push(obj, "universeGuid", p->universeGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGraphicWrapper::TUniverseCameraComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "universeGuid", p->universeGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TButtonClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TButtonClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TButtonComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TButtonComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TDialogCloseEventHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TDialogComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TDialogComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFocusComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFocusComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFrameComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFrameComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFrameKeyHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFrameMouseClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFrameMouseMoveHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TFrameMouseWheelHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TInputTextComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TInputTextComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TInputTextValueComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TInputTextValueComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TLabelComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TLabelComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TLabelValueComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TLabelValueComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TMainWindowComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TMainWindowComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TMenuNodeClickHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TMenuNodeComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TMenuNodeComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TNodeIconComponent* p, Jobj& obj)
{
    PUM::Push(obj, "width", p->width);
    PUM::Push(obj, "height", p->height);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TNodeIconComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "width", p->width);
    POM::PopNum(obj, "height", p->height);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TPositionComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TPositionComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TSelectedTreeNodeGuidComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TSizeComponent* p, Jobj& obj)
{
    PUM::Push(obj, "x", p->x);
    PUM::Push(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TSizeComponent* p, const Jobj& obj)
{
    POM::PopNum(obj, "x", p->x);
    POM::PopNum(obj, "y", p->y);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TTitleComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TTitleComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TTreeNodeComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TTreeNodeComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TTreeViewComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TTreeViewComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TVisibilityComponent* p, Jobj& obj)
{
    PUM::Push(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TVisibilityComponent* p, const Jobj& obj)
{
    POM::PopBool(obj, "value", p->value);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, Jobj& obj)
{
    _Serialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TWindowCloseEventHandlerComponent* p, const Jobj& obj)
{
    _Deserialize((nsCommonWrapper::THandlerTarget*)p, obj);// Inheritances
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsGuiWrapper::TWindowComponent* p, Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsGuiWrapper::TWindowComponent* p, const Jobj& obj)
{
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TObjectInstanceEndHandlerComponent* p, Jobj& obj)
{
    PUM::Push(obj, "handlerTypeName", p->handlerTypeName);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TObjectInstanceEndHandlerComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "handlerTypeName", p->handlerTypeName);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
    PUM::Push(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TPrefabObjectReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
    POM::PopStr(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TPrefabReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TPrefabReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "prefabGuid", p->prefabGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TSceneObjectReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "objectGuid", p->objectGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TSceneReferenceComponent* p, Jobj& obj)
{
    PUM::Push(obj, "sceneGuid", p->sceneGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TSceneReferenceComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "sceneGuid", p->sceneGuid);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsLogicWrapper::TSystemComponent* p, Jobj& obj)
{
    PUM::Push(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsLogicWrapper::TSystemComponent* p, const Jobj& obj)
{
    POM::PopStr(obj, "typeName", p->typeName);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Serialize(nsMathTools::TMatrix16* p, Jobj& obj)
{
    PUM::Push(obj, "_11", p->_11);
    PUM::Push(obj, "_12", p->_12);
    PUM::Push(obj, "_13", p->_13);
    PUM::Push(obj, "_14", p->_14);
    PUM::Push(obj, "_21", p->_21);
    PUM::Push(obj, "_22", p->_22);
    PUM::Push(obj, "_23", p->_23);
    PUM::Push(obj, "_24", p->_24);
    PUM::Push(obj, "_31", p->_31);
    PUM::Push(obj, "_32", p->_32);
    PUM::Push(obj, "_33", p->_33);
    PUM::Push(obj, "_34", p->_34);
    PUM::Push(obj, "_41", p->_41);
    PUM::Push(obj, "_42", p->_42);
    PUM::Push(obj, "_43", p->_43);
    PUM::Push(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------
void TComponentJsonSerializer::_Deserialize(nsMathTools::TMatrix16* p, const Jobj& obj)
{
    POM::PopNum(obj, "_11", p->_11);
    POM::PopNum(obj, "_12", p->_12);
    POM::PopNum(obj, "_13", p->_13);
    POM::PopNum(obj, "_14", p->_14);
    POM::PopNum(obj, "_21", p->_21);
    POM::PopNum(obj, "_22", p->_22);
    POM::PopNum(obj, "_23", p->_23);
    POM::PopNum(obj, "_24", p->_24);
    POM::PopNum(obj, "_31", p->_31);
    POM::PopNum(obj, "_32", p->_32);
    POM::PopNum(obj, "_33", p->_33);
    POM::PopNum(obj, "_34", p->_34);
    POM::PopNum(obj, "_41", p->_41);
    POM::PopNum(obj, "_42", p->_42);
    POM::PopNum(obj, "_43", p->_43);
    POM::PopNum(obj, "_44", p->_44);
}
//---------------------------------------------------------------------------------------

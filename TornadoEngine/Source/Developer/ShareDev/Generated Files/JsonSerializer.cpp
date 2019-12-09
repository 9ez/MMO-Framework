/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/
// File has been generated by ReflectionCodeGenerator version 1.7 build 36, at 2019_02_11 14:28:02.809
	
#include "JsonSerializer.h"
#include "fmt/core.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"

using namespace nsSharedDev;

using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

void TJsonSerializer::_Serialize( TBaseResources* p, Jobj& obj )
{
  PUM::Push( obj, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TBaseResources* p, const json11::Json& json )
{
  POM::PopStr( json, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TFrameworkResources* p, Jobj& obj )
{
  Jobj gameEngine_obj;
  _Serialize( &(p->gameEngine), gameEngine_obj );
  PUM::Push( obj, "gameEngine", gameEngine_obj );
  Jobj graphicEngine_obj;
  _Serialize( &(p->graphicEngine), graphicEngine_obj );
  PUM::Push( obj, "graphicEngine", graphicEngine_obj );
  Jobj gui_obj;
  _Serialize( &(p->gui), gui_obj );
  PUM::Push( obj, "gui", gui_obj );
  Jobj game_obj;
  _Serialize( &(p->game), game_obj );
  PUM::Push( obj, "game", game_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TFrameworkResources* p, const json11::Json& json )
{
  auto& gameEngine_json = json["gameEngine"];
  _Deserialize( &(p->gameEngine), gameEngine_json );
  auto& graphicEngine_json = json["graphicEngine"];
  _Deserialize( &(p->graphicEngine), graphicEngine_json );
  auto& gui_json = json["gui"];
  _Deserialize( &(p->gui), gui_json );
  auto& game_json = json["game"];
  _Deserialize( &(p->game), game_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TGUIResources* p, Jobj& obj )
{
  _Serialize( (TBaseResources*)p, obj);
  Jobj resources_obj;
  _Serialize( &(p->resources), resources_obj );
  PUM::Push( obj, "resources", resources_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TGUIResources* p, const json11::Json& json )
{
  _Deserialize( (TBaseResources*)p, json);
  auto& resources_json = json["resources"];
  _Deserialize( &(p->resources), resources_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TGameEngineResources* p, Jobj& obj )
{
  _Serialize( (TBaseResources*)p, obj);
  PUM::Push( obj, "conveyerPath", p->conveyerPath );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TGameEngineResources* p, const json11::Json& json )
{
  _Deserialize( (TBaseResources*)p, json);
  POM::PopStr( json, "conveyerPath", p->conveyerPath );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TGameResources* p, Jobj& obj )
{
  _Serialize( (TBaseResources*)p, obj);
  Jobj resources_obj;
  _Serialize( &(p->resources), resources_obj );
  PUM::Push( obj, "resources", resources_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TGameResources* p, const json11::Json& json )
{
  _Deserialize( (TBaseResources*)p, json);
  auto& resources_json = json["resources"];
  _Deserialize( &(p->resources), resources_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TGraphicEngineResources* p, Jobj& obj )
{
  _Serialize( (TBaseResources*)p, obj);
  PUM::Push( obj, "terrainPath", p->terrainPath );
  Jobj pluginsCfg_obj;
  _Serialize( &(p->pluginsCfg), pluginsCfg_obj );
  PUM::Push( obj, "pluginsCfg", pluginsCfg_obj );
  Jobj ogreCfg_obj;
  _Serialize( &(p->ogreCfg), ogreCfg_obj );
  PUM::Push( obj, "ogreCfg", ogreCfg_obj );
  Jobj resources_obj;
  _Serialize( &(p->resources), resources_obj );
  PUM::Push( obj, "resources", resources_obj );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TGraphicEngineResources* p, const json11::Json& json )
{
  _Deserialize( (TBaseResources*)p, json);
  POM::PopStr( json, "terrainPath", p->terrainPath );
  auto& pluginsCfg_json = json["pluginsCfg"];
  _Deserialize( &(p->pluginsCfg), pluginsCfg_json );
  auto& ogreCfg_json = json["ogreCfg"];
  _Deserialize( &(p->ogreCfg), ogreCfg_json );
  auto& resources_json = json["resources"];
  _Deserialize( &(p->resources), resources_json );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TOgreCfg* p, Jobj& obj )
{
  PUM::Push( obj, "release", p->release );
  PUM::Push( obj, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TOgreCfg* p, const json11::Json& json )
{
  POM::PopStr( json, "release", p->release );
  POM::PopStr( json, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Serialize( TOgreResources* p, Jobj& obj )
{
  
  Jobj release_c0;
  for ( auto& release_e0 : p->release )
  {
    Jarr release_c1;
    for ( auto& release_e1 : release_e0.second )
    {
      release_c1.push_back( release_e1 );
    }
    release_c0.insert( { fmt::format( "{}", release_e0.first ), release_c1 } );
  }
  PUM::PushMap( obj, "release", release_c0 );
}
//---------------------------------------------------------------------------------------
void TJsonSerializer::_Deserialize( TOgreResources* p, const json11::Json& json )
{
  
  auto& release_src0 = json["release"].object_items();
  for ( auto& release_e0 : release_src0 )
  {
    std::list<std::string> release_c1;
    auto& release_src1 = release_e0.second.array_items();
    for ( auto& release_e1 : release_src1 )
    {
      release_c1.push_back( release_e1.string_value() );
    }
    p->release.insert( { release_e0.first, release_c1 } );
  }
}
//---------------------------------------------------------------------------------------

/*

*/
// File has been generated by ReflectionCodeGenerator version 1.13 build 41, at 2020_09_03 08:33:27.985
	
#include "ShareDevJsonSerializer.h"
#include "JsonPopMaster.h"
#include "JsonPushMaster.h"


using POM = TJsonPopMaster;
using PUM = TJsonPushMaster;

void TShareDevJsonSerializer::_Serialize( TBaseResources* p, Jobj& obj )
{
    PUM::Push( obj, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TBaseResources* p, const json11::Json& json )
{
    POM::PopStr( json, "name", p->name );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TFrameworkResources* p, Jobj& obj )
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
void TShareDevJsonSerializer::_Deserialize( TFrameworkResources* p, const json11::Json& json )
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
void TShareDevJsonSerializer::_Serialize( TGUIResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);
    
    Jobj resources_c0;
    for ( auto& resources_e0 : p->resources )
    {
        Jarr resources_c1;
        for ( auto& resources_e1 : resources_e0.second )
        {
            resources_c1.push_back( resources_e1 );
        }
        resources_c0.insert( { PUM::ConvertToString( resources_e0.first ), resources_c1 } );
    }
    PUM::PushMap( obj, "resources", resources_c0 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGUIResources* p, const json11::Json& json )
{
    _Deserialize( (TBaseResources*)p, json);
    
    auto& resources_src0 = json["resources"].object_items();
    for ( auto& resources_e0 : resources_src0 )
    {
        std::list<std::string> resources_c1;
        auto& resources_src1 = resources_e0.second.array_items();
        for ( auto& resources_e1 : resources_src1 )
        {
            resources_c1.push_back( resources_e1.string_value() );
        }
        p->resources.insert( { resources_e0.first, resources_c1 } );
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TGameEngineResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);
    
    Jobj resources_c0;
    for ( auto& resources_e0 : p->resources )
    {
        Jarr resources_c1;
        for ( auto& resources_e1 : resources_e0.second )
        {
            resources_c1.push_back( resources_e1 );
        }
        resources_c0.insert( { PUM::ConvertToString( resources_e0.first ), resources_c1 } );
    }
    PUM::PushMap( obj, "resources", resources_c0 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGameEngineResources* p, const json11::Json& json )
{
    _Deserialize( (TBaseResources*)p, json);
    
    auto& resources_src0 = json["resources"].object_items();
    for ( auto& resources_e0 : resources_src0 )
    {
        std::list<std::string> resources_c1;
        auto& resources_src1 = resources_e0.second.array_items();
        for ( auto& resources_e1 : resources_src1 )
        {
            resources_c1.push_back( resources_e1.string_value() );
        }
        p->resources.insert( { resources_e0.first, resources_c1 } );
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TGameResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);
    
    Jobj resources_c0;
    for ( auto& resources_e0 : p->resources )
    {
        Jarr resources_c1;
        for ( auto& resources_e1 : resources_e0.second )
        {
            resources_c1.push_back( resources_e1 );
        }
        resources_c0.insert( { PUM::ConvertToString( resources_e0.first ), resources_c1 } );
    }
    PUM::PushMap( obj, "resources", resources_c0 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGameResources* p, const json11::Json& json )
{
    _Deserialize( (TBaseResources*)p, json);
    
    auto& resources_src0 = json["resources"].object_items();
    for ( auto& resources_e0 : resources_src0 )
    {
        std::list<std::string> resources_c1;
        auto& resources_src1 = resources_e0.second.array_items();
        for ( auto& resources_e1 : resources_src1 )
        {
            resources_c1.push_back( resources_e1.string_value() );
        }
        p->resources.insert( { resources_e0.first, resources_c1 } );
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TGraphicEngineResources* p, Jobj& obj )
{
    _Serialize( (TBaseResources*)p, obj);
    PUM::Push( obj, "terrainPath", p->terrainPath );
    Jobj pluginsCfg_obj;
    _Serialize( &(p->pluginsCfg), pluginsCfg_obj );
    PUM::Push( obj, "pluginsCfg", pluginsCfg_obj );
    Jobj ogreCfg_obj;
    _Serialize( &(p->ogreCfg), ogreCfg_obj );
    PUM::Push( obj, "ogreCfg", ogreCfg_obj );
    
    Jobj resources_c0;
    for ( auto& resources_e0 : p->resources )
    {
        Jarr resources_c1;
        for ( auto& resources_e1 : resources_e0.second )
        {
            resources_c1.push_back( resources_e1 );
        }
        resources_c0.insert( { PUM::ConvertToString( resources_e0.first ), resources_c1 } );
    }
    PUM::PushMap( obj, "resources", resources_c0 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TGraphicEngineResources* p, const json11::Json& json )
{
    _Deserialize( (TBaseResources*)p, json);
    POM::PopStr( json, "terrainPath", p->terrainPath );
    auto& pluginsCfg_json = json["pluginsCfg"];
    _Deserialize( &(p->pluginsCfg), pluginsCfg_json );
    auto& ogreCfg_json = json["ogreCfg"];
    _Deserialize( &(p->ogreCfg), ogreCfg_json );
    
    auto& resources_src0 = json["resources"].object_items();
    for ( auto& resources_e0 : resources_src0 )
    {
        std::list<std::string> resources_c1;
        auto& resources_src1 = resources_e0.second.array_items();
        for ( auto& resources_e1 : resources_src1 )
        {
            resources_c1.push_back( resources_e1.string_value() );
        }
        p->resources.insert( { resources_e0.first, resources_c1 } );
    }
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( TOgreCfg* p, Jobj& obj )
{
    PUM::Push( obj, "release", p->release );
    PUM::Push( obj, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( TOgreCfg* p, const json11::Json& json )
{
    POM::PopStr( json, "release", p->release );
    POM::PopStr( json, "debug", p->debug );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TMatrix16* p, Jobj& obj )
{
    PUM::Push( obj, "_11", p->_11 );
    PUM::Push( obj, "_12", p->_12 );
    PUM::Push( obj, "_13", p->_13 );
    PUM::Push( obj, "_14", p->_14 );
    PUM::Push( obj, "_21", p->_21 );
    PUM::Push( obj, "_22", p->_22 );
    PUM::Push( obj, "_23", p->_23 );
    PUM::Push( obj, "_24", p->_24 );
    PUM::Push( obj, "_31", p->_31 );
    PUM::Push( obj, "_32", p->_32 );
    PUM::Push( obj, "_33", p->_33 );
    PUM::Push( obj, "_34", p->_34 );
    PUM::Push( obj, "_41", p->_41 );
    PUM::Push( obj, "_42", p->_42 );
    PUM::Push( obj, "_43", p->_43 );
    PUM::Push( obj, "_44", p->_44 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TMatrix16* p, const json11::Json& json )
{
    POM::PopNum( json, "_11", p->_11 );
    POM::PopNum( json, "_12", p->_12 );
    POM::PopNum( json, "_13", p->_13 );
    POM::PopNum( json, "_14", p->_14 );
    POM::PopNum( json, "_21", p->_21 );
    POM::PopNum( json, "_22", p->_22 );
    POM::PopNum( json, "_23", p->_23 );
    POM::PopNum( json, "_24", p->_24 );
    POM::PopNum( json, "_31", p->_31 );
    POM::PopNum( json, "_32", p->_32 );
    POM::PopNum( json, "_33", p->_33 );
    POM::PopNum( json, "_34", p->_34 );
    POM::PopNum( json, "_41", p->_41 );
    POM::PopNum( json, "_42", p->_42 );
    POM::PopNum( json, "_43", p->_43 );
    POM::PopNum( json, "_44", p->_44 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TMatrix9* p, Jobj& obj )
{
    PUM::Push( obj, "_11", p->_11 );
    PUM::Push( obj, "_12", p->_12 );
    PUM::Push( obj, "_13", p->_13 );
    PUM::Push( obj, "_21", p->_21 );
    PUM::Push( obj, "_22", p->_22 );
    PUM::Push( obj, "_23", p->_23 );
    PUM::Push( obj, "_31", p->_31 );
    PUM::Push( obj, "_32", p->_32 );
    PUM::Push( obj, "_33", p->_33 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TMatrix9* p, const json11::Json& json )
{
    POM::PopNum( json, "_11", p->_11 );
    POM::PopNum( json, "_12", p->_12 );
    POM::PopNum( json, "_13", p->_13 );
    POM::PopNum( json, "_21", p->_21 );
    POM::PopNum( json, "_22", p->_22 );
    POM::PopNum( json, "_23", p->_23 );
    POM::PopNum( json, "_31", p->_31 );
    POM::PopNum( json, "_32", p->_32 );
    POM::PopNum( json, "_33", p->_33 );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TOrientation* p, Jobj& obj )
{
    Jobj axis_obj;
    _Serialize( &(p->axis), axis_obj );
    PUM::Push( obj, "axis", axis_obj );
    PUM::Push( obj, "angle", p->angle );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TOrientation* p, const json11::Json& json )
{
    auto& axis_json = json["axis"];
    _Deserialize( &(p->axis), axis_json );
    POM::PopNum( json, "angle", p->angle );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TPlane* p, Jobj& obj )
{
    PUM::Push( obj, "a", p->a );
    PUM::Push( obj, "b", p->b );
    PUM::Push( obj, "c", p->c );
    PUM::Push( obj, "d", p->d );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TPlane* p, const json11::Json& json )
{
    POM::PopNum( json, "a", p->a );
    POM::PopNum( json, "b", p->b );
    POM::PopNum( json, "c", p->c );
    POM::PopNum( json, "d", p->d );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TPoint2* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TPoint2* p, const json11::Json& json )
{
    POM::PopNum( json, "x", p->x );
    POM::PopNum( json, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TQuaternion* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
    PUM::Push( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TQuaternion* p, const json11::Json& json )
{
    POM::PopNum( json, "x", p->x );
    POM::PopNum( json, "y", p->y );
    POM::PopNum( json, "z", p->z );
    POM::PopNum( json, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector2* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector2* p, const json11::Json& json )
{
    POM::PopNum( json, "x", p->x );
    POM::PopNum( json, "y", p->y );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector3* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector3* p, const json11::Json& json )
{
    POM::PopNum( json, "x", p->x );
    POM::PopNum( json, "y", p->y );
    POM::PopNum( json, "z", p->z );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Serialize( nsMathTools::TVector4* p, Jobj& obj )
{
    PUM::Push( obj, "x", p->x );
    PUM::Push( obj, "y", p->y );
    PUM::Push( obj, "z", p->z );
    PUM::Push( obj, "w", p->w );
}
//---------------------------------------------------------------------------------------
void TShareDevJsonSerializer::_Deserialize( nsMathTools::TVector4* p, const json11::Json& json )
{
    POM::PopNum( json, "x", p->x );
    POM::PopNum( json, "y", p->y );
    POM::PopNum( json, "z", p->z );
    POM::PopNum( json, "w", p->w );
}
//---------------------------------------------------------------------------------------

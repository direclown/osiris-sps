// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "extensionsmoduleviewerhidden.h"
#include "xmldocument.h"
#include "ideskin.h"
#include "idesession.h"
#include "ideportalcontrol.h"
#include "datatree.h"
#include "htmlattributes.h"
#include "htmlevent.h"
#include "eventssource.h"
#include "htmlvirtualpage.h"
#include "htmlwriter.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "httpsession.h"
#include "extensionsmoduleviewerhidden.pypp.hpp"

namespace bp = boost::python;

struct ExtensionsModuleViewerHidden_wrapper : ::osiris::ExtensionsModuleViewerHidden, ::osiris::PythonWrapper< ::osiris::ExtensionsModuleViewerHidden > {

    ExtensionsModuleViewerHidden_wrapper( )
    : ::osiris::ExtensionsModuleViewerHidden( )
      , ::osiris::PythonWrapper< ::osiris::ExtensionsModuleViewerHidden >(){
        // null constructor
    
    }

    virtual bool getShowBlock(  ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_getShowBlock = this->get_override( "getShowBlock" ) )
            return func_getShowBlock(  );
        else{
            __pystate.leave();
            return this->::osiris::ExtensionsModuleViewerHidden::getShowBlock(  );
        }
    }
    
    bool default_getShowBlock(  ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::ExtensionsModuleViewerHidden::getShowBlock( );
    }

    virtual void onLoad(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onLoad = this->get_override( "onLoad" ) )
            func_onLoad(  );
        else{
            __pystate.leave();
            this->::osiris::ExtensionsModuleViewerHidden::onLoad(  );
        }
    }
    
    virtual void default_onLoad(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::ExtensionsModuleViewerHidden::onLoad( );
    }

    bool decodeEvent( ::osiris::String const & command, ::osiris::String & eventName, ::osiris::HtmlEvent & e ) const {
        return ::osiris::IHtmlControl::decodeEvent( boost::ref(command), boost::ref(eventName), boost::ref(e) );
    }

    ::osiris::String encodeEvent( ::osiris::String const & eventName, ::osiris::HtmlEvent const * e=(nullptr) ) const {
        return ::osiris::IHtmlControl::encodeEvent( boost::ref(eventName), boost::python::ptr(e) );
    }

    virtual ::boost::shared_ptr< osiris::HttpSession > getSession(  ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_getSession = this->get_override( "getSession" ) )
            return func_getSession(  );
        else{
            __pystate.leave();
            return this->::osiris::IHtmlControl::getSession(  );
        }
    }
    
    ::boost::shared_ptr< osiris::HttpSession > default_getSession(  ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::IHtmlControl::getSession( );
    }

    virtual bool init( ::boost::shared_ptr< osiris::IExtensionsModule > module, ::osiris::String const & title, ::osiris::UniqueID const & instance, ::osiris::String const & xml ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_init = this->get_override( "init" ) )
            return func_init( module, boost::ref(title), boost::ref(instance), boost::ref(xml) );
        else{
            __pystate.leave();
            return this->::osiris::ExtensionsModuleControl::init( module, boost::ref(title), boost::ref(instance), boost::ref(xml) );
        }
    }
    
    bool default_init( ::boost::shared_ptr< osiris::IExtensionsModule > module, ::osiris::String const & title, ::osiris::UniqueID const & instance, ::osiris::String const & xml ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::ExtensionsModuleControl::init( module, boost::ref(title), boost::ref(instance), boost::ref(xml) );
    }

    virtual void onEvent( ::osiris::String const & name, ::osiris::IEvent * e=(nullptr) ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onEvent = this->get_override( "onEvent" ) )
            func_onEvent( boost::ref(name), boost::python::ptr(e) );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onEvent( boost::ref(name), boost::python::ptr(e) );
        }
    }
    
    virtual void default_onEvent( ::osiris::String const & name, ::osiris::IEvent * e=(nullptr) ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onEvent( boost::ref(name), boost::python::ptr(e) );
    }

    virtual void onInit(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onInit = this->get_override( "onInit" ) )
            func_onInit(  );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onInit(  );
        }
    }
    
    virtual void default_onInit(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onInit( );
    }

    virtual void onLoadViewState( ::osiris::DataTree const & state ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onLoadViewState = this->get_override( "onLoadViewState" ) )
            func_onLoadViewState( boost::ref(state) );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onLoadViewState( boost::ref(state) );
        }
    }
    
    virtual void default_onLoadViewState( ::osiris::DataTree const & state ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onLoadViewState( boost::ref(state) );
    }

    virtual void onPreRender(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onPreRender = this->get_override( "onPreRender" ) )
            func_onPreRender(  );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onPreRender(  );
        }
    }
    
    virtual void default_onPreRender(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onPreRender( );
    }

    virtual void onRender( ::osiris::HtmlWriter & writer ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onRender = this->get_override( "onRender" ) )
            func_onRender( boost::ref(writer) );
        else{
            __pystate.leave();
            this->::osiris::HtmlDiv::onRender( boost::ref(writer) );
        }
    }
    
    virtual void default_onRender( ::osiris::HtmlWriter & writer ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::HtmlDiv::onRender( boost::ref(writer) );
    }

    virtual void onSaveViewState( ::osiris::DataTree & state ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onSaveViewState = this->get_override( "onSaveViewState" ) )
            func_onSaveViewState( boost::ref(state) );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onSaveViewState( boost::ref(state) );
        }
    }
    
    virtual void default_onSaveViewState( ::osiris::DataTree & state ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onSaveViewState( boost::ref(state) );
    }

    virtual void renderAttributes( ::osiris::HtmlWriter & writer ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_renderAttributes = this->get_override( "renderAttributes" ) )
            func_renderAttributes( boost::ref(writer) );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::renderAttributes( boost::ref(writer) );
        }
    }
    
    void default_renderAttributes( ::osiris::HtmlWriter & writer ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::renderAttributes( boost::ref(writer) );
    }

    virtual void renderChilds( ::osiris::HtmlWriter & writer ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_renderChilds = this->get_override( "renderChilds" ) )
            func_renderChilds( boost::ref(writer) );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::renderChilds( boost::ref(writer) );
        }
    }
    
    void default_renderChilds( ::osiris::HtmlWriter & writer ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::renderChilds( boost::ref(writer) );
    }

    void saveViewState( ::osiris::DataTree & states ){
        ::osiris::IHtmlControl::saveViewState( boost::ref(states) );
    }

};

void register_ExtensionsModuleViewerHidden_class(){

    { //::osiris::ExtensionsModuleViewerHidden
        typedef ::boost::python::class_< ExtensionsModuleViewerHidden_wrapper, ::boost::python::bases< ::osiris::ExtensionsModuleViewer >, ::boost::noncopyable > ExtensionsModuleViewerHidden_exposer_t;
        ExtensionsModuleViewerHidden_exposer_t ExtensionsModuleViewerHidden_exposer = ExtensionsModuleViewerHidden_exposer_t( "ExtensionsModuleViewerHidden", ::boost::python::init< >() );
        ::boost::python::scope ExtensionsModuleViewerHidden_scope( ExtensionsModuleViewerHidden_exposer );
        { //::osiris::ExtensionsModuleViewerHidden::getShowBlock
        
            typedef bool ( ::osiris::ExtensionsModuleViewerHidden::*getShowBlock_function_type )(  ) const;
            typedef bool ( ExtensionsModuleViewerHidden_wrapper::*default_getShowBlock_function_type )(  ) const;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "getShowBlock"
                , getShowBlock_function_type(&::osiris::ExtensionsModuleViewerHidden::getShowBlock)
                , default_getShowBlock_function_type(&ExtensionsModuleViewerHidden_wrapper::default_getShowBlock) );
        
        }
        { //::osiris::ExtensionsModuleViewerHidden::onLoad
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onLoad_function_type )(  ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onLoad"
                , onLoad_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onLoad ) );
        
        }
        { //::osiris::IHtmlControl::decodeEvent
        
            typedef bool ( ExtensionsModuleViewerHidden_wrapper::*decodeEvent_function_type )( ::osiris::String const &,::osiris::String &,::osiris::HtmlEvent & ) const;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "decodeEvent"
                , decodeEvent_function_type( &ExtensionsModuleViewerHidden_wrapper::decodeEvent )
                , ( ::boost::python::arg("command"), ::boost::python::arg("eventName"), ::boost::python::arg("e") ) );
        
        }
        { //::osiris::IHtmlControl::encodeEvent
        
            typedef ::osiris::String ( ExtensionsModuleViewerHidden_wrapper::*encodeEvent_function_type )( ::osiris::String const &,::osiris::HtmlEvent const * ) const;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "encodeEvent"
                , encodeEvent_function_type( &ExtensionsModuleViewerHidden_wrapper::encodeEvent )
                , ( ::boost::python::arg("eventName"), ::boost::python::arg("e")=(nullptr) ) );
        
        }
        { //::osiris::IHtmlControl::getSession
        
            typedef ::boost::shared_ptr< osiris::HttpSession > ( ::osiris::IHtmlControl::*getSession_function_type )(  ) const;
            typedef ::boost::shared_ptr< osiris::HttpSession > ( ExtensionsModuleViewerHidden_wrapper::*default_getSession_function_type )(  ) const;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "getSession"
                , getSession_function_type(&::osiris::IHtmlControl::getSession)
                , default_getSession_function_type(&ExtensionsModuleViewerHidden_wrapper::default_getSession) );
        
        }
        { //::osiris::ExtensionsModuleControl::init
        
            typedef bool ( ::osiris::ExtensionsModuleControl::*init_function_type )( ::boost::shared_ptr< osiris::IExtensionsModule >,::osiris::String const &,::osiris::UniqueID const &,::osiris::String const & ) ;
            typedef bool ( ExtensionsModuleViewerHidden_wrapper::*default_init_function_type )( ::boost::shared_ptr< osiris::IExtensionsModule >,::osiris::String const &,::osiris::UniqueID const &,::osiris::String const & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "init"
                , init_function_type(&::osiris::ExtensionsModuleControl::init)
                , default_init_function_type(&ExtensionsModuleViewerHidden_wrapper::default_init)
                , ( ::boost::python::arg("module"), ::boost::python::arg("title"), ::boost::python::arg("instance"), ::boost::python::arg("xml") ) );
        
        }
        { //::osiris::IHtmlControl::onEvent
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onEvent_function_type )( ::osiris::String const &,::osiris::IEvent * ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onEvent"
                , onEvent_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onEvent )
                , ( ::boost::python::arg("name"), ::boost::python::arg("e")=(nullptr) ) );
        
        }
        { //::osiris::IHtmlControl::onInit
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onInit_function_type )(  ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onInit"
                , onInit_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onInit ) );
        
        }
        { //::osiris::IHtmlControl::onLoadViewState
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onLoadViewState_function_type )( ::osiris::DataTree const & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onLoadViewState"
                , onLoadViewState_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onLoadViewState )
                , ( ::boost::python::arg("state") ) );
        
        }
        { //::osiris::IHtmlControl::onPreRender
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onPreRender_function_type )(  ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onPreRender"
                , onPreRender_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onPreRender ) );
        
        }
        { //::osiris::HtmlDiv::onRender
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onRender_function_type )( ::osiris::HtmlWriter & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onRender"
                , onRender_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onRender )
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::onSaveViewState
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*onSaveViewState_function_type )( ::osiris::DataTree & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "onSaveViewState"
                , onSaveViewState_function_type( &ExtensionsModuleViewerHidden_wrapper::default_onSaveViewState )
                , ( ::boost::python::arg("state") ) );
        
        }
        { //::osiris::IHtmlControl::renderAttributes
        
            typedef void ( ::osiris::IHtmlControl::*renderAttributes_function_type )( ::osiris::HtmlWriter & ) ;
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*default_renderAttributes_function_type )( ::osiris::HtmlWriter & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "renderAttributes"
                , renderAttributes_function_type(&::osiris::IHtmlControl::renderAttributes)
                , default_renderAttributes_function_type(&ExtensionsModuleViewerHidden_wrapper::default_renderAttributes)
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::renderChilds
        
            typedef void ( ::osiris::IHtmlControl::*renderChilds_function_type )( ::osiris::HtmlWriter & ) ;
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*default_renderChilds_function_type )( ::osiris::HtmlWriter & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "renderChilds"
                , renderChilds_function_type(&::osiris::IHtmlControl::renderChilds)
                , default_renderChilds_function_type(&ExtensionsModuleViewerHidden_wrapper::default_renderChilds)
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::saveViewState
        
            typedef void ( ExtensionsModuleViewerHidden_wrapper::*saveViewState_function_type )( ::osiris::DataTree & ) ;
            
            ExtensionsModuleViewerHidden_exposer.def( 
                "saveViewState"
                , saveViewState_function_type( &ExtensionsModuleViewerHidden_wrapper::saveViewState )
                , ( ::boost::python::arg("states") ) );
        
        }
        { //property "showBlock"[fget=::osiris::ExtensionsModuleViewerHidden::getShowBlock]
        
            typedef bool ( ::osiris::ExtensionsModuleViewerHidden::*fget )(  ) const;
            
            ExtensionsModuleViewerHidden_exposer.add_property( 
                "showBlock"
                , fget( &::osiris::ExtensionsModuleViewerHidden::getShowBlock )
                , "get property, built on top of \"bool osiris::ExtensionsModuleViewerHidden::getShowBlock() const [member function]\"" );
        
        }
    }

}

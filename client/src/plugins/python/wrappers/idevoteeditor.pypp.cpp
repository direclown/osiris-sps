// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "idevoteeditor.h"
#include "ideskin.h"
#include "idesession.h"
#include "datatree.h"
#include "htmlattributes.h"
#include "htmlevent.h"
#include "eventssource.h"
#include "htmlvirtualpage.h"
#include "htmlwriter.h"
#include "httprequest.h"
#include "httpresponse.h"
#include "httpsession.h"
#include "idevoteeditor.pypp.hpp"

namespace bp = boost::python;

struct IdeVoteEditor_wrapper : ::osiris::IdeVoteEditor, ::osiris::PythonWrapper< ::osiris::IdeVoteEditor > {

    IdeVoteEditor_wrapper( )
    : ::osiris::IdeVoteEditor( )
      , ::osiris::PythonWrapper< ::osiris::IdeVoteEditor >(){
        // null constructor
    
    }

    static boost::python::object getValue( ::osiris::IdeVoteEditor const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::uint32 result = inst.getValue();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    static boost::python::object isNull( ::osiris::IdeVoteEditor const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        bool result = inst.isNull();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    static void setNull( ::osiris::IdeVoteEditor & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        inst.setNull();
        __pythreadSaver.restore();
    }

    static boost::python::object getEventUpdate( ::osiris::IdeVoteEditor const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::boost::shared_ptr<osiris::EventSource> result = inst.getEventUpdate();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    virtual void onInit(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onInit = this->get_override( "onInit" ) )
            func_onInit(  );
        else{
            __pystate.leave();
            this->::osiris::IdeVoteEditor::onInit(  );
        }
    }
    
    virtual void default_onInit(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IdeVoteEditor::onInit( );
    }

    static void setValue( ::osiris::IdeVoteEditor & inst, ::osiris::uint32 value ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        inst.setValue(value);
        __pythreadSaver.restore();
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

    virtual void onLoad(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onLoad = this->get_override( "onLoad" ) )
            func_onLoad(  );
        else{
            __pystate.leave();
            this->::osiris::IHtmlControl::onLoad(  );
        }
    }
    
    virtual void default_onLoad(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onLoad( );
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
            this->::osiris::IHtmlControl::onRender( boost::ref(writer) );
        }
    }
    
    virtual void default_onRender( ::osiris::HtmlWriter & writer ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IHtmlControl::onRender( boost::ref(writer) );
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

void register_IdeVoteEditor_class(){

    { //::osiris::IdeVoteEditor
        typedef ::boost::python::class_< IdeVoteEditor_wrapper, ::boost::python::bases< ::osiris::IPortalPageControl< osiris::IHtmlControl > >, ::boost::noncopyable > IdeVoteEditor_exposer_t;
        IdeVoteEditor_exposer_t IdeVoteEditor_exposer = IdeVoteEditor_exposer_t( "IdeVoteEditor", ::boost::python::init< >() );
        ::boost::python::scope IdeVoteEditor_scope( IdeVoteEditor_exposer );
        { //::osiris::IdeVoteEditor::getValue
        
            typedef boost::python::object ( *getValue_function_type )( ::osiris::IdeVoteEditor const & );
            
            IdeVoteEditor_exposer.def( 
                "getValue"
                , getValue_function_type( &IdeVoteEditor_wrapper::getValue ) );
        
        }
        { //::osiris::IdeVoteEditor::isNull
        
            typedef boost::python::object ( *isNull_function_type )( ::osiris::IdeVoteEditor const & );
            
            IdeVoteEditor_exposer.def( 
                "isNull"
                , isNull_function_type( &IdeVoteEditor_wrapper::isNull ) );
        
        }
        { //::osiris::IdeVoteEditor::setNull
        
            typedef void ( *setNull_function_type )( ::osiris::IdeVoteEditor & );
            
            IdeVoteEditor_exposer.def( 
                "setNull"
                , setNull_function_type( &IdeVoteEditor_wrapper::setNull ) );
        
        }
        { //::osiris::IdeVoteEditor::getEventUpdate
        
            typedef boost::python::object ( *getEventUpdate_function_type )( ::osiris::IdeVoteEditor const & );
            
            IdeVoteEditor_exposer.def( 
                "getEventUpdate"
                , getEventUpdate_function_type( &IdeVoteEditor_wrapper::getEventUpdate ) );
        
        }
        { //::osiris::IdeVoteEditor::onInit
        
            typedef void ( IdeVoteEditor_wrapper::*onInit_function_type )(  ) ;
            
            IdeVoteEditor_exposer.def( 
                "onInit"
                , onInit_function_type( &IdeVoteEditor_wrapper::default_onInit ) );
        
        }
        { //::osiris::IdeVoteEditor::setValue
        
            typedef void ( *setValue_function_type )( ::osiris::IdeVoteEditor &,::osiris::uint32 );
            
            IdeVoteEditor_exposer.def( 
                "setValue"
                , setValue_function_type( &IdeVoteEditor_wrapper::setValue )
                , ( ::boost::python::arg("inst"), ::boost::python::arg("value") ) );
        
        }
        { //::osiris::IHtmlControl::decodeEvent
        
            typedef bool ( IdeVoteEditor_wrapper::*decodeEvent_function_type )( ::osiris::String const &,::osiris::String &,::osiris::HtmlEvent & ) const;
            
            IdeVoteEditor_exposer.def( 
                "decodeEvent"
                , decodeEvent_function_type( &IdeVoteEditor_wrapper::decodeEvent )
                , ( ::boost::python::arg("command"), ::boost::python::arg("eventName"), ::boost::python::arg("e") ) );
        
        }
        { //::osiris::IHtmlControl::encodeEvent
        
            typedef ::osiris::String ( IdeVoteEditor_wrapper::*encodeEvent_function_type )( ::osiris::String const &,::osiris::HtmlEvent const * ) const;
            
            IdeVoteEditor_exposer.def( 
                "encodeEvent"
                , encodeEvent_function_type( &IdeVoteEditor_wrapper::encodeEvent )
                , ( ::boost::python::arg("eventName"), ::boost::python::arg("e")=(nullptr) ) );
        
        }
        { //::osiris::IHtmlControl::getSession
        
            typedef ::boost::shared_ptr< osiris::HttpSession > ( ::osiris::IHtmlControl::*getSession_function_type )(  ) const;
            typedef ::boost::shared_ptr< osiris::HttpSession > ( IdeVoteEditor_wrapper::*default_getSession_function_type )(  ) const;
            
            IdeVoteEditor_exposer.def( 
                "getSession"
                , getSession_function_type(&::osiris::IHtmlControl::getSession)
                , default_getSession_function_type(&IdeVoteEditor_wrapper::default_getSession) );
        
        }
        { //::osiris::IHtmlControl::onEvent
        
            typedef void ( IdeVoteEditor_wrapper::*onEvent_function_type )( ::osiris::String const &,::osiris::IEvent * ) ;
            
            IdeVoteEditor_exposer.def( 
                "onEvent"
                , onEvent_function_type( &IdeVoteEditor_wrapper::default_onEvent )
                , ( ::boost::python::arg("name"), ::boost::python::arg("e")=(nullptr) ) );
        
        }
        { //::osiris::IHtmlControl::onLoad
        
            typedef void ( IdeVoteEditor_wrapper::*onLoad_function_type )(  ) ;
            
            IdeVoteEditor_exposer.def( 
                "onLoad"
                , onLoad_function_type( &IdeVoteEditor_wrapper::default_onLoad ) );
        
        }
        { //::osiris::IHtmlControl::onLoadViewState
        
            typedef void ( IdeVoteEditor_wrapper::*onLoadViewState_function_type )( ::osiris::DataTree const & ) ;
            
            IdeVoteEditor_exposer.def( 
                "onLoadViewState"
                , onLoadViewState_function_type( &IdeVoteEditor_wrapper::default_onLoadViewState )
                , ( ::boost::python::arg("state") ) );
        
        }
        { //::osiris::IHtmlControl::onPreRender
        
            typedef void ( IdeVoteEditor_wrapper::*onPreRender_function_type )(  ) ;
            
            IdeVoteEditor_exposer.def( 
                "onPreRender"
                , onPreRender_function_type( &IdeVoteEditor_wrapper::default_onPreRender ) );
        
        }
        { //::osiris::IHtmlControl::onRender
        
            typedef void ( IdeVoteEditor_wrapper::*onRender_function_type )( ::osiris::HtmlWriter & ) ;
            
            IdeVoteEditor_exposer.def( 
                "onRender"
                , onRender_function_type( &IdeVoteEditor_wrapper::default_onRender )
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::onSaveViewState
        
            typedef void ( IdeVoteEditor_wrapper::*onSaveViewState_function_type )( ::osiris::DataTree & ) ;
            
            IdeVoteEditor_exposer.def( 
                "onSaveViewState"
                , onSaveViewState_function_type( &IdeVoteEditor_wrapper::default_onSaveViewState )
                , ( ::boost::python::arg("state") ) );
        
        }
        { //::osiris::IHtmlControl::renderAttributes
        
            typedef void ( ::osiris::IHtmlControl::*renderAttributes_function_type )( ::osiris::HtmlWriter & ) ;
            typedef void ( IdeVoteEditor_wrapper::*default_renderAttributes_function_type )( ::osiris::HtmlWriter & ) ;
            
            IdeVoteEditor_exposer.def( 
                "renderAttributes"
                , renderAttributes_function_type(&::osiris::IHtmlControl::renderAttributes)
                , default_renderAttributes_function_type(&IdeVoteEditor_wrapper::default_renderAttributes)
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::renderChilds
        
            typedef void ( ::osiris::IHtmlControl::*renderChilds_function_type )( ::osiris::HtmlWriter & ) ;
            typedef void ( IdeVoteEditor_wrapper::*default_renderChilds_function_type )( ::osiris::HtmlWriter & ) ;
            
            IdeVoteEditor_exposer.def( 
                "renderChilds"
                , renderChilds_function_type(&::osiris::IHtmlControl::renderChilds)
                , default_renderChilds_function_type(&IdeVoteEditor_wrapper::default_renderChilds)
                , ( ::boost::python::arg("writer") ) );
        
        }
        { //::osiris::IHtmlControl::saveViewState
        
            typedef void ( IdeVoteEditor_wrapper::*saveViewState_function_type )( ::osiris::DataTree & ) ;
            
            IdeVoteEditor_exposer.def( 
                "saveViewState"
                , saveViewState_function_type( &IdeVoteEditor_wrapper::saveViewState )
                , ( ::boost::python::arg("states") ) );
        
        }
        { //property "value"[fget=::osiris::IdeVoteEditor::getValue, fset=::osiris::IdeVoteEditor::setValue]
        
            typedef ::osiris::uint32 ( ::osiris::IdeVoteEditor::*fget )(  ) const;
            typedef void ( ::osiris::IdeVoteEditor::*fset )( ::osiris::uint32 ) ;
            
            IdeVoteEditor_exposer.add_property( 
                "value"
                , fget( &::osiris::IdeVoteEditor::getValue )
                , fset( &::osiris::IdeVoteEditor::setValue )
                , "get\\set property, built on top of \"osiris::uint32 osiris::IdeVoteEditor::getValue() const [member function]\" and \"void osiris::IdeVoteEditor::setValue(osiris::uint32 value) [member function]\"" );
        
        }
        { //property "eventUpdate"[fget=::osiris::IdeVoteEditor::getEventUpdate]
        
            typedef ::boost::shared_ptr<osiris::EventSource> ( ::osiris::IdeVoteEditor::*fget )(  ) const;
            
            IdeVoteEditor_exposer.add_property( 
                "eventUpdate"
                , fget( &::osiris::IdeVoteEditor::getEventUpdate )
                , "get property, built on top of \"boost::shared_ptr<osiris::EventSource> osiris::IdeVoteEditor::getEventUpdate() const [member function]\"" );
        
        }
    }

}

// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "omlpopup.h"
#include "omlpopup.pypp.hpp"

namespace bp = boost::python;

struct OMLPopup_wrapper : ::osiris::OMLPopup, ::osiris::PythonWrapper< ::osiris::OMLPopup > {

    OMLPopup_wrapper(::osiris::OMLPopup const & arg )
    : ::osiris::OMLPopup( arg )
      , ::osiris::PythonWrapper< ::osiris::OMLPopup >(){
        // copy constructor
        
    }

    OMLPopup_wrapper(::osiris::String const & tag )
    : ::osiris::OMLPopup( boost::ref(tag) )
      , ::osiris::PythonWrapper< ::osiris::OMLPopup >(){
        // constructor
    
    }

    virtual ::osiris::String processHtml( ::boost::shared_ptr< osiris::OMLItem > i, ::boost::shared_ptr< osiris::OMLContext > context ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_processHtml = this->get_override( "processHtml" ) )
            return func_processHtml( i, context );
        else{
            __pystate.leave();
            return this->::osiris::OMLPopup::processHtml( i, context );
        }
    }
    
    ::osiris::String default_processHtml( ::boost::shared_ptr< osiris::OMLItem > i, ::boost::shared_ptr< osiris::OMLContext > context ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::OMLPopup::processHtml( i, context );
    }

    virtual bool allowRowMode(  ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_allowRowMode = this->get_override( "allowRowMode" ) )
            return func_allowRowMode(  );
        else{
            __pystate.leave();
            return this->::osiris::IOMLCode::allowRowMode(  );
        }
    }
    
    bool default_allowRowMode(  ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::IOMLCode::allowRowMode( );
    }

    virtual ::osiris::String processOsml( ::boost::shared_ptr< osiris::OMLItem > i, ::boost::shared_ptr< osiris::OMLContext > context ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_processOsml = this->get_override( "processOsml" ) )
            return func_processOsml( i, context );
        else{
            __pystate.leave();
            return this->::osiris::IOMLCode::processOsml( i, context );
        }
    }
    
    ::osiris::String default_processOsml( ::boost::shared_ptr< osiris::OMLItem > i, ::boost::shared_ptr< osiris::OMLContext > context ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::IOMLCode::processOsml( i, context );
    }

};

void register_OMLPopup_class(){

    { //::osiris::OMLPopup
        typedef ::boost::python::class_< OMLPopup_wrapper, ::boost::python::bases< ::osiris::IOMLCode > > OMLPopup_exposer_t;
        OMLPopup_exposer_t OMLPopup_exposer = OMLPopup_exposer_t( "OMLPopup", ::boost::python::init< ::osiris::String const & >(( ::boost::python::arg("tag") )) );
        ::boost::python::scope OMLPopup_scope( OMLPopup_exposer );
        ::boost::python::implicitly_convertible< ::osiris::String const &, ::osiris::OMLPopup >();
        { //::osiris::OMLPopup::processHtml
        
            typedef ::osiris::String ( ::osiris::OMLPopup::*processHtml_function_type )( ::boost::shared_ptr< osiris::OMLItem >,::boost::shared_ptr< osiris::OMLContext > ) const;
            typedef ::osiris::String ( OMLPopup_wrapper::*default_processHtml_function_type )( ::boost::shared_ptr< osiris::OMLItem >,::boost::shared_ptr< osiris::OMLContext > ) const;
            
            OMLPopup_exposer.def( 
                "processHtml"
                , processHtml_function_type(&::osiris::OMLPopup::processHtml)
                , default_processHtml_function_type(&OMLPopup_wrapper::default_processHtml)
                , ( ::boost::python::arg("i"), ::boost::python::arg("context") ) );
        
        }
        { //::osiris::IOMLCode::allowRowMode
        
            typedef bool ( ::osiris::IOMLCode::*allowRowMode_function_type )(  ) const;
            typedef bool ( OMLPopup_wrapper::*default_allowRowMode_function_type )(  ) const;
            
            OMLPopup_exposer.def( 
                "allowRowMode"
                , allowRowMode_function_type(&::osiris::IOMLCode::allowRowMode)
                , default_allowRowMode_function_type(&OMLPopup_wrapper::default_allowRowMode) );
        
        }
        { //::osiris::IOMLCode::processOsml
        
            typedef ::osiris::String ( ::osiris::IOMLCode::*processOsml_function_type )( ::boost::shared_ptr< osiris::OMLItem >,::boost::shared_ptr< osiris::OMLContext > ) const;
            typedef ::osiris::String ( OMLPopup_wrapper::*default_processOsml_function_type )( ::boost::shared_ptr< osiris::OMLItem >,::boost::shared_ptr< osiris::OMLContext > ) const;
            
            OMLPopup_exposer.def( 
                "processOsml"
                , processOsml_function_type(&::osiris::IOMLCode::processOsml)
                , default_processOsml_function_type(&OMLPopup_wrapper::default_processOsml)
                , ( ::boost::python::arg("i"), ::boost::python::arg("context") ) );
        
        }
    }

}

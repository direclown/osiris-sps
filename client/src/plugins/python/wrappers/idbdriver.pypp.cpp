// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "idbdriver.h"
#include "idbconnection.h"
#include "idboptions.h"
#include "idbdriver.pypp.hpp"

namespace bp = boost::python;

struct IDbDriver_wrapper : ::osiris::IDbDriver, ::osiris::PythonWrapper< ::osiris::IDbDriver > {

    IDbDriver_wrapper( )
    : ::osiris::IDbDriver( )
      , ::osiris::PythonWrapper< ::osiris::IDbDriver >(){
        // null constructor
    
    }

    virtual ::std::string getName(  ) const {
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_getName = this->get_override( "getName" );
        return func_getName(  ).operator std::string();
    }

    virtual ::std::string getDescription(  ) const {
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_getDescription = this->get_override( "getDescription" );
        return func_getDescription(  ).operator std::string();
    }

    virtual ::boost::shared_ptr< osiris::IDbOptions > createOptions(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_createOptions = this->get_override( "createOptions" );
        return func_createOptions(  );
    }

    virtual ::boost::shared_ptr< osiris::IDbConnection > createConnection( ::std::string const & database, ::boost::shared_ptr< osiris::IDbOptions > options ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_createConnection = this->get_override( "createConnection" );
        return func_createConnection( database, options );
    }

    virtual bool createDatabase( ::std::string const & name, ::boost::shared_ptr< osiris::IDbOptions > options ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_createDatabase = this->get_override( "createDatabase" );
        return func_createDatabase( name, options );
    }

    virtual bool removeDatabase( ::std::string const & name, ::boost::shared_ptr< osiris::IDbOptions > options ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_removeDatabase = this->get_override( "removeDatabase" );
        return func_removeDatabase( name, options );
    }

    virtual bool databaseExists( ::std::string const & name, ::boost::shared_ptr< osiris::IDbOptions > options ) const {
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_databaseExists = this->get_override( "databaseExists" );
        return func_databaseExists( name, options );
    }

};

void register_IDbDriver_class(){

    { //::osiris::IDbDriver
        typedef ::boost::python::class_< IDbDriver_wrapper, ::boost::noncopyable > IDbDriver_exposer_t;
        IDbDriver_exposer_t IDbDriver_exposer = IDbDriver_exposer_t( "IDbDriver", ::boost::python::init< >() );
        ::boost::python::scope IDbDriver_scope( IDbDriver_exposer );
        { //::osiris::IDbDriver::getName
        
            typedef ::std::string ( ::osiris::IDbDriver::*getName_function_type )(  ) const;
            
            IDbDriver_exposer.def( 
                "getName"
                , ( getName_function_type(&::osiris::IDbDriver::getName) ) );
        
        }
        { //::osiris::IDbDriver::getDescription
        
            typedef ::std::string ( ::osiris::IDbDriver::*getDescription_function_type )(  ) const;
            
            IDbDriver_exposer.def( 
                "getDescription"
                , ( getDescription_function_type(&::osiris::IDbDriver::getDescription) ) );
        
        }
        { //::osiris::IDbDriver::createOptions
        
            typedef ::boost::shared_ptr<osiris::IDbOptions> ( ::osiris::IDbDriver::*createOptions_function_type )(  ) ;
            
            IDbDriver_exposer.def( 
                "createOptions"
                , ( createOptions_function_type(&::osiris::IDbDriver::createOptions) ) );
        
        }
        { //::osiris::IDbDriver::createConnection
        
            typedef ::boost::shared_ptr<osiris::IDbConnection> ( ::osiris::IDbDriver::*createConnection_function_type )( ::std::string const &,::boost::shared_ptr<osiris::IDbOptions> ) ;
            
            IDbDriver_exposer.def( 
                "createConnection"
                , ( createConnection_function_type(&::osiris::IDbDriver::createConnection) )
                , ( ::boost::python::arg("database"), ::boost::python::arg("options") ) );
        
        }
        { //::osiris::IDbDriver::createDatabase
        
            typedef bool ( ::osiris::IDbDriver::*createDatabase_function_type )( ::std::string const &,::boost::shared_ptr<osiris::IDbOptions> ) ;
            
            IDbDriver_exposer.def( 
                "createDatabase"
                , ( createDatabase_function_type(&::osiris::IDbDriver::createDatabase) )
                , ( ::boost::python::arg("name"), ::boost::python::arg("options") ) );
        
        }
        { //::osiris::IDbDriver::removeDatabase
        
            typedef bool ( ::osiris::IDbDriver::*removeDatabase_function_type )( ::std::string const &,::boost::shared_ptr<osiris::IDbOptions> ) ;
            
            IDbDriver_exposer.def( 
                "removeDatabase"
                , ( removeDatabase_function_type(&::osiris::IDbDriver::removeDatabase) )
                , ( ::boost::python::arg("name"), ::boost::python::arg("options") ) );
        
        }
        { //::osiris::IDbDriver::databaseExists
        
            typedef bool ( ::osiris::IDbDriver::*databaseExists_function_type )( ::std::string const &,::boost::shared_ptr<osiris::IDbOptions> ) const;
            
            IDbDriver_exposer.def( 
                "databaseExists"
                , ( databaseExists_function_type(&::osiris::IDbDriver::databaseExists) )
                , ( ::boost::python::arg("name"), ::boost::python::arg("options") ) );
        
        }
        { //property "name"[fget=::osiris::IDbDriver::getName]
        
            typedef ::std::string ( ::osiris::IDbDriver::*fget )(  ) const;
            
            IDbDriver_exposer.add_property( 
                "name"
                , fget( &::osiris::IDbDriver::getName )
                , "get property, built on top of \"std::string osiris::IDbDriver::getName() const [member function]\"" );
        
        }
        { //property "description"[fget=::osiris::IDbDriver::getDescription]
        
            typedef ::std::string ( ::osiris::IDbDriver::*fget )(  ) const;
            
            IDbDriver_exposer.add_property( 
                "description"
                , fget( &::osiris::IDbDriver::getDescription )
                , "get property, built on top of \"std::string osiris::IDbDriver::getDescription() const [member function]\"" );
        
        }
        ::boost::python::register_ptr_to_python< boost::shared_ptr< ::osiris::IDbDriver > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IDbDriver >, boost::shared_ptr< ::osiris::Object > >();
    }

}

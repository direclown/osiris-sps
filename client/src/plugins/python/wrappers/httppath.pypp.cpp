// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "httppath.h"
#include "httppath.pypp.hpp"

namespace bp = boost::python;

static boost::python::object getUrl_8f6ef94093382dfc23f1a5c32e4216ca( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String const & result = inst.getUrl();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::String const & >( result ) );
}

static boost::python::object empty_7ebf5bd1ff7abc771d58cf23dea33484( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    bool result = inst.empty();
    __pythreadSaver.restore();
    return boost::python::object( result );
}

static boost::python::object getTokens_b6574d0b387e40ebcb8adfa8e73e8d36( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::StringVector const & result = inst.getTokens();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::StringVector const & >( result ) );
}

static boost::python::object getDirectory_ddf2ce824cf378b29054a38da50936e3( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String const & result = inst.getDirectory();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::String const & >( result ) );
}

static boost::python::object isSafe_ce80b1565b980229883840929528becb( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    bool result = inst.isSafe();
    __pythreadSaver.restore();
    return boost::python::object( result );
}

static boost::python::object getTarget_e161b189611d77aa649fd18318f5af96( ::osiris::HttpPath const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String result = inst.getTarget();
    __pythreadSaver.restore();
    return boost::python::object( result );
}

static boost::python::object getRelativePath_59a8b9d7f056d054351bc261f187aeb9( ::osiris::HttpPath const & inst, ::osiris::uint32 index ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String result = inst.getRelativePath(index);
    __pythreadSaver.restore();
    return boost::python::object( result );
}

static boost::python::object getToken_794a5270396ce4f4096d2624d6ac110e( ::osiris::HttpPath const & inst, ::osiris::uint32 index ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String const & result = inst.getToken(index);
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::String const & >( result ) );
}

static void set_271c4630ab8bd7100a30dd0e574a680c( ::osiris::HttpPath & inst, ::osiris::String const & url ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    inst.set(url);
    __pythreadSaver.restore();
}

void register_HttpPath_class(){

    { //::osiris::HttpPath
        typedef ::boost::python::class_< ::osiris::HttpPath > HttpPath_exposer_t;
        HttpPath_exposer_t HttpPath_exposer = HttpPath_exposer_t( "HttpPath", ::boost::python::init< ::osiris::String const & >(( ::boost::python::arg("url") )) );
        ::boost::python::scope HttpPath_scope( HttpPath_exposer );
        ::boost::python::implicitly_convertible< ::osiris::String const &, ::osiris::HttpPath >();
        HttpPath_exposer.def( ::boost::python::init< ::osiris::HttpPath const & >(( ::boost::python::arg("second") )) );
        { //::osiris::HttpPath::getUrl
        
            typedef boost::python::object ( *getUrl_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "getUrl"
                , getUrl_function_type( &getUrl_8f6ef94093382dfc23f1a5c32e4216ca ) );
        
        }
        { //::osiris::HttpPath::empty
        
            typedef boost::python::object ( *empty_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "empty"
                , empty_function_type( &empty_7ebf5bd1ff7abc771d58cf23dea33484 ) );
        
        }
        { //::osiris::HttpPath::getTokens
        
            typedef boost::python::object ( *getTokens_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "getTokens"
                , getTokens_function_type( &getTokens_b6574d0b387e40ebcb8adfa8e73e8d36 ) );
        
        }
        { //::osiris::HttpPath::getDirectory
        
            typedef boost::python::object ( *getDirectory_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "getDirectory"
                , getDirectory_function_type( &getDirectory_ddf2ce824cf378b29054a38da50936e3 ) );
        
        }
        { //::osiris::HttpPath::isSafe
        
            typedef boost::python::object ( *isSafe_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "isSafe"
                , isSafe_function_type( &isSafe_ce80b1565b980229883840929528becb ) );
        
        }
        { //::osiris::HttpPath::getTarget
        
            typedef boost::python::object ( *getTarget_function_type )( ::osiris::HttpPath const & );
            
            HttpPath_exposer.def( 
                "getTarget"
                , getTarget_function_type( &getTarget_e161b189611d77aa649fd18318f5af96 ) );
        
        }
        { //::osiris::HttpPath::getRelativePath
        
            typedef boost::python::object ( *getRelativePath_function_type )( ::osiris::HttpPath const &,::osiris::uint32 );
            
            HttpPath_exposer.def( 
                "getRelativePath"
                , getRelativePath_function_type( &getRelativePath_59a8b9d7f056d054351bc261f187aeb9 )
                , ( ::boost::python::arg("inst"), ::boost::python::arg("index") ) );
        
        }
        { //::osiris::HttpPath::getToken
        
            typedef boost::python::object ( *getToken_function_type )( ::osiris::HttpPath const &,::osiris::uint32 );
            
            HttpPath_exposer.def( 
                "getToken"
                , getToken_function_type( &getToken_794a5270396ce4f4096d2624d6ac110e )
                , ( ::boost::python::arg("inst"), ::boost::python::arg("index") ) );
        
        }
        { //::osiris::HttpPath::operator=
        
            typedef ::osiris::HttpPath & ( ::osiris::HttpPath::*assign_function_type )( ::osiris::HttpPath const & ) ;
            
            HttpPath_exposer.def( 
                "assign"
                , assign_function_type( &::osiris::HttpPath::operator= )
                , ( ::boost::python::arg("second") )
                , bp::return_self< >() );
        
        }
        { //::osiris::HttpPath::set
        
            typedef void ( *set_function_type )( ::osiris::HttpPath &,::osiris::String const & );
            
            HttpPath_exposer.def( 
                "set"
                , set_function_type( &set_271c4630ab8bd7100a30dd0e574a680c )
                , ( ::boost::python::arg("inst"), ::boost::python::arg("url") ) );
        
        }
        { //property "url"[fget=::osiris::HttpPath::getUrl]
        
            typedef ::osiris::String const & ( ::osiris::HttpPath::*fget )(  ) const;
            
            HttpPath_exposer.add_property( 
                "url"
                , ::boost::python::make_function( 
                      fget( &::osiris::HttpPath::getUrl )
                    , bp::return_value_policy< bp::copy_const_reference >() ) 
                , "get property, built on top of \"osiris::String const & osiris::HttpPath::getUrl() const [member function]\"" );
        
        }
        { //property "tokens"[fget=::osiris::HttpPath::getTokens]
        
            typedef ::osiris::StringVector const & ( ::osiris::HttpPath::*fget )(  ) const;
            
            HttpPath_exposer.add_property( 
                "tokens"
                , ::boost::python::make_function( 
                      fget( &::osiris::HttpPath::getTokens )
                    , bp::return_value_policy< bp::copy_const_reference >() ) 
                , "get property, built on top of \"osiris::StringVector const & osiris::HttpPath::getTokens() const [member function]\"" );
        
        }
        { //property "directory"[fget=::osiris::HttpPath::getDirectory]
        
            typedef ::osiris::String const & ( ::osiris::HttpPath::*fget )(  ) const;
            
            HttpPath_exposer.add_property( 
                "directory"
                , ::boost::python::make_function( 
                      fget( &::osiris::HttpPath::getDirectory )
                    , bp::return_value_policy< bp::copy_const_reference >() ) 
                , "get property, built on top of \"osiris::String const & osiris::HttpPath::getDirectory() const [member function]\"" );
        
        }
        { //property "target"[fget=::osiris::HttpPath::getTarget]
        
            typedef ::osiris::String ( ::osiris::HttpPath::*fget )(  ) const;
            
            HttpPath_exposer.add_property( 
                "target"
                , fget( &::osiris::HttpPath::getTarget )
                , "get property, built on top of \"osiris::String osiris::HttpPath::getTarget() const [member function]\"" );
        
        }
    }

}

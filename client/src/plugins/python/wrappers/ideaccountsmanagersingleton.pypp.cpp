// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "ideaccountsmanager.h"
#include "ideaccountsmanagersingleton.pypp.hpp"

namespace bp = boost::python;

struct StaticSingleton_less__osiris_scope_IdeAccountsManager_comma__true__greater__wrapper : ::osiris::StaticSingleton< osiris::IdeAccountsManager, true >, ::osiris::PythonWrapper< ::osiris::StaticSingleton< osiris::IdeAccountsManager, true > > {

    StaticSingleton_less__osiris_scope_IdeAccountsManager_comma__true__greater__wrapper( )
    : ::osiris::StaticSingleton<osiris::IdeAccountsManager, true>( )
      , ::osiris::PythonWrapper< ::osiris::StaticSingleton< osiris::IdeAccountsManager, true > >(){
        // null constructor
    
    }

    static boost::python::object instance(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IdeAccountsManager * result = ::osiris::StaticSingleton<osiris::IdeAccountsManager, true>::instance();
        __pythreadSaver.restore();
        typedef bp::return_value_policy< bp::reference_existing_object > call_policies_t;
        return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::IdeAccountsManager * >( result ) );
    }

};

void register_IdeAccountsManagerSingleton_class(){

    ::boost::python::class_< StaticSingleton_less__osiris_scope_IdeAccountsManager_comma__true__greater__wrapper, ::boost::noncopyable >( "IdeAccountsManagerSingleton", ::boost::python::no_init )    
        .def( ::boost::python::init< >() )    
        .def( 
            "instance"
            , (boost::python::object (*)(  ))( &StaticSingleton_less__osiris_scope_IdeAccountsManager_comma__true__greater__wrapper::instance ) )    
        .staticmethod( "instance" );

}

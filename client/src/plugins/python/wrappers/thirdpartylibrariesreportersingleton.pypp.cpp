// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "thirdpartylibrariesreporter.h"
#include "thirdpartylibrariesreportersingleton.pypp.hpp"

namespace bp = boost::python;

struct StaticSingleton_less__osiris_scope_ThirdPartyLibrariesReporter_comma__true__greater__wrapper : ::osiris::StaticSingleton< osiris::ThirdPartyLibrariesReporter, true >, ::osiris::PythonWrapper< ::osiris::StaticSingleton< osiris::ThirdPartyLibrariesReporter, true > > {

    StaticSingleton_less__osiris_scope_ThirdPartyLibrariesReporter_comma__true__greater__wrapper( )
    : ::osiris::StaticSingleton<osiris::ThirdPartyLibrariesReporter, true>( )
      , ::osiris::PythonWrapper< ::osiris::StaticSingleton< osiris::ThirdPartyLibrariesReporter, true > >(){
        // null constructor
    
    }

    static boost::python::object instance(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::ThirdPartyLibrariesReporter * result = ::osiris::StaticSingleton<osiris::ThirdPartyLibrariesReporter, true>::instance();
        __pythreadSaver.restore();
        typedef bp::return_value_policy< bp::reference_existing_object > call_policies_t;
        return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::ThirdPartyLibrariesReporter * >( result ) );
    }

};

void register_ThirdPartyLibrariesReporterSingleton_class(){

    ::boost::python::class_< StaticSingleton_less__osiris_scope_ThirdPartyLibrariesReporter_comma__true__greater__wrapper, ::boost::noncopyable >( "ThirdPartyLibrariesReporterSingleton", ::boost::python::no_init )    
        .def( ::boost::python::init< >() )    
        .def( 
            "instance"
            , (boost::python::object (*)(  ))( &StaticSingleton_less__osiris_scope_ThirdPartyLibrariesReporter_comma__true__greater__wrapper::instance ) )    
        .staticmethod( "instance" );

}

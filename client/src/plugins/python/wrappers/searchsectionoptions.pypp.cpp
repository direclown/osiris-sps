// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "searchsectionoptions.h"
#include "idesearchparam.h"
#include "searchsectionoptions.pypp.hpp"

namespace bp = boost::python;

struct SearchSectionOptions_wrapper : ::osiris::SearchSectionOptions, ::osiris::PythonWrapper< ::osiris::SearchSectionOptions > {

    SearchSectionOptions_wrapper(::osiris::SearchSectionOptions const & arg )
    : ::osiris::SearchSectionOptions( arg )
      , ::osiris::PythonWrapper< ::osiris::SearchSectionOptions >(){
        // copy constructor
        
    }

    SearchSectionOptions_wrapper( )
    : ::osiris::SearchSectionOptions( )
      , ::osiris::PythonWrapper< ::osiris::SearchSectionOptions >(){
        // null constructor
    
    }

    virtual ::boost::shared_ptr< osiris::IdeSearchParam > getControl(  ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_getControl = this->get_override( "getControl" ) )
            return func_getControl(  );
        else{
            __pystate.leave();
            return this->::osiris::ISearchOptions::getControl(  );
        }
    }
    
    ::boost::shared_ptr< osiris::IdeSearchParam > default_getControl(  ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::ISearchOptions::getControl( );
    }

};

void register_SearchSectionOptions_class(){

    ::boost::python::class_< SearchSectionOptions_wrapper, ::boost::python::bases< ::osiris::ISearchOptions > >( "SearchSectionOptions", ::boost::python::init< >() )    
        .def( 
            "getControl"
            , (::boost::shared_ptr< osiris::IdeSearchParam > ( ::osiris::ISearchOptions::* )(  ) )(&::osiris::ISearchOptions::getControl)
            , (::boost::shared_ptr< osiris::IdeSearchParam > ( SearchSectionOptions_wrapper::* )(  ) )(&SearchSectionOptions_wrapper::default_getControl) );

}

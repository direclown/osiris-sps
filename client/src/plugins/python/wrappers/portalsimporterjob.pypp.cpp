// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "portalsimporterjob.h"
#include "portalsimporterjob.pypp.hpp"

namespace bp = boost::python;

struct PortalsImporterJob_wrapper : ::osiris::PortalsImporterJob, ::osiris::PythonWrapper< ::osiris::PortalsImporterJob > {

    PortalsImporterJob_wrapper(::osiris::uint32 id, ::boost::shared_ptr< osiris::Portal > portal, ::boost::shared_ptr< osiris::IStream > stream )
    : ::osiris::PortalsImporterJob( id, portal, stream )
      , ::osiris::PythonWrapper< ::osiris::PortalsImporterJob >(){
        // constructor
    
    }

    PortalsImporterJob_wrapper(::osiris::uint32 id, ::boost::shared_ptr< osiris::Portal > portal, ::osiris::String const & url )
    : ::osiris::PortalsImporterJob( id, portal, boost::ref(url) )
      , ::osiris::PythonWrapper< ::osiris::PortalsImporterJob >(){
        // constructor
    
    }

    virtual void stop(  ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_stop = this->get_override( "stop" ) )
            func_stop(  );
        else{
            __pystate.leave();
            this->::osiris::PortalsImporterJob::stop(  );
        }
    }
    
    void default_stop(  ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::PortalsImporterJob::stop( );
    }

    virtual ::osiris::IJob::JobStatus run(  ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_run = this->get_override( "run" ) )
            return func_run(  );
        else{
            __pystate.leave();
            return this->::osiris::PortalsImporterJob::run(  );
        }
    }
    
    ::osiris::IJob::JobStatus default_run(  ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::PortalsImporterJob::run( );
    }

    virtual ::boost::shared_ptr< osiris::IBackgroundJob::Details > getDetails(  ) const  {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_getDetails = this->get_override( "getDetails" ) )
            return func_getDetails(  );
        else{
            __pystate.leave();
            return this->::osiris::PortalsImporterJob::getDetails(  );
        }
    }
    
    ::boost::shared_ptr< osiris::IBackgroundJob::Details > default_getDetails(  ) const  {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::PortalsImporterJob::getDetails( );
    }

    virtual void onProgress(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_onProgress = this->get_override( "onProgress" ) )
            func_onProgress(  );
        else{
            __pystate.leave();
            this->::osiris::IBackgroundJob::onProgress(  );
        }
    }
    
    virtual void default_onProgress(  ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IBackgroundJob::onProgress( );
    }

    virtual ::osiris::IJob::JobStatus start(  ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_start = this->get_override( "start" ) )
            return func_start(  );
        else{
            __pystate.leave();
            return this->::osiris::IJob::start(  );
        }
    }
    
    ::osiris::IJob::JobStatus default_start(  ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        return ::osiris::IJob::start( );
    }

};

void register_PortalsImporterJob_class(){

    { //::osiris::PortalsImporterJob
        typedef ::boost::python::class_< PortalsImporterJob_wrapper, ::boost::python::bases< ::osiris::IPortalBackgroundJob >, ::boost::noncopyable > PortalsImporterJob_exposer_t;
        PortalsImporterJob_exposer_t PortalsImporterJob_exposer = PortalsImporterJob_exposer_t( "PortalsImporterJob", ::boost::python::init< ::osiris::uint32, ::boost::shared_ptr< osiris::Portal >, ::boost::shared_ptr< osiris::IStream > >(( ::boost::python::arg("id"), ::boost::python::arg("portal"), ::boost::python::arg("stream") )) );
        ::boost::python::scope PortalsImporterJob_scope( PortalsImporterJob_exposer );
        PortalsImporterJob_exposer.def( ::boost::python::init< ::osiris::uint32, ::boost::shared_ptr< osiris::Portal >, ::osiris::String const & >(( ::boost::python::arg("id"), ::boost::python::arg("portal"), ::boost::python::arg("url") )) );
        { //::osiris::PortalsImporterJob::stop
        
            typedef void ( ::osiris::PortalsImporterJob::*stop_function_type )(  ) ;
            typedef void ( PortalsImporterJob_wrapper::*default_stop_function_type )(  ) ;
            
            PortalsImporterJob_exposer.def( 
                "stop"
                , stop_function_type(&::osiris::PortalsImporterJob::stop)
                , default_stop_function_type(&PortalsImporterJob_wrapper::default_stop) );
        
        }
        { //::osiris::PortalsImporterJob::run
        
            typedef ::osiris::IJob::JobStatus ( ::osiris::PortalsImporterJob::*run_function_type )(  ) ;
            typedef ::osiris::IJob::JobStatus ( PortalsImporterJob_wrapper::*default_run_function_type )(  ) ;
            
            PortalsImporterJob_exposer.def( 
                "run"
                , run_function_type(&::osiris::PortalsImporterJob::run)
                , default_run_function_type(&PortalsImporterJob_wrapper::default_run) );
        
        }
        { //::osiris::PortalsImporterJob::getDetails
        
            typedef ::boost::shared_ptr< osiris::IBackgroundJob::Details > ( ::osiris::PortalsImporterJob::*getDetails_function_type )(  ) const;
            typedef ::boost::shared_ptr< osiris::IBackgroundJob::Details > ( PortalsImporterJob_wrapper::*default_getDetails_function_type )(  ) const;
            
            PortalsImporterJob_exposer.def( 
                "getDetails"
                , getDetails_function_type(&::osiris::PortalsImporterJob::getDetails)
                , default_getDetails_function_type(&PortalsImporterJob_wrapper::default_getDetails) );
        
        }
        { //::osiris::IBackgroundJob::onProgress
        
            typedef void ( PortalsImporterJob_wrapper::*onProgress_function_type )(  ) ;
            
            PortalsImporterJob_exposer.def( 
                "onProgress"
                , onProgress_function_type( &PortalsImporterJob_wrapper::default_onProgress ) );
        
        }
        { //::osiris::IJob::start
        
            typedef ::osiris::IJob::JobStatus ( ::osiris::IJob::*start_function_type )(  ) ;
            typedef ::osiris::IJob::JobStatus ( PortalsImporterJob_wrapper::*default_start_function_type )(  ) ;
            
            PortalsImporterJob_exposer.def( 
                "start"
                , start_function_type(&::osiris::IJob::start)
                , default_start_function_type(&PortalsImporterJob_wrapper::default_start) );
        
        }
        { //property "details"[fget=::osiris::PortalsImporterJob::getDetails]
        
            typedef ::boost::shared_ptr<osiris::IBackgroundJob::Details> ( ::osiris::PortalsImporterJob::*fget )(  ) const;
            
            PortalsImporterJob_exposer.add_property( 
                "details"
                , fget( &::osiris::PortalsImporterJob::getDetails )
                , "get property, built on top of \"boost::shared_ptr<osiris::IBackgroundJob::Details> osiris::PortalsImporterJob::getDetails() const [member function]\"" );
        
        }
    }

}

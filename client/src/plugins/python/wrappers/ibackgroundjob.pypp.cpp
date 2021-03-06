// This file has been generated by Py++.

#include "stdafx.h"
#include "pypluspluscommon.h"
#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "ibackgroundjob.h"
#include "mainaddonsjob.h"
#include "iportalbackgroundjob.h"
#include "portalsimporterjob.h"
#include "portalsstabilityjob.h"
#include "ibackgroundjob.pypp.hpp"

namespace bp = boost::python;

struct IBackgroundJob_wrapper : ::osiris::IBackgroundJob, ::osiris::PythonWrapper< ::osiris::IBackgroundJob > {

    IBackgroundJob_wrapper(bool visible, ::osiris::uint32 id, ::osiris::TaskPriority priority=::osiris::taskPriorityNormal )
    : ::osiris::IBackgroundJob( visible, id, priority )
      , ::osiris::PythonWrapper< ::osiris::IBackgroundJob >(){
        // constructor
    
    }

    static boost::python::object getVisible( ::osiris::IBackgroundJob const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        bool result = inst.getVisible();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    static boost::python::object getCreationTime( ::osiris::IBackgroundJob const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::boost::posix_time::ptime result = inst.getCreationTime();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    static boost::python::object getLastProgressTime( ::osiris::IBackgroundJob const & inst ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::boost::posix_time::ptime result = inst.getLastProgressTime();
        __pythreadSaver.restore();
        return boost::python::object( result );
    }

    virtual ::boost::shared_ptr< osiris::IBackgroundJob::Details > getDetails(  ) const {
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_getDetails = this->get_override( "getDetails" );
        return func_getDetails(  );
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

    static void setVisible( ::osiris::IBackgroundJob & inst, bool visible ){
        ::osiris::PythonThreadSaver __pythreadSaver;
        inst.setVisible(visible);
        __pythreadSaver.restore();
    }

    virtual ::osiris::IJob::JobStatus run(  ){
        ::osiris::PythonState __pystate(getPythonThreadState());
        ::osiris::PythonOverride func_run = this->get_override( "run" );
        return func_run(  );
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

    virtual void stop(  ) {
        ::osiris::PythonState __pystate(getPythonThreadState());
        if( ::osiris::PythonOverride func_stop = this->get_override( "stop" ) )
            func_stop(  );
        else{
            __pystate.leave();
            this->::osiris::IJob::stop(  );
        }
    }
    
    void default_stop(  ) {
        ::osiris::PythonThreadSaver __pythreadSaver;
        ::osiris::IJob::stop( );
    }

};

static boost::python::object getName_f667742db51643e84c8296e5ab3390d2( ::osiris::IBackgroundJob::Details const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::std::wstring const & result = inst.getName();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::std::wstring const & >( result ) );
}

static boost::python::object getStatus_bec750cbfbf676c89d9b42047eff5ca9( ::osiris::IBackgroundJob::Details const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::std::wstring const & result = inst.getStatus();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::std::wstring const & >( result ) );
}

static boost::python::object getPercentage_5213adf648f6405637884bdabaf3479c( ::osiris::IBackgroundJob::Details const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::boost::optional<double> const & result = inst.getPercentage();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::boost::optional<double> const & >( result ) );
}

static boost::python::object getResult_4b621e8d6ef7e53035fce9847ee81a92( ::osiris::IBackgroundJob::Details const & inst ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    ::osiris::String const & result = inst.getResult();
    __pythreadSaver.restore();
    typedef bp::return_value_policy< bp::copy_const_reference > call_policies_t;
    return boost::python::object( pyplusplus::call_policies::make_object< call_policies_t, ::osiris::String const & >( result ) );
}

static void setPercentage_6c9626ba4e78d3294f0002025b61ff4c( ::osiris::IBackgroundJob::Details & inst, ::boost::optional< double > const & percentage ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    inst.setPercentage(percentage);
    __pythreadSaver.restore();
}

static void setResult_e6afc3c054c8437cc7d2509a5a2ad915( ::osiris::IBackgroundJob::Details & inst, ::osiris::String const & result ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    inst.setResult(result);
    __pythreadSaver.restore();
}

static void setStatus_62072e2c623e90359b58ae2d01908f50( ::osiris::IBackgroundJob::Details & inst, ::std::wstring status ){
    ::osiris::PythonThreadSaver __pythreadSaver;
    inst.setStatus(status);
    __pythreadSaver.restore();
}

void register_IBackgroundJob_class(){

    { //::osiris::IBackgroundJob
        typedef ::boost::python::class_< IBackgroundJob_wrapper, ::boost::python::bases< ::osiris::IJob >, ::boost::noncopyable > IBackgroundJob_exposer_t;
        IBackgroundJob_exposer_t IBackgroundJob_exposer = IBackgroundJob_exposer_t( "IBackgroundJob", ::boost::python::init< bool, ::osiris::uint32, ::boost::python::optional< ::osiris::TaskPriority > >(( ::boost::python::arg("visible"), ::boost::python::arg("id"), ::boost::python::arg("priority")=::osiris::taskPriorityNormal )) );
        ::boost::python::scope IBackgroundJob_scope( IBackgroundJob_exposer );
        { //::osiris::IBackgroundJob::Details
            typedef ::boost::python::class_< ::osiris::IBackgroundJob::Details, ::boost::noncopyable > Details_exposer_t;
            Details_exposer_t Details_exposer = Details_exposer_t( "Details", ::boost::python::init< ::std::wstring const & >(( ::boost::python::arg("name") )) );
            ::boost::python::scope Details_scope( Details_exposer );
            ::boost::python::implicitly_convertible< ::std::wstring const &, ::osiris::IBackgroundJob::Details >();
            { //::osiris::IBackgroundJob::Details::getName
            
                typedef boost::python::object ( *getName_function_type )( ::osiris::IBackgroundJob::Details const & );
                
                Details_exposer.def( 
                    "getName"
                    , getName_function_type( &getName_f667742db51643e84c8296e5ab3390d2 ) );
            
            }
            { //::osiris::IBackgroundJob::Details::getStatus
            
                typedef boost::python::object ( *getStatus_function_type )( ::osiris::IBackgroundJob::Details const & );
                
                Details_exposer.def( 
                    "getStatus"
                    , getStatus_function_type( &getStatus_bec750cbfbf676c89d9b42047eff5ca9 ) );
            
            }
            { //::osiris::IBackgroundJob::Details::getPercentage
            
                typedef boost::python::object ( *getPercentage_function_type )( ::osiris::IBackgroundJob::Details const & );
                
                Details_exposer.def( 
                    "getPercentage"
                    , getPercentage_function_type( &getPercentage_5213adf648f6405637884bdabaf3479c ) );
            
            }
            { //::osiris::IBackgroundJob::Details::getResult
            
                typedef boost::python::object ( *getResult_function_type )( ::osiris::IBackgroundJob::Details const & );
                
                Details_exposer.def( 
                    "getResult"
                    , getResult_function_type( &getResult_4b621e8d6ef7e53035fce9847ee81a92 ) );
            
            }
            { //::osiris::IBackgroundJob::Details::setPercentage
            
                typedef void ( *setPercentage_function_type )( ::osiris::IBackgroundJob::Details &,::boost::optional<double> const & );
                
                Details_exposer.def( 
                    "setPercentage"
                    , setPercentage_function_type( &setPercentage_6c9626ba4e78d3294f0002025b61ff4c )
                    , ( ::boost::python::arg("inst"), ::boost::python::arg("percentage") ) );
            
            }
            { //::osiris::IBackgroundJob::Details::setResult
            
                typedef void ( *setResult_function_type )( ::osiris::IBackgroundJob::Details &,::osiris::String const & );
                
                Details_exposer.def( 
                    "setResult"
                    , setResult_function_type( &setResult_e6afc3c054c8437cc7d2509a5a2ad915 )
                    , ( ::boost::python::arg("inst"), ::boost::python::arg("result") ) );
            
            }
            { //::osiris::IBackgroundJob::Details::setStatus
            
                typedef void ( *setStatus_function_type )( ::osiris::IBackgroundJob::Details &,::std::wstring );
                
                Details_exposer.def( 
                    "setStatus"
                    , setStatus_function_type( &setStatus_62072e2c623e90359b58ae2d01908f50 )
                    , ( ::boost::python::arg("inst"), ::boost::python::arg("status") ) );
            
            }
            { //property "percentage"[fget=::osiris::IBackgroundJob::Details::getPercentage, fset=::osiris::IBackgroundJob::Details::setPercentage]
            
                typedef ::boost::optional<double> const & ( ::osiris::IBackgroundJob::Details::*fget )(  ) const;
                typedef void ( ::osiris::IBackgroundJob::Details::*fset )( ::boost::optional<double> const & ) ;
                
                Details_exposer.add_property( 
                    "percentage"
                    , ::boost::python::make_function( 
                          fget( &::osiris::IBackgroundJob::Details::getPercentage )
                        , bp::return_value_policy< bp::copy_const_reference >() ) 
                    , fset( &::osiris::IBackgroundJob::Details::setPercentage )
                    , "get\\set property, built on top of \"boost::optional<double> const & osiris::IBackgroundJob::Details::getPercentage() const [member function]\" and \"void osiris::IBackgroundJob::Details::setPercentage(boost::optional<double> const & percentage) [member function]\"" );
            
            }
            { //property "result"[fget=::osiris::IBackgroundJob::Details::getResult, fset=::osiris::IBackgroundJob::Details::setResult]
            
                typedef ::osiris::String const & ( ::osiris::IBackgroundJob::Details::*fget )(  ) const;
                typedef void ( ::osiris::IBackgroundJob::Details::*fset )( ::osiris::String const & ) ;
                
                Details_exposer.add_property( 
                    "result"
                    , ::boost::python::make_function( 
                          fget( &::osiris::IBackgroundJob::Details::getResult )
                        , bp::return_value_policy< bp::copy_const_reference >() ) 
                    , fset( &::osiris::IBackgroundJob::Details::setResult )
                    , "get\\set property, built on top of \"osiris::String const & osiris::IBackgroundJob::Details::getResult() const [member function]\" and \"void osiris::IBackgroundJob::Details::setResult(osiris::String const & result) [member function]\"" );
            
            }
            { //property "name"[fget=::osiris::IBackgroundJob::Details::getName]
            
                typedef ::std::wstring const & ( ::osiris::IBackgroundJob::Details::*fget )(  ) const;
                
                Details_exposer.add_property( 
                    "name"
                    , ::boost::python::make_function( 
                          fget( &::osiris::IBackgroundJob::Details::getName )
                        , bp::return_value_policy< bp::copy_const_reference >() ) 
                    , "get property, built on top of \"std::wstring const & osiris::IBackgroundJob::Details::getName() const [member function]\"" );
            
            }
            { //property "status"[fget=::osiris::IBackgroundJob::Details::getStatus]
            
                typedef ::std::wstring const & ( ::osiris::IBackgroundJob::Details::*fget )(  ) const;
                
                Details_exposer.add_property( 
                    "status"
                    , ::boost::python::make_function( 
                          fget( &::osiris::IBackgroundJob::Details::getStatus )
                        , bp::return_value_policy< bp::copy_const_reference >() ) 
                    , "get property, built on top of \"std::wstring const & osiris::IBackgroundJob::Details::getStatus() const [member function]\"" );
            
            }
            ::boost::python::register_ptr_to_python< boost::shared_ptr< ::osiris::IBackgroundJob::Details > >();
            ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob::Details >, boost::shared_ptr< ::osiris::Object > >();
            ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob::Details >, boost::shared_ptr< ::osiris::AllocWrapper< osiris::Object, osiris::SysAllocator< osiris::Object > > > >();
        }
        { //::osiris::IBackgroundJob::getVisible
        
            typedef boost::python::object ( *getVisible_function_type )( ::osiris::IBackgroundJob const & );
            
            IBackgroundJob_exposer.def( 
                "getVisible"
                , getVisible_function_type( &IBackgroundJob_wrapper::getVisible ) );
        
        }
        { //::osiris::IBackgroundJob::getCreationTime
        
            typedef boost::python::object ( *getCreationTime_function_type )( ::osiris::IBackgroundJob const & );
            
            IBackgroundJob_exposer.def( 
                "getCreationTime"
                , getCreationTime_function_type( &IBackgroundJob_wrapper::getCreationTime ) );
        
        }
        { //::osiris::IBackgroundJob::getLastProgressTime
        
            typedef boost::python::object ( *getLastProgressTime_function_type )( ::osiris::IBackgroundJob const & );
            
            IBackgroundJob_exposer.def( 
                "getLastProgressTime"
                , getLastProgressTime_function_type( &IBackgroundJob_wrapper::getLastProgressTime ) );
        
        }
        { //::osiris::IBackgroundJob::getDetails
        
            typedef ::boost::shared_ptr<osiris::IBackgroundJob::Details> ( ::osiris::IBackgroundJob::*getDetails_function_type )(  ) const;
            
            IBackgroundJob_exposer.def( 
                "getDetails"
                , ( getDetails_function_type(&::osiris::IBackgroundJob::getDetails) ) );
        
        }
        { //::osiris::IBackgroundJob::onProgress
        
            typedef void ( IBackgroundJob_wrapper::*onProgress_function_type )(  ) ;
            
            IBackgroundJob_exposer.def( 
                "onProgress"
                , onProgress_function_type( &IBackgroundJob_wrapper::default_onProgress ) );
        
        }
        { //::osiris::IBackgroundJob::setVisible
        
            typedef void ( *setVisible_function_type )( ::osiris::IBackgroundJob &,bool );
            
            IBackgroundJob_exposer.def( 
                "setVisible"
                , setVisible_function_type( &IBackgroundJob_wrapper::setVisible )
                , ( ::boost::python::arg("inst"), ::boost::python::arg("visible") ) );
        
        }
        { //::osiris::IJob::run
        
            typedef ::osiris::IJob::JobStatus ( IBackgroundJob_wrapper::*run_function_type )(  ) ;
            
            IBackgroundJob_exposer.def( 
                "run"
                , run_function_type( &IBackgroundJob_wrapper::run ) );
        
        }
        { //::osiris::IJob::start
        
            typedef ::osiris::IJob::JobStatus ( ::osiris::IJob::*start_function_type )(  ) ;
            typedef ::osiris::IJob::JobStatus ( IBackgroundJob_wrapper::*default_start_function_type )(  ) ;
            
            IBackgroundJob_exposer.def( 
                "start"
                , start_function_type(&::osiris::IJob::start)
                , default_start_function_type(&IBackgroundJob_wrapper::default_start) );
        
        }
        { //::osiris::IJob::stop
        
            typedef void ( ::osiris::IJob::*stop_function_type )(  ) ;
            typedef void ( IBackgroundJob_wrapper::*default_stop_function_type )(  ) ;
            
            IBackgroundJob_exposer.def( 
                "stop"
                , stop_function_type(&::osiris::IJob::stop)
                , default_stop_function_type(&IBackgroundJob_wrapper::default_stop) );
        
        }
        { //property "visible"[fget=::osiris::IBackgroundJob::getVisible, fset=::osiris::IBackgroundJob::setVisible]
        
            typedef bool ( ::osiris::IBackgroundJob::*fget )(  ) const;
            typedef void ( ::osiris::IBackgroundJob::*fset )( bool ) ;
            
            IBackgroundJob_exposer.add_property( 
                "visible"
                , fget( &::osiris::IBackgroundJob::getVisible )
                , fset( &::osiris::IBackgroundJob::setVisible )
                , "get\\set property, built on top of \"bool osiris::IBackgroundJob::getVisible() const [member function]\" and \"void osiris::IBackgroundJob::setVisible(bool visible) [member function]\"" );
        
        }
        { //property "creationTime"[fget=::osiris::IBackgroundJob::getCreationTime]
        
            typedef ::boost::posix_time::ptime ( ::osiris::IBackgroundJob::*fget )(  ) const;
            
            IBackgroundJob_exposer.add_property( 
                "creationTime"
                , fget( &::osiris::IBackgroundJob::getCreationTime )
                , "get property, built on top of \"boost::posix_time::ptime osiris::IBackgroundJob::getCreationTime() const [member function]\"" );
        
        }
        { //property "lastProgressTime"[fget=::osiris::IBackgroundJob::getLastProgressTime]
        
            typedef ::boost::posix_time::ptime ( ::osiris::IBackgroundJob::*fget )(  ) const;
            
            IBackgroundJob_exposer.add_property( 
                "lastProgressTime"
                , fget( &::osiris::IBackgroundJob::getLastProgressTime )
                , "get property, built on top of \"boost::posix_time::ptime osiris::IBackgroundJob::getLastProgressTime() const [member function]\"" );
        
        }
        { //property "details"[fget=::osiris::IBackgroundJob::getDetails]
        
            typedef ::boost::shared_ptr<osiris::IBackgroundJob::Details> ( ::osiris::IBackgroundJob::*fget )(  ) const;
            
            IBackgroundJob_exposer.add_property( 
                "details"
                , fget( &::osiris::IBackgroundJob::getDetails )
                , "get property, built on top of \"boost::shared_ptr<osiris::IBackgroundJob::Details> osiris::IBackgroundJob::getDetails() const [member function]\"" );
        
        }
        ::boost::python::register_ptr_to_python< boost::shared_ptr< ::osiris::IBackgroundJob > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob >, boost::shared_ptr< ::osiris::IJob > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob >, boost::shared_ptr< ::osiris::enable_this_ptr< osiris::IJob > > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob >, boost::shared_ptr< ::boost::noncopyable_::noncopyable > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IBackgroundJob >, boost::shared_ptr< ::osiris::Object > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::MainAddonsJob >, boost::shared_ptr< ::osiris::IBackgroundJob > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::IPortalBackgroundJob >, boost::shared_ptr< ::osiris::IBackgroundJob > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::PortalsImporterJob >, boost::shared_ptr< ::osiris::IBackgroundJob > >();
        ::boost::python::implicitly_convertible< boost::shared_ptr< ::osiris::PortalsStabilityJob >, boost::shared_ptr< ::osiris::IBackgroundJob > >();
    }

}

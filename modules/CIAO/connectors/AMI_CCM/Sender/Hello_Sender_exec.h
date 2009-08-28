// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.1 ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:1217

#ifndef CIAO_HELLO_SENDER_EXEC_H_
#define CIAO_HELLO_SENDER_EXEC_H_


#include "Hello_SenderEC.h"
#include "Hello_Sender_exec_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/LocalObject.h"
#include "ace/Task.h"


namespace CIAO_Hello_AMI_Sender_Impl
{
  // Worker thread for asynchronous invocations
  class asynch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_foo_generator (::CCM_AMI::AMI_MyFoo_ptr my_foo_ami);

    virtual int svc (void);

  private:
    ::CCM_AMI::AMI_MyFoo_var my_foo_ami_;
  };

  // Worker thread for synchronous invocations
  class synch_foo_generator : public virtual ACE_Task_Base
  {
  public:
    synch_foo_generator (::CCM_AMI::MyFoo_ptr my_foo_ami);

    virtual int svc (void);

  private:
    ::CCM_AMI::MyFoo_var my_foo_ami_;
  };

  // Worker thread for synchronous invocations
  class asynch_interface_generator : public virtual ACE_Task_Base
  {
  public:
    asynch_interface_generator (::CCM_AMI::AMI_MyInterface_ptr my_interface_ami);

    virtual int svc (void);

  private:
    ::CCM_AMI::AMI_MyInterface_ptr my_interface_ami_;
  };

  class  MyInterface_callback_exec_i
    : public virtual ::CCM_AMI::CCM_AMI_MyInterface_callback,
      public virtual ::CORBA::LocalObject
  {
  public:
    MyInterface_callback_exec_i (void);
    virtual ~MyInterface_callback_exec_i (void);
    
    // Operations and attributes from ::CCM_AMI::MyFoo_callback
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    do_something_with_something_callback_handler (
      ::CORBA::Float result);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    do_something_with_something_callback_excep (
      const ::CCM_AMI::InternalException & exception_holder);
  };

  class  MyFoo_callback_exec_i
    : public virtual ::CCM_AMI::CCM_AMI_MyFoo_callback,
      public virtual ::POA_CCM_AMI::AMI_MyFooHandler,
      public virtual ::CORBA::LocalObject
  {
  public:
    MyFoo_callback_exec_i (void);
    virtual ~MyFoo_callback_exec_i (void);
    
    // Operations and attributes from ::CCM_AMI::MyFoo_callback
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    foo_callback_handler (
      ::CORBA::Long result,
      const char * answer);
    
    virtual void
    hello_callback_handler (
      ::CORBA::Long answer);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    foo_callback_excep (
      const ::CCM_AMI::InternalException & exception_holder);
    
    virtual void
    hello_callback_excep (
      const ::CCM_AMI::InternalException & exception_holder);
  
  };
  
  class  Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // Port operations.
    
    virtual ::CCM_AMI::CCM_AMI_MyFoo_callback_ptr
    get_the_my_foo_callback (void);

    virtual ::CCM_AMI::CCM_AMI_MyInterface_callback_ptr
    get_the_my_interface_callback (void);

    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::Hello_AMI::CCM_Sender_Context_var context_;
    MyFoo_callback_exec_i* global_foo_callback_;
    MyInterface_callback_exec_i* global_interface_callback_;
  };
  
  extern "C" HELLO_SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Hello_AMI_Sender_Impl (void);
}

namespace CIAO_Hello_AMI_Sender_Impl
{
  class  SenderHome_exec_i
    : public virtual SenderHome_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    SenderHome_exec_i (void);
    
    virtual ~SenderHome_exec_i (void);
    
    // All operations and attributes.
    
    // Factory operations.
    
    // Finder operations.
    
    // Implicit operations.
    
    virtual ::Components::EnterpriseComponent_ptr
    create (void);
  };
  
  extern "C" HELLO_SENDER_EXEC_Export ::Components::HomeExecutorBase_ptr
  create_Hello_AMI_SenderHome_Impl (void);
}

#endif /* ifndef */


// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
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
// be/be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_IOP_IORC_H_
#define _TAO_IDL_ORIG_IOP_IORC_H_

#include /**/ "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/TAO_Export.h"
#include "tao/OctetSeqC.h"
#include "tao/VarOut_T.h"
#include "tao/CDR.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  IOP
{

  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::ULong ProfileId;
  typedef CORBA::ULong_out ProfileId_out;

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ProfileId;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_INTERNET_IOP = 0U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_MULTIPLE_COMPONENTS = 1U;

  // TAO_IDL - Generated from
  // be/be_type.cpp:249

  struct TaggedProfile;

  typedef
    TAO_Var_Var_T<
        TaggedProfile
      >
    TaggedProfile_var;

  typedef
    TAO_Out_T<
        TaggedProfile,
        TaggedProfile_var
      >
    TaggedProfile_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export TaggedProfile
  {
    typedef TaggedProfile_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ProfileId tag;
    CORBA::OctetSeq profile_data;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TaggedProfile;

  // TAO_IDL - Generated from
  // be/be_type.cpp:249

#if defined (HPUX) && defined (IOR)
   /* HP-UX 11.11 defines IOR in /usr/include/pa/inline.h
      and we don't want that definition.  See IOP_IORC.h. */
# undef IOR
#endif /* HPUX && IOR */
  struct IOR;

  typedef
    TAO_Var_Var_T<
        IOR
      >
    IOR_var;

  typedef
    TAO_Out_T<
        IOR,
        IOR_var
      >
    IOR_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export IOR
  {
    typedef IOR_var _var_type;

    static void _tao_any_destructor (void *);
    TAO_String_Manager type_id;


    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_IOR__TAO_SEQ_TAGGEDPROFILE_PROFILES_CH_)
#define _IOP_IOR__TAO_SEQ_TAGGEDPROFILE_PROFILES_CH_

    class TAO_Export _tao_seq_TaggedProfile_profiles
      : public
          TAO_Unbounded_Sequence<
              ACE_NESTED_CLASS (IOP, TaggedProfile)
            >
    {
    public:
      _tao_seq_TaggedProfile_profiles (void);
      _tao_seq_TaggedProfile_profiles (CORBA::ULong max);
      _tao_seq_TaggedProfile_profiles (
          CORBA::ULong max,
          CORBA::ULong length,
          ACE_NESTED_CLASS (IOP, TaggedProfile)* buffer,
          CORBA::Boolean release = 0
        );
      _tao_seq_TaggedProfile_profiles (const _tao_seq_TaggedProfile_profiles &);
      ~_tao_seq_TaggedProfile_profiles (void);

      static void _tao_any_destructor (void *);


    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_field/field_ch.cpp:453

    typedef _tao_seq_TaggedProfile_profiles _profiles_seq;
    _tao_seq_TaggedProfile_profiles profiles;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_IOR;

  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::ULong ComponentId;
  typedef CORBA::ULong_out ComponentId_out;

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ComponentId;

  // TAO_IDL - Generated from
  // be/be_type.cpp:249

  struct TaggedComponent;

  typedef
    TAO_Var_Var_T<
        TaggedComponent
      >
    TaggedComponent_var;

  typedef
    TAO_Out_T<
        TaggedComponent,
        TaggedComponent_var
      >
    TaggedComponent_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export TaggedComponent
  {
    typedef TaggedComponent_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ComponentId tag;
    CORBA::OctetSeq component_data;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TaggedComponent;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_MULTIPLECOMPONENTPROFILE_CH_)
#define _IOP_MULTIPLECOMPONENTPROFILE_CH_

  class MultipleComponentProfile;

  typedef
    TAO_VarSeq_Var_T<
        MultipleComponentProfile,
        TaggedComponent
      >
    MultipleComponentProfile_var;

  typedef
    TAO_Seq_Out_T<
        MultipleComponentProfile,
        MultipleComponentProfile_var,
        TaggedComponent
      >
    MultipleComponentProfile_out;

  class TAO_Export MultipleComponentProfile
    : public
        TAO_Unbounded_Sequence<
            TaggedComponent
          >
  {
  public:
    MultipleComponentProfile (void);
    MultipleComponentProfile (CORBA::ULong max);
    MultipleComponentProfile (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    MultipleComponentProfile (const MultipleComponentProfile &);
    ~MultipleComponentProfile (void);

    static void _tao_any_destructor (void *);

    typedef MultipleComponentProfile_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_MultipleComponentProfile;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_TAGGEDCOMPONENTLIST_CH_)
#define _IOP_TAGGEDCOMPONENTLIST_CH_

  class TaggedComponentList;

  typedef
    TAO_VarSeq_Var_T<
        TaggedComponentList,
        TaggedComponent
      >
    TaggedComponentList_var;

  typedef
    TAO_Seq_Out_T<
        TaggedComponentList,
        TaggedComponentList_var,
        TaggedComponent
      >
    TaggedComponentList_out;

  class TAO_Export TaggedComponentList
    : public
        TAO_Unbounded_Sequence<
            TaggedComponent
          >
  {
  public:
    TaggedComponentList (void);
    TaggedComponentList (CORBA::ULong max);
    TaggedComponentList (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    TaggedComponentList (const TaggedComponentList &);
    ~TaggedComponentList (void);

    static void _tao_any_destructor (void *);

    typedef TaggedComponentList_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TaggedComponentList;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_TAGGEDCOMPONENTSEQ_CH_)
#define _IOP_TAGGEDCOMPONENTSEQ_CH_

  class TaggedComponentSeq;

  typedef
    TAO_VarSeq_Var_T<
        TaggedComponentSeq,
        TaggedComponent
      >
    TaggedComponentSeq_var;

  typedef
    TAO_Seq_Out_T<
        TaggedComponentSeq,
        TaggedComponentSeq_var,
        TaggedComponent
      >
    TaggedComponentSeq_out;

  class TAO_Export TaggedComponentSeq
    : public
        TAO_Unbounded_Sequence<
            TaggedComponent
          >
  {
  public:
    TaggedComponentSeq (void);
    TaggedComponentSeq (CORBA::ULong max);
    TaggedComponentSeq (
        CORBA::ULong max,
        CORBA::ULong length,
        TaggedComponent* buffer,
        CORBA::Boolean release = 0
      );
    TaggedComponentSeq (const TaggedComponentSeq &);
    ~TaggedComponentSeq (void);

    static void _tao_any_destructor (void *);

    typedef TaggedComponentSeq_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_TaggedComponentSeq;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ORB_TYPE = 0U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_CODE_SETS = 1U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_POLICIES = 2U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ALTERNATE_IIOP_ADDRESS = 3U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_COMPLETE_OBJECT_KEY = 5U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_ENDPOINT_ID_POSITION = 6U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_LOCATION_POLICY = 12U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_STRING_BINDING = 100U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_BINDING_NAME = 101U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_DCE_NO_PIPES = 102U;

  // TAO_IDL - Generated from
  // be/be_visitor_typedef/typedef_ch.cpp:333

  typedef CORBA::ULong ServiceId;
  typedef CORBA::ULong_out ServiceId_out;

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceId;

  // TAO_IDL - Generated from
  // be/be_type.cpp:249

  struct ServiceContext;

  typedef
    TAO_Var_Var_T<
        ServiceContext
      >
    ServiceContext_var;

  typedef
    TAO_Out_T<
        ServiceContext,
        ServiceContext_var
      >
    ServiceContext_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:52

  struct TAO_Export ServiceContext
  {
    typedef ServiceContext_var _var_type;

    static void _tao_any_destructor (void *);
    IOP::ServiceId context_id;


    // TAO_IDL - Generated from
    // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_SERVICECONTEXT__TAO_SEQ_OCTET_CONTEXT_DATA_CH_)
#define _IOP_SERVICECONTEXT__TAO_SEQ_OCTET_CONTEXT_DATA_CH_

    class TAO_Export _tao_seq_Octet_context_data
      : public
          TAO_Unbounded_Sequence<
              CORBA::Octet
            >
    {
    public:
      _tao_seq_Octet_context_data (void);
      _tao_seq_Octet_context_data (CORBA::ULong max);
      _tao_seq_Octet_context_data (
          CORBA::ULong max,
          CORBA::ULong length,
          CORBA::Octet* buffer,
          CORBA::Boolean release = 0
        );
      _tao_seq_Octet_context_data (const _tao_seq_Octet_context_data &);
      ~_tao_seq_Octet_context_data (void);

      static void _tao_any_destructor (void *);



#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      _tao_seq_Octet_context_data (
          CORBA::ULong length,
          const ACE_Message_Block* mb
        )
        : TAO_Unbounded_Sequence<CORBA::Octet> (length, mb) {}
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
    };

#endif /* end #if !defined */

    // TAO_IDL - Generated from
    // be/be_visitor_field/field_ch.cpp:453

    typedef _tao_seq_Octet_context_data _context_data_seq;
    _tao_seq_Octet_context_data context_data;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceContext;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:89

#if !defined (_IOP_SERVICECONTEXTLIST_CH_)
#define _IOP_SERVICECONTEXTLIST_CH_

  class ServiceContextList;

  typedef
    TAO_VarSeq_Var_T<
        ServiceContextList,
        ServiceContext
      >
    ServiceContextList_var;

  typedef
    TAO_Seq_Out_T<
        ServiceContextList,
        ServiceContextList_var,
        ServiceContext
      >
    ServiceContextList_out;

  class TAO_Export ServiceContextList
    : public
        TAO_Unbounded_Sequence<
            ServiceContext
          >
  {
  public:
    ServiceContextList (void);
    ServiceContextList (CORBA::ULong max);
    ServiceContextList (
        CORBA::ULong max,
        CORBA::ULong length,
        ServiceContext* buffer,
        CORBA::Boolean release = 0
      );
    ServiceContextList (const ServiceContextList &);
    ~ServiceContextList (void);

    static void _tao_any_destructor (void *);

    typedef ServiceContextList_var _var_type;
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:44

  TAO_NAMESPACE_STORAGE_CLASS ::CORBA::TypeCode_ptr _tc_ServiceContextList;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId TransactionService = 0U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId CodeSets = 1U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId ChainBypassCheck = 2U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId ChainBypassInfo = 3U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId LogicalThreadId = 4U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId BI_DIR_IIOP = 5U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId SendingContextRunTime = 6U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId INVOCATION_POLICIES = 7U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId UnknownExceptionInfo = 9U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId RTCorbaPriority = 10U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId RTCorbaPriorityRange = 11U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_GROUP = 27U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_PRIMARY = 28U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_FT_HEARTBEAT_ENABLED = 29U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId FT_GROUP_VERSION = 12U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ServiceId FT_REQUEST = 13U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ProfileId TAG_UIPMC = 1413566220U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_GROUP = 1413566211U;

  // TAO_IDL - Generated from
  // be/be_visitor_constant/constant_ch.cpp:52

  const IOP::ComponentId TAG_GROUP_IIOP = 1413566212U;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module IOP

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::TaggedProfile &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::TaggedProfile*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedProfile *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedProfile *&);

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::IOR &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::IOR*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::IOR *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::IOR *&);

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponent &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::TaggedComponent*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponent *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponent *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::MultipleComponentProfile &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::MultipleComponentProfile*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::MultipleComponentProfile *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::MultipleComponentProfile *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponentList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::TaggedComponentList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponentList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponentList *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::TaggedComponentSeq &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::TaggedComponentSeq*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::TaggedComponentSeq *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::TaggedComponentSeq *&);

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::ServiceContext &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::ServiceContext*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::ServiceContext *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::ServiceContext *&);

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:52

TAO_Export void operator<<= (CORBA::Any &, const IOP::ServiceContextList &); // copying version
TAO_Export void operator<<= (CORBA::Any &, IOP::ServiceContextList*); // noncopying version
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, IOP::ServiceContextList *&); // deprecated
TAO_Export CORBA::Boolean operator>>= (const CORBA::Any &, const IOP::ServiceContextList *&);

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::TaggedProfile &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::TaggedProfile &);

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::IOR &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::IOR &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_IOR__tao_seq_TaggedProfile_profiles_H_
#define _TAO_CDR_OP_IOP_IOR__tao_seq_TaggedProfile_profiles_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::IOR::_tao_seq_TaggedProfile_profiles &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::IOR::_tao_seq_TaggedProfile_profiles &
  );

#endif /* _TAO_CDR_OP_IOP_IOR__tao_seq_TaggedProfile_profiles_H_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::TaggedComponent &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::TaggedComponent &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_MultipleComponentProfile_H_
#define _TAO_CDR_OP_IOP_MultipleComponentProfile_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::MultipleComponentProfile &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::MultipleComponentProfile &
  );

#endif /* _TAO_CDR_OP_IOP_MultipleComponentProfile_H_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_TaggedComponentList_H_
#define _TAO_CDR_OP_IOP_TaggedComponentList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentList &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_TaggedComponentSeq_H_
#define _TAO_CDR_OP_IOP_TaggedComponentSeq_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::TaggedComponentSeq &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::TaggedComponentSeq &
  );

#endif /* _TAO_CDR_OP_IOP_TaggedComponentSeq_H_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:53

TAO_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IOP::ServiceContext &);
TAO_Export CORBA::Boolean operator>> (TAO_InputCDR &, IOP::ServiceContext &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_ServiceContext__tao_seq_Octet_context_data_H_
#define _TAO_CDR_OP_IOP_ServiceContext__tao_seq_Octet_context_data_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContext::_tao_seq_Octet_context_data &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::ServiceContext::_tao_seq_Octet_context_data &
  );

#endif /* _TAO_CDR_OP_IOP_ServiceContext__tao_seq_Octet_context_data_H_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:70

#if !defined _TAO_CDR_OP_IOP_ServiceContextList_H_
#define _TAO_CDR_OP_IOP_ServiceContextList_H_

TAO_Export CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const IOP::ServiceContextList &
  );
TAO_Export CORBA::Boolean operator>> (
    TAO_InputCDR &,
    IOP::ServiceContextList &
  );

#endif /* _TAO_CDR_OP_IOP_ServiceContextList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "IOP_IORC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

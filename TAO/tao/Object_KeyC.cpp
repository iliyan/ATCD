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
// be/be_codegen.cpp:314


#include "Object_KeyC.h"
#include "tao/ORB_Core.h"


#if defined (__BORLANDC__)
#pragma option -w-rvl -w-rch -w-ccc -w-aus -w-sig
#endif /* __BORLANDC__ */

#include "ace/ACE.h"

#if !defined (__ACE_INLINE__)
#include "Object_KeyC.i"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_cs.cpp:56

TAO::ObjectKey::ObjectKey (void)
{}

TAO::ObjectKey::ObjectKey (CORBA::ULong max)
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

TAO::ObjectKey::ObjectKey (
    CORBA::ULong max,
    CORBA::ULong length,
    CORBA::Octet* buffer,
    CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max, length, buffer, release)
{}

TAO::ObjectKey::ObjectKey (const ObjectKey &seq)
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

TAO::ObjectKey::~ObjectKey (void)
{}

void TAO::ObjectKey::_tao_any_destructor (void *_tao_void_pointer)
{
  ObjectKey *tmp = ACE_static_cast (ObjectKey*, _tao_void_pointer);
  delete tmp;
}

void
TAO::ObjectKey::encode_sequence_to_string (char * &str,
                                           const TAO_Unbounded_Sequence<CORBA::Octet> &seq)
{
  // We must allocate a buffer which is (gag) 3 times the length
  // of the sequence, which is the length required in the worst-case
  // scenario of all non-printable characters.
  //
  // There are two strategies here...we could allocate all that space here,
  // fill it up, then copy-allocate new space of just the right length.
  // OR, we could just return this space.  The classic time-space tradeoff,
  // and for now we'll let time win out, which means that we only do the
  // allocation once.
  u_int len = 3 * seq.length (); /* space for zero termination not needed */;
  str = CORBA::string_alloc (len);

  char *cp = str;

  for (u_int i = 0;
       cp < (cp + len) && i < seq.length();
       ++i)
    {
      // Some platforms define 'byte' as a macro, solve the problem
      // here.
#undef byte
      u_char byte = seq[i];
      if (is_legal (byte))
        {
          *cp++ = (char) byte;
          continue;
        }

      *cp++ = '%';
      *cp++ = ACE::nibble2hex ((byte >> 4) & 0x0f);
      *cp++ = ACE::nibble2hex (byte & 0x0f);
    }
  // Zero terminate
  *cp = '\0';
}

int TAO::ObjectKey::is_legal (u_char & c)
{
  if (isalnum(c))
  {
    return 1;
  }
  else
  {
    return ( c == ';' || c == '/' ||c == ':' || c == '?' ||
             c == '@' || c == '&' ||c == '=' || c == '+' ||
             c == '$' || c == ',' ||c == '_' || c == '.' ||
             c == '!' || c == '~' ||c == '*' || c == '\'' ||
             c == '-' || c == '(' || c == ')' );
  }
}

void
TAO::ObjectKey::decode_string_to_sequence (TAO_Unbounded_Sequence<CORBA::Octet> &seq,
                                           const char *str)
{
  if (str == 0)
    {
      seq.length (0);
      return;
    }

  u_int length = ACE_OS::strlen (str);
  const char *eos = str + length;
  const char *cp = str;

  // Set the length of the sequence to be as long as
  // we'll possibly need...we'll reset it to the actual
  // length later.
  seq.length (length);

  u_int i = 0;
  for (;
       cp < eos && i < seq.length ();
       i++)
    {
      if (*cp == '%')
        {
          // This is an escaped non-printable,
          // so we decode the hex values into
          // the sequence's octet
          seq[i] = (u_char) (ACE::hex2byte (cp[1]) << 4);
          seq[i] |= (u_char) ACE::hex2byte (cp[2]);
          cp += 3;
        }
      else
        // Copy it in
        seq[i] = *cp++;
    }

  // Set the length appropriately
  seq.length (i);
}


#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

template class
  TAO_FixedSeq_Var_T<
      TAO::ObjectKey,
      CORBA::Octet
    >;

template class TAO_Seq_Var_Base_T<TAO::ObjectKey,
                                  CORBA::Octet>;

template class
  TAO_Seq_Out_T<
      TAO::ObjectKey,
      TAO::ObjectKey_var,
      CORBA::Octet
    >;

#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

# pragma instantiate \
  TAO_FixedSeq_Var_T< \
      TAO::ObjectKey, \
      CORBA::Octet \
    >

# pragma instantiate \
  TAO_Seq_Out_T< \
      TAO::ObjectKey, \
      TAO::ObjectKey_var, \
      CORBA::Octet \
    >

#pragma instantiate TAO_Seq_Var_Base_T<TAO::ObjectKey,
                                       CORBA::Octet>;

#endif /* !ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_typecode/typecode_defn.cpp:284

static const CORBA::Long _oc_TAO_ObjectKey[] =
{
    TAO_ENCAP_BYTE_ORDER, // byte order
  22,
  ACE_NTOHL (0x49444c3a),
  ACE_NTOHL (0x54414f2f),
  ACE_NTOHL (0x4f626a65),
  ACE_NTOHL (0x63744b65),
  ACE_NTOHL (0x793a312e),
  ACE_NTOHL (0x30000000),  // repository ID = IDL:TAO/ObjectKey:1.0
    10,
  ACE_NTOHL (0x4f626a65),
  ACE_NTOHL (0x63744b65),
  ACE_NTOHL (0x79000000),  // name = ObjectKey
    CORBA::tk_sequence, // typecode kind
  12, // encapsulation length
    TAO_ENCAP_BYTE_ORDER, // byte order
    CORBA::tk_octet,

    0U,

};

static CORBA::TypeCode _tc_TAO_tc_TAO_ObjectKey (
    CORBA::tk_alias,
    sizeof (_oc_TAO_ObjectKey),
    (char *) &_oc_TAO_ObjectKey,
    0,
    sizeof (TAO::ObjectKey)
  );

TAO_NAMESPACE_TYPE (CORBA::TypeCode_ptr)
TAO_NAMESPACE_BEGIN (TAO)
TAO_NAMESPACE_DEFINE (
    ::CORBA::TypeCode_ptr,
    _tc_ObjectKey,
    &_tc_TAO_tc_TAO_ObjectKey
  )
TAO_NAMESPACE_END

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_cs.cpp:54

// Copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    const TAO::ObjectKey &_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::ObjectKey>::insert_copy (
      _tao_any,
      TAO::ObjectKey::_tao_any_destructor,
      TAO::_tc_ObjectKey,
      _tao_elem
    );
}

// Non-copying insertion.
void operator<<= (
    CORBA::Any &_tao_any,
    TAO::ObjectKey *_tao_elem
  )
{
  TAO::Any_Dual_Impl_T<TAO::ObjectKey>::insert (
      _tao_any,
      TAO::ObjectKey::_tao_any_destructor,
      TAO::_tc_ObjectKey,
      _tao_elem
    );
}

// Extraction to non-const pointer (deprecated).
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    TAO::ObjectKey *&_tao_elem
  )
{
  return _tao_any >>= ACE_const_cast (
      const TAO::ObjectKey *&,
      _tao_elem
    );
}

// Extraction to const pointer.
CORBA::Boolean operator>>= (
    const CORBA::Any &_tao_any,
    const TAO::ObjectKey *&_tao_elem
  )
{
  return
    TAO::Any_Dual_Impl_T<TAO::ObjectKey>::extract (
        _tao_any,
        TAO::ObjectKey::_tao_any_destructor,
        TAO::_tc_ObjectKey,
        _tao_elem
      );
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)  || \
    defined (ACE_HAS_GNU_REPO)
  template class TAO::Any_Dual_Impl_T<TAO::ObjectKey>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
# pragma instantiate TAO::Any_Dual_Impl_T<TAO::ObjectKey>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_cs.cpp:98

CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TAO::ObjectKey &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len = _tao_sequence.length ();

  if (strm << _tao_seq_len)
    {
      // Encode all elements.

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
          ACE_static_cast (TAO_Unbounded_Sequence<CORBA::Octet>*, (TAO::ObjectKey *)&_tao_sequence);
        if (oseq->mb ())
          return strm.write_octet_array_mb (oseq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }

#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }

  return 0;
}

CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TAO::ObjectKey &_tao_sequence
  )
{
  CORBA::ULong _tao_seq_len;

  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return 0;
        }

      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);

      // If length is 0 we return true.
      if (0 >= _tao_seq_len)
        {
          return 1;
        }

      // Retrieve all the elements.

#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      if (ACE_BIT_DISABLED (strm.start ()->flags (),
      ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();
        if (orb_core != 0 &&
        strm.orb_core ()->resource_factory ()->
        input_cdr_allocator_type_locked () == 1)
        {
          TAO_Unbounded_Sequence<CORBA::Octet> *oseq =
            ACE_static_cast(TAO_Unbounded_Sequence<CORBA::Octet>*, &_tao_sequence);
          oseq->replace (_tao_seq_len, strm.start ());
          oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
          strm.skip_bytes (_tao_seq_len);
          return 1;
        }
      }
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());

#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }

  return 0;
}

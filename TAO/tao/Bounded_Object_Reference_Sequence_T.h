#ifndef guard_bounded_object_reference_sequence_hpp
#define guard_bounded_object_reference_sequence_hpp
/**
 * @file
 *
 * @brief Implement bounded sequences for object references.
 *
 * @author Carlos O'Ryan
 */
#include "Bounded_Reference_Allocation_Traits_T.h"
#include "Object_Reference_Traits_T.h"
#include "Generic_Sequence_T.h"
#include "Object_Reference_Sequence_Element_T.h"
#include "Object_Reference_Const_Sequence_Element_T.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace TAO
{
template<typename object_t, typename object_t_var, CORBA::ULong MAX>
class bounded_object_reference_sequence
{
public:
  typedef object_t object_type;
  typedef object_type * value_type;
  typedef value_type const const_value_type;
  typedef object_t_var object_type_var;
  typedef ::CORBA::ULong size_type;

  typedef details::object_reference_traits<object_type,object_type_var,true> element_traits;
  typedef details::bounded_reference_allocation_traits<value_type,element_traits,MAX,true> allocation_traits;

  typedef details::object_reference_sequence_element<element_traits> element_type;
  typedef details::object_reference_const_sequence_element<element_traits> const_element_type;
  typedef element_type subscript_type;
  typedef value_type const & const_subscript_type;

  typedef details::generic_sequence<value_type, allocation_traits, element_traits> implementation_type;

  inline bounded_object_reference_sequence()
    : impl_()
  {}
  inline bounded_object_reference_sequence(
      CORBA::ULong length,
      value_type * data,
      CORBA::Boolean release)
    : impl_(MAX, length, data, release)
  {}

  /* Use default ctor, operator= and dtor */
  // @copydoc TAO::details::generic_sequence::maximum()
  inline CORBA::ULong maximum() const {
    return impl_.maximum();
  }
  // @copydoc TAO::details::generic_sequence::release()
  inline CORBA::Boolean release() const {
    return impl_.release();
  }
  // @copydoc TAO::details::generic_sequence::length()
  inline CORBA::ULong length() const {
    return impl_.length();
  }

  // @copydoc TAO::details::generic_sequence::length()
  inline void length(CORBA::ULong length) {
    implementation_type::range::check_length(length, MAX);
    impl_.length(length);
  }
  // @copydoc TAO::details::generic_sequence::operator[]
  inline const_element_type operator[](CORBA::ULong i) const {
    return const_element_type (impl_[i], release());
  }
  // @copydoc TAO::details::generic_sequence::operator[]
  inline element_type operator[](CORBA::ULong i) {
    return element_type(impl_[i], release());
  }
  // @copydoc TAO::details::generic_sequence::get_buffer()
  inline value_type const * get_buffer() const {
    return impl_.get_buffer();
  }
  // @copydoc TAO::details::generic_sequence::replace()
  inline void replace(
      CORBA::ULong length,
      value_type * data,
      CORBA::Boolean release = false) {
    impl_.replace(MAX, length, data, release);
  }
  // @copydoc TAO::details::generic_sequence::get_buffer(CORBA::Boolean)
  inline value_type * get_buffer(CORBA::Boolean orphan = false) {
    return impl_.get_buffer(orphan);
  }
  // @copydoc TAO::details::generic_sequence::swap
  inline void swap(bounded_object_reference_sequence & rhs) throw() {
    impl_.swap(rhs.impl_);
  }

  static value_type * allocbuf(CORBA::ULong maximum)
  {
    return implementation_type::allocbuf(maximum);
  }
  static value_type * allocbuf()
  {
    return implementation_type::allocbuf(MAX);
  }
  static void freebuf(value_type * buffer)
  {
    implementation_type::freebuf(buffer);
  }

private:
  implementation_type impl_;
};
} // namespace TAO

TAO_END_VERSIONED_NAMESPACE_DECL

#endif // guard_bounded_object_reference_sequence_hpp

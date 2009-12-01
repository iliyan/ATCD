// -*- C++ -*-
// $Id$

#ifndef DDS4CCM_STATELISTENERCONTROLI_H_
#define DDS4CCM_STATELISTENERCONTROLI_H_

#include "dds4ccm/impl/ndds/dds4ccm_ndds_impl_export.h"
#include "dds4ccm/idl/dds4ccm_StateListenerControlEC.h"
#include "tao/LocalObject.h"
#include "ace/Copy_Disabled.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class DDS4CCM_NDDS_IMPL_Export CCM_DDS_StateListenerControl_i
  : public virtual CCM_DDS::CCM_StateListenerControl,
    public virtual ::CORBA::LocalObject,
    private ACE_Copy_Disabled
{
public:
  /// Constructor
  CCM_DDS_StateListenerControl_i (
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::ListenerMode> &mode,
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::DataNumber_t> &max_delivered_data,
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CORBA::Boolean> &is_filter_interpreted);

  /// Destructor
  virtual ~CCM_DDS_StateListenerControl_i (void);

  /// Set the mode
  virtual ::CCM_DDS::ListenerMode mode (void);

  /// Get the mode
  virtual void mode (::CCM_DDS::ListenerMode mode);

  /// Set the max_delivered_data
  virtual ::CCM_DDS::DataNumber_t max_delivered_data (void);

  /// Get the max_delivered_data
  virtual void max_delivered_data (::CCM_DDS::DataNumber_t max_delivered_data);

  /// Set the is_filter_interpreted
  virtual ::CORBA::Boolean is_filter_interpreted (void);

  /// Get the is_filter_interpreted
  virtual void is_filter_interpreted (::CORBA::Boolean is_filter_interpreted);

private:
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::ListenerMode> &mode_;
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CCM_DDS::DataNumber_t> &max_delivered_data_;
  ACE_Atomic_Op <TAO_SYNCH_MUTEX, ::CORBA::Boolean> &is_filter_interpreted_;

};


#endif /* DDS4CCM_STATELISTENERCONTROLI_H_  */


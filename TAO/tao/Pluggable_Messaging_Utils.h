// -*- C++ -*-
// $Id$

// ============================================================================
//
// = LIBRARY
//     TAO
//
// = FILENAME
//     Pluggable_Messaging_Utils.h
//
// = DESCRIPTION
//     Utility classes for the TAO pluggable messaging framework.
//
// = AUTHOR
//     Balachandran Natarajan <bala@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_PLUGGABLE_MESSAGING_UTILS_H
#define TAO_PLUGGABLE_MESSAGING_UTILS_H
#include "ace/pre.h"

#include "tao/IOPC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CDR.h"

class TAO_Export TAO_Pluggable_Reply_Params
{
  // = TITLE
  //   TAO_Pluggable_Connector_Params
  //
  // = DESCRIPTION
  //   This represents a set of data that would be received by the
  //   connector from the acceptor.
public:
  TAO_Pluggable_Reply_Params (TAO_ORB_Core *orb_core);
  // Constructor.

  IOP::ServiceContextList svc_ctx_;
  // The IOP service context list.

  CORBA::ULong request_id_;
  // The request id for which the reply we (connector) has received.

  // @@ Bala: this is (again) an GIOPism (to coin a word).  Other
  // protocol may choose to send different *messages* instead.
  // @@ Carlos: I agree. Please see above.
  CORBA::ULong reply_status_;
  // The reply status.

  CORBA::Boolean is_dsi_;
  // Since this class no longer contains an NVList, this is the
  // way to determine if the request was DSI, so we can use Carlos'
  // service context list no-deep-copy optimization.

  ptr_arith_t dsi_nvlist_align_;
  // Info required for DSI optimization that pads the outgoing
  // CDR stream according to the alignment of the NVList.

  IOP::ServiceContextList &service_context_notowned (void);
  void service_context_notowned (IOP::ServiceContextList *svc);
  // Get and Set methods for the service context list that we dont
  // own. This is useful for cases  where the application objects own
  // a service context list and would like to pass on their contents
  // without a copy.

  CORBA::Boolean argument_flag_;
  // A flag that indicates if there is any data is going to get
  // marshalled in the reply

  TAO_InputCDR input_cdr_;
  // The stream with the non-demarshalled reply. This stream will be
  // passed up to the stubs to demarshall the parameter values.

private:
  IOP::ServiceContextList *service_context_;
  // The service context list that we don't own.
};

// @@ Bala: this is a GIOPism too, there is no such thing as locate
// request in HTTP (the basis for SOAP and XIOP), i don't know about
// HTTP-NG, but i wouldn't be surprised if it had.  Furthermore, some
// very influential people (Michi) is arguing against it in the OMG.
//
// @@Carlos: Yes, I also saw some of Michi's ideas. Even if OMG
// decides to remove this, can I point that we may have to support that
// for the existsing GIOP1.0,1.1 & GIOP 1.2.  Above all, the enum type
// contains things that I know of today. I can go ahead and add HTTP-NG
// stuff. They all seem to be in Working Draft stage. So, I am just
// keeping off. I dont want to add something for the kick of it :-)
enum TAO_Pluggable_Header_Type
{
  // = TITLE
  // = DESCRIPTION
  //
  TAO_PLUGGABLE_MESSAGE_REQUEST_HEADER = 0,
  TAO_PLUGGABLE_MESSAGE_LOCATE_REQUEST_HEADER
};


enum TAO_Pluggable_Message_Type
{
  // = DESCRIPTION
  //   Provide an external interface for the users of this pluggable
  //   messaging framework to denote  existing message types. This has
  //   an inspiration from GIOP. So if anybody wants to add more message
  //   types you are welcome but please do not change the numbering
  //   scheme as this would affect GIOP.

  //   NOTE: We may not need evrything here. It would be good if we
  //   have only the following messages TAO_PLUGGABLE_MESSAGE_REQUEST,
  //   TAO_PLUGGABLE_MESSAGE_REPLY,
  //   TAO_PLUGGABLE_MESSAGE_CLOSECONNECTION,
  //   TAO_PLUGGABLE_MESSAGE_MESSAGE_ERROR.  Changes will be made once
  //   the rest of the stuff gets ready to roll.
  TAO_PLUGGABLE_MESSAGE_REQUEST = 0,                // sent by client.
  TAO_PLUGGABLE_MESSAGE_REPLY = 1,                  // by server.
  TAO_PLUGGABLE_MESSAGE_CANCELREQUEST = 2,          // by client.
  TAO_PLUGGABLE_MESSAGE_LOCATEREQUEST = 3,          // by client.
  TAO_PLUGGABLE_MESSAGE_LOCATEREPLY = 4,
  TAO_PLUGGABLE_MESSAGE_CLOSECONNECTION = 5,
  TAO_PLUGGABLE_MESSAGE_MESSAGERROR = 6,
  TAO_PLUGGABLE_MESSAGE_FRAGMENT = 7
};

// @@ Bala: This is a hopeless GIOPism.
// @@ Carlos: Agreed.

enum TAO_Pluggable_Message_Exception_Type
{
  // = DESCRIPTION
  //   Provide an external interface for the users of this pluggable
  //   messaging framework to denote  existing Exception types. This has
  //   an inspiration from GIOP. So if anybody wants to add more message
  //   types you are welcome but please do not change the numbering
  //   scheme as this would affect GIOP.
  TAO_PLUGGABLE_MESSAGE_NO_EXCEPTION = 0,
  // Request completed successfully

  TAO_PLUGGABLE_MESSAGE_USER_EXCEPTION,
  // Request terminated with user exception

  TAO_PLUGGABLE_MESSAGE_SYSTEM_EXCEPTION,
  // Request terminated with system exception

  TAO_PLUGGABLE_MESSAGE_LOCATION_FORWARD,
  // Reply is a location forward type

  TAO_PLUGGABLE_MESSAGE_LOCATION_FORWARD_PERM,
  // PLUGGABLE_MESSAGE 1.2, Reply is a location forward perm type..

  TAO_PLUGGABLE_MESSAGE_NEEDS_ADDRESSING_MODE
  // GIOP1.2,
};

#if defined (__ACE_INLINE__)
#include "tao/Pluggable_Messaging_Utils.i"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_PLUGGABLE_MESSAGING_UTILS_H*/
